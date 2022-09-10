#include<stdio.h>
main(){
    int n,m,i;
    scanf("%d%d",&n,&m);
    m%=(n*(n+1)/2);
    for(i=1;i<=m;i++)m-=i;
    printf("%d\n",m);
}