#include<stdio.h>
int n,d[110];
main(){
    int i,a,b;
    scanf("%d",&n);
    for(i=2;i<=n;i++)scanf("%d",&d[i]);
    for(i=3;i<=n;i++)d[i]+=d[i-1];
    scanf("%d%d",&a,&b);
    printf("%d\n",d[b]-d[a]);
}