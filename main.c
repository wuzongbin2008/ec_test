#include <stdio.h>
#include <stdlib.h>

#include "jerasure/cauchy.h"
#include "jerasure/galois.h"
#include "jerasure/jerasure.h"
#include "jerasure/liberation.h"
#include "jerasure/reed_sol.h"

int main(int argc,char *argv[])
{
    int k=10,m=3,w=8,packetsize=1,buffersize=11,blocksize=11;
    char **data;
    char **coding;
    /* Vandermonde matrix */
    int matrix[3][10] =
    {
        {1,1,1,1,1,1	,1,1	,1,1	},
        {1,147,138,73,93	,161,103,58,99,178},
        {1,220,166,123,82,143,245,40,167,122}
    };//*matrix;
    int i;

    /* Allocate data and coding */
    data = (char **)malloc(sizeof(char*)*k);
    coding = (char **)malloc(sizeof(char*)*m);
    for (i = 0; i < m; i++)
    {
        coding[i] = (char *)malloc(sizeof(char)*blocksize);
    }
    /* Set pointers to point to file data */
    for (i = 0; i < k; i++)
    {
        data[i] = (char *)calloc(11,sizeof(char *));
        switch(i){
        case 0:
            data[i] = "abcdefghij";
            break;
        case 1:
            data[i] = "123456789k";
            break;
        }
    }

    jerasure_matrix_encode(k, m, w, matrix, data, coding, blocksize);

    return 0;
}
