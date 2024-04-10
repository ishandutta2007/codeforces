#include<stdio.h>
int used[4];
main(){
    int n,i,x,ma;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        used[x]++;
    }
    ma=0;
    for(i=1;i<=3;i++){
        if(used[i]>ma)ma=used[i];
    }
    printf("%d\n",n-ma);
}