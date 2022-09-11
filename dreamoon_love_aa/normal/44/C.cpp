#include<stdio.h>
int a[128];
main(){
    int n,m,x,y,i;
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d",&x,&y);
        do{
            a[x]++;
            x++;
        }while(x<=y);
    }
    for(i=1;i<=n;i++)
        if(a[i]!=1)break;
    if(i<=n)printf("%d %d\n",i,a[i]);
    else puts("OK");
}