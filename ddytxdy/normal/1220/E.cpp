#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+50;
int n,m,a[N],ver[N*2],nxt[N*2],head[N],tot,s,dfn[N],low[N],cnt,st[N],tp,shu[N],dcc,sz[N];
int ver1[N*2],nxt1[N*2],head1[N],tot1;LL b[N],f[N],sum,mx;bool flag[N];
void add(int x,int y){ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;}
void add1(int x,int y){ver1[++tot1]=y;nxt1[tot1]=head1[x];head1[x]=tot1;}
void dfs(int x,int ff){
    low[x]=dfn[x]=++cnt;st[++tp]=x;
    for(int i=head[x],y;i;i=nxt[i]){
        if(!dfn[y=ver[i]])dfs(y,x),low[x]=min(low[x],low[y]);
        else if(y!=ff)low[x]=min(low[x],dfn[y]);
    }
    if(low[x]==dfn[x]){int z;dcc++;do z=st[tp--],shu[z]=dcc,sz[dcc]++;while(z!=x);}
}
void dfs1(int x,int ff){
    for(int i=head1[x],y;i;i=nxt1[i])if((y=ver1[i])!=ff)
        dfs1(y,x),f[x]=max(f[x],f[y]),flag[x]|=flag[y];
    if(sz[x]!=1)flag[x]=1;f[x]+=b[x];
    if(!flag[x])mx=max(mx,f[x]);
    else sum+=b[x];
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1,x,y;i<=m;i++){
        scanf("%d%d",&x,&y);
        add(x,y);add(y,x);
    }
    scanf("%d",&s);dfs(s,0);
    for(int i=1;i<=n;i++)if(dfn[i]){
        b[shu[i]]+=a[i];
        for(int j=head[i],y;j;j=nxt[j])
            if(dfn[y=ver[j]]&&shu[y]!=shu[i])add1(shu[i],shu[y]);
    }
    dfs1(shu[s],0);cout<<sum+mx;
    return 0;
}