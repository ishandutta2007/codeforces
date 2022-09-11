#include<stdio.h>
main(){
    int n,i;
    scanf("%d",&n);
    if(n==1){
        printf("a\na\nb\nb\n");
    }
    else if(n&1){
        for(i=0;i+1<n;i+=2){
            if(i%4==0)printf("aa");
            else printf("bb");
        }
        puts("c");
        for(i=0;i+1<n;i+=2){
            if(i%4==0)printf("dd");
            else printf("ee");
        }
        puts("c");
        printf("z");
        for(i=0;i+1<n;i+=2){
            if(i%4==0)printf("ff");
            else printf("gg");
        }
        printf("\nz");
        for(i=0;i+1<n;i+=2){
            if(i%4==0)printf("hh");
            else printf("ii");
        }
        puts("");
    }
    else{
        for(i=0;i+1<n;i+=2){
            if(i%4==0)printf("aa");
            else printf("bb");
        }
        puts("");
        printf("z");
        for(i=0;i+2<n;i+=2){
            if(i%4==0)printf("ee");
            else printf("ff");
        }
        puts("y");
        printf("z");
        for(i=0;i+2<n;i+=2){
            if(i%4==0)printf("gg");
            else printf("hh");
        }
        puts("y");
        for(i=0;i+1<n;i+=2){
            if(i%4==0)printf("cc");
            else printf("dd");
        }
        puts("");
    }
}