#include<stdio.h>
main(){
    int n,m,a,b;
    scanf("%d%d%d%d",&n,&m,&a,&b);
    if((a-1)%m==0&&(b-1)%m==m-1){
        puts("1");
    }
    else if((a-1)/m==(b-1)/m){
        puts("1");
    }
    else if((a-1)%m==0&&b==n){
        puts("1");
    }
    else if((a-1)%m-1==(b-1)%m){
        puts("2");
    }
    else if((a-1)/m+1==(b-1)/m){
        puts("2");
    }
    else if((a-1)%m==0){
        puts("2");
    }
    else if((b-1)%m==m-1){
        puts("2");
    }
    else if(b==n){
        puts("2");
    }
    else puts("3");
}