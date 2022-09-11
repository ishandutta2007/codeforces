#include<stdio.h>
main(){
    int n,i,j;
    scanf("%d",&n);
    printf("1");
    for(i=1,j=n;i<j;j--){
        printf(" %d",j);
        i++;
        if(i<j)printf(" %d",i);
    }
    puts("");
}