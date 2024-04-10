#include<stdio.h>
main(){
    int n,i;
    scanf("%d",&n);
    if(n&1){
        printf("1");
        for(i=2;i<=n;i++){
            if(i&1)printf(" %d",i-1);
            else printf(" %d",i+1);
        }
    }
    else{
        printf("2");
        for(i=2;i<=n;i++){
            if(i&1)printf(" %d",i+1);
            else printf(" %d",i-1);
        }
    }
    puts("");
}