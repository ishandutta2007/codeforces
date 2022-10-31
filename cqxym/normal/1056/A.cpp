#include<stdio.h>
#define R register int
int v[101];
int main(){
    int n,m,x;
    scanf("%d",&n);
    for(R i=0;i!=n;i++){
        scanf("%d",&m);
        for(R j=0;j!=m;j++){
            scanf("%d",&x);
            v[x]++;
        }
    }
    for(R i=1;i!=101;i++){
        if(v[i]==n){
            printf("%d ",i);
        }
    }
    return 0;
}