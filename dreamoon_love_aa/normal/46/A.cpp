#include<stdio.h>
main(){
    int n,now=1,i,j=1;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        now=(now+j-1)%n+1;
        j++;
        if(i!=1)putchar(' ');
        printf("%d",now);
    }
    puts("");
}