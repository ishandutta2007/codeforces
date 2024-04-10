#include<stdio.h>
int used[1024],d[1024];
int b[1024];
main(){
    int n,k,i,j;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)scanf("%d",&b[i]);
    for(i=1;i<=n;i++){
        if(i!=1)putchar(' ');
        for(j=1;j<=n;j++){
            if(used[j])continue;
            if(b[j]<=d[j]){
                printf("%d",j);
                used[j]=1;
                for(j=j-k;j>0;j--)d[j]++;
                break;
            }
        }
    }
    puts("");
}