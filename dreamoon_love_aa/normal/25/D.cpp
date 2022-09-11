#include<stdio.h>
#define SIZE 1024
int d[SIZE],e[1024];
bool f(int x,int y){
    while(x!=d[x])x=d[x];
    while(y!=d[y])y=d[y];
    if(x!=y){
        if(e[x]<e[y])d[x]=y;
        else if(e[y]<e[x])d[y]=x;
        else{
            d[x]=y;
            e[y]++;
        }
        return 1;
    }
    return 0;
}
struct data{
    int x,y;
}an[SIZE];
int g[SIZE],gn;
main(){
    int n,m,ann=0,i,x,y;
    scanf("%d",&n);
    m=n-1;
    for(i=1;i<=n;i++)d[i]=i;
    while(m--){
        scanf("%d%d",&x,&y);
        if(!f(x,y))an[ann++]=(data){x,y};
    }
    for(i=1;i<=n;i++)
        if(d[i]==i)g[gn++]=i;
    printf("%d\n",ann);
    for(i=0;i<ann;i++)
        printf("%d %d %d %d\n",an[i].x,an[i].y,g[i],g[i+1]);
}