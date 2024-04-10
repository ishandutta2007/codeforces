#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+10;
int a[maxn],fir[maxn],nxt[maxn],gett[maxn];
int n,top,cnt;
int a1[maxn],b1[maxn];
int fa[maxn],rt,maxx;
int dis[maxn],ans;
inline void add(int x,int y){
    gett[++top]=y; nxt[top]=fir[x]; fir[x]=top;
}
int ask(int x){
    if (x==fa[x]) return x; else return fa[x]=ask(fa[x]);
}
void dfs(int x,int fa){
    for (int i=fir[x];i;i=nxt[i]){
        int v=gett[i];
        if (v==fa) continue;
        dis[v]=dis[x]+1;
        if (dis[v]>maxx){
            maxx=dis[v]; rt=v;
        }
        dfs(v,x);
    }
}
int main(){
    scanf("%d",&n);
int kkk;
    for (int i=1;i<=n;++i) scanf("%d",&a[i]);
    for (int i=1;i<=n;++i) fa[i]=i;
    for (int i=1,x,y;i<n;++i){
        scanf("%d%d",&a1[i],&b1[i]);
        x=ask(a1[i]),y=ask(b1[i]);
        if (a[a1[i]]==a[b1[i]]) fa[x]=y;
    }
    rt=ask(1);
    for (int i=1,x,y;i<=n;++i){
        x=ask(a1[i]),y=ask(b1[i]);
        if (x!=y){
            add(x,y); add(y,x);
        }
    }
    dis[rt]=0; maxx=0;
    dfs(rt,0);
    dis[rt]=0;
    dfs(rt,0);
    printf("%d\n",(maxx+1)/2);
}