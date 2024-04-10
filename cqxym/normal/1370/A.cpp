#include<stdio.h>
int main(){
    int t,x;
    scanf("%d",&t);
    for(register int i=0;i!=t;i++){
        scanf("%d",&x);
        printf("%d\n",x>>1);
    }
    return 0;
}