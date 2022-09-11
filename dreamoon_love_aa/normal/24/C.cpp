#include<stdio.h>
#define SIZE 100010
int x[SIZE],y[SIZE];
main(){
    int n,anx,any,i;
    long long j;
    scanf("%d%I64d",&n,&j);
    scanf("%d%d",&anx,&any);
    for(i=0;i<n;i++)scanf("%d%d",&x[i],&y[i]);
    if((j/n)&1){
        for(i=0;i<n;i++){
            anx=x[i]*2-anx;
            any=y[i]*2-any;
        }
    }
    for(i=0;i<j%n;i++){
        anx=x[i]*2-anx;
        any=y[i]*2-any;
    }
    printf("%d %d\n",anx,any);
}