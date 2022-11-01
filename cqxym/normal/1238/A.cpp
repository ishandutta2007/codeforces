#include<stdio.h>
int main(){
    int t;
    long long x,y;
    scanf("%d",&t);
    for(register int i=0;i<t;i++){
        scanf("%lld%lld",&x,&y);
        if(x-y>1){
            puts("YES");
        }else{
            puts("NO");
        }
    }
    return 0;
}