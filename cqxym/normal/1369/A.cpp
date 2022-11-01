#include<stdio.h>
int main(){
    int t,n;
    scanf("%d",&t);
    for(register int i=0;i!=t;i++){
        scanf("%d",&n);
        if((n&3)!=0){
            puts("No");
        }else{
            puts("Yes");
        }
    }
    return 0;
}