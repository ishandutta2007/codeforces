#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define pb push_back
#define LL long long
using namespace std;
const int N=1e5+50;
int n,q,dfn[N],rr[N],cnt,f[N][20],d[N],a[N];LL bit[N];
vector<int>v[N];
void dfs(int x,int ff){
    dfn[x]=++cnt;
    f[x][0]=ff;d[x]=d[ff]+1;
    for(int i=0;i<18;i++)f[x][i+1]=f[f[x][i]][i];
    for(int i=0;i<v[x].size();i++){
        int y=v[x][i];
        if(y==ff)continue;
        dfs(y,x);
    }
    rr[x]=cnt;
}
int lca(int x,int y){
    if(d[x]<d[y])swap(x,y);
    for(int i=18;~i;i--)if(d[f[x][i]]>=d[y])x=f[x][i];
    if(x==y)return x;
    for(int i=18;~i;i--)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
    return f[x][0];
}
void add(int x,int y){for(;x<=n;x+=x&-x)bit[x]+=y;}
LL ask(int x){LL z=0;for(;x;x-=x&-x)z+=bit[x];return z;}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),a[i]=abs(a[i]);
    for(int i=1,x,y;i<n;i++){
        scanf("%d%d",&x,&y);
        v[x].pb(y);v[y].pb(x);
    }
    dfs(1,0);//puts("1");
    for(int i=1;i<=n;i++)add(dfn[i],a[i]),add(rr[i]+1,-a[i]);
    for(int i=1,op,x,y;i<=q;i++){
        scanf("%d%d%d",&op,&x,&y);
        if(op==1){
            add(dfn[x],-a[x]);add(rr[x]+1,a[x]);
            add(dfn[x],a[x]=abs(y));add(rr[x]+1,-a[x]);
        }
        else{
            int z=lca(x,y),zz=f[z][0];
            // cout<<x<<" "<<y<<" "<<z<<endl;
            printf("%lld\n",2*(ask(dfn[x])+ask(dfn[y])-ask(dfn[z])-ask(dfn[zz]))-a[x]-a[y]);
        }
    }
    return 0;
}