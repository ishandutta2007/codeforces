#include <stdio.h>
int main()
{
    int a,b,c,d,e,k,tol=0;
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    for(k=1;k<=e;k++)
        if(k%a==0 || k%b==0 || k%c==0 || k%d==0) tol++;
    printf("%d",tol);
    return 0;
}