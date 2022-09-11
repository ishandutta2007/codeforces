#include<stdio.h>
int d[7],e[7],an1,an2;
struct data{
    int l,h,a;
}Map[7][7];
void dfs(int x,int y,int r,int cost,int n){
    int i;
    if(x==n){
        if(an1>e[n]||(an1==e[n]&&an2<cost)){
            an1=e[n];
            an2=cost;
        }
        return;
    }
    if(y>n){
        if(r==0){
            dfs(x+1,x+2,e[x+1],cost,n);
        }
    }
    else{
        for(i=Map[x][y].l;i<=Map[x][y].h;i++){
            if(r<i)return;
            if(!i)dfs(x,y+1,r,cost,n);
            else{
                e[y]+=i;
                dfs(x,y+1,r-i,cost+Map[x][y].a+i*i,n);
                e[y]-=i;
            }
        }
    }
}
void Start(int x,int cost,int n){
    int i;
    if(x>n){
        for(i=1;i<=n;i++)e[i]=d[i];
        dfs(2,3,d[2],cost,n);
        return;
    }
    for(i=Map[1][x].l;i<=Map[1][x].h;i++){
        d[x]=i;
        if(i==0)Start(x+1,cost,n);
        else Start(x+1,cost+Map[1][x].a+i*i,n);
    }
}
main(){
    int n,m,s,f,l,h,a,i;
    an1=2147483647;
    scanf("%d",&n);
    m=n*(n-1)/2;
    for(i=0;i<m;i++){
        scanf("%d%d%d%d%d",&s,&f,&l,&h,&a);
        Map[s][f]=(data){l,h,a};
    }
    Start(2,0,n);
    if(an1==2147483647)puts("-1 -1");
    else printf("%d %d\n",an1,an2);
}