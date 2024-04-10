#include<stdio.h>
int a[111],d[111];
main(){
    int n,m,k,x,i,mi=10000;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=m;i++)scanf("%d",&a[i]);
    while(k--){
        scanf("%d",&x);
        for(i=1;i<=m;i++)
            if(x%a[i]==0)d[i]++;
    }
    for(i=1;i<=m;i++)
        if(d[i]<mi)mi=d[i];
    for(x=0,i=1;i<=m;i++)
        if(d[i]==mi)x++;
    printf("%d\n",x);
    x=0;
    for(i=1;i<=m;i++){
        if(d[i]==mi){
            if(x)printf(" ");
            else x++;
            printf("%d",i);
        }
    }
    puts("");
}