#include<stdio.h>
int res[128];
main(){
    int n,now=1,an=0,i,x;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&x);
        if(x==now){
            now++;
            res[an++]=i+2000;
        }
    }
    printf("%d\n",an);
    if(an){
        for(i=0;i<an;i++){
            if(i)putchar(' ');
            printf("%d",res[i]);
        }
        puts("");
    }
}