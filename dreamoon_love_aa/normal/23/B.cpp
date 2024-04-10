#include<stdio.h>
main(){
    int n,x;
    scanf("%d\n",&n);
    while(n--){
        scanf("%d",&x);
        if(x>2)printf("%d\n",x-2);
        else puts("0");
    }
}