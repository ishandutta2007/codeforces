#include<stdio.h>

#define ABS(X) ((X)>0?(X):(-(X)))
#define MAX(A,B) ((A)>(B)?(A):(B))

int r1,c1,r2,c2;
char strt[10],end[10];

int main()
{
    scanf("%s%s",strt,end);

    c1 = strt[0]-'a';
    r1 = strt[1]-'1';

    c2 = end[0]-'a';
    r2 = end[1]-'1';

    printf("%d\n",MAX(ABS(c1-c2),ABS(r2-r1)));

    for(;r1>r2 && c1>c2;)
    {
        r1--;       c1--;
        printf("LD\n");
    }

    for(;r1<r2 && c1<c2;)
    {
        r1++;       c1++;
        printf("RU\n");
    }

    for(;r1>r2 && c1<c2;)
    {
        r1--;       c1++;
        printf("RD\n");
    }

    for(;r1<r2 && c1>c2;)
    {
        r1++;       c1--;
        printf("LU\n");
    }

    for(;r1<r2;)
    {
        r1++;
        printf("U\n");
    }

    for(;r1>r2;)
    {
        r1--;
        printf("D\n");
    }

    for(;c1<c2;)
    {
        c1++;
        printf("R\n");
    }

    for(;c1>c2;)
    {
        c1--;
        printf("L\n");
    }

    return 0;
}