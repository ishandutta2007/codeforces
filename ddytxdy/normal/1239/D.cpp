#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50;
int t,n,m,ver[N],nxt[N],head[N],tot,dfn[N],low[N],st[N],cnt,tp,bel[N],scc,sz[N];
void add(int y,int x){if(x!=y)ver[++tot]=y,nxt[tot]=head[x],head[x]=tot;}
void init(){
    memset(head+1,0,4*n);
    memset(dfn+1,0,4*n);
    memset(sz+1,0,4*scc);
    memset(bel+1,0,4*n);
    tot=cnt=scc=0;
}
int read(){
    int x=0;char c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+(c^48),c=getchar();
    return x;
}
void dfs(int x){
    dfn[x]=low[x]=++cnt;st[++tp]=x;
    for(int i=head[x],y;i;i=nxt[i])
        if(!dfn[y=ver[i]])dfs(y),low[x]=min(low[x],low[y]);
        else if(!bel[y])low[x]=min(low[x],dfn[y]);
    if(low[x]==dfn[x]){
        int y;scc++;
        do sz[bel[y=st[tp--]]=scc]++;while(y!=x);
    }
}
int main(){
    scanf("%d",&t);
    while(t--){
        init();
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)add(read(),read());
        for(int i=1;i<=n;i++)if(!dfn[i])dfs(i);
        if(scc<2)puts("No");
        else{
            puts("Yes");printf("%d %d\n",sz[1],n-sz[1]);
            for(int i=1;i<=n;i++)if(bel[i]==1)printf("%d ",i);puts("");
            for(int i=1;i<=n;i++)if(bel[i]!=1)printf("%d ",i);puts("");
        }
    }
    return 0;
}