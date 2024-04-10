#include<stdio.h>
main(){
    int n,m,k,i;
    double an=1;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<=k;i++)an*=(double)(m-i)/(n+1+i);
    an=1-an;
    if(an<0)an=0;
    printf("%lf\n",an);
}