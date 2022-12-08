#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+10;
int n,pos,top;
int fir[maxn+1],nxt[maxn],gett[maxn],f[maxn];
int maxx[maxn],dep[maxn],id[maxn];
inline void add(int x,int y){
    gett[++top]=y; nxt[top]=fir[x]; fir[x]=top;
}
void dfs(int x,int fa){
    dep[x]=dep[fa]+1; f[x]=fa; id[x]=x;
    for (int i=fir[x];i;i=nxt[i]){
        int v=gett[i];
        if (v==fa) continue;
        dfs(v,x);
        if (maxx[v]>maxx[x]){
            maxx[x]=maxx[v]; id[x]=id[v];
        }
    }
    ++maxx[x];
}
int main(){
    scanf("%d%d",&n,&pos);
    for (int i=1,x,y;i<n;++i){
        scanf("%d%d",&x,&y);
        add(x,y); add(y,x);
    }
    dfs(1,0);
    int now=pos,tt=0,ans=0;
    while (now!=1){
        if (dep[1]+tt>=dep[now]) break;
        ans=max(ans,dep[id[now]]-1);
        now=f[now]; ++tt;
    }
    printf("%d",ans*2);
}