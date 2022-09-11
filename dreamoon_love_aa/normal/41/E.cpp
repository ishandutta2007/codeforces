#include<stdio.h>
main(){
    int n,i,j;
    scanf("%d",&n);
    printf("%d\n",(n/2)*((n+1)/2));
    for(i=1;i<=n/2;i++)
        for(j=n/2+1;j<=n;j++)
            printf("%d %d\n",i,j);
}