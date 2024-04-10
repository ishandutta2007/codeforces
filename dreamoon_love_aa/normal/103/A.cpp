#include<stdio.h>
long long an;
main(){
    int i,x,n;
    long long sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        an+=(sum+1)*(x-1)+1;
        sum++;
    }
    printf("%I64d\n",an);
}