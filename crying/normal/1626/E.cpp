#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=3e5+10;
int n,c[MAXN],ans[MAXN];
vector<int>e[MAXN];
int fa[MAXN],f[MAXN],sf[MAXN],g[MAXN],sg[MAXN];
int pre1[MAXN],pre2[MAXN],suf1[MAXN],suf2[MAXN];
void dfs1(int u){
    if(c[u] || c[fa[u]])ans[u]=1;
    sf[u]=sg[u]=c[u];
    for(auto v:e[u])if(v!=fa[u]){
        fa[v]=u;dfs1(v);
        sf[u]+=sf[v];
        if(c[v])ans[u]=1;
        if(sf[v]>=2 && f[v])ans[u]=1;
    }
    f[u]=ans[u];
}
void dfs2(int u){
    int cnt=0;
    ans[u]|=g[u];
    for(auto v:e[u])if(v!=fa[u]){
        cnt++;
        pre1[cnt]=pre1[cnt-1]|(f[v]&&sf[v]>=2)|(c[v]);
        pre2[cnt]=pre2[cnt-1]+sf[v];
    }
    suf1[cnt+1]=suf2[cnt+1]=0;
    reverse(e[u].begin(),e[u].end());
    for(auto v:e[u])if(v!=fa[u]){
        suf1[cnt]=suf1[cnt+1]|(f[v]&&sf[v]>=2)|(c[v]);
        suf2[cnt]=suf2[cnt+1]+sf[v];
        cnt--;
    }
    reverse(e[u].begin(),e[u].end());
    for(auto v:e[u])if(v!=fa[u]){
        cnt++;
        g[v]|=((g[u]|pre1[cnt-1]|suf1[cnt+1])&(sg[u]+pre2[cnt-1]+suf2[cnt+1]>=2));
        g[v]|=c[u];
        sg[v]+=(sg[u]+pre2[cnt-1]+suf2[cnt+1]);
    }
    for(auto v:e[u])if(v!=fa[u])dfs2(v);
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;rep(i,1,n)cin>>c[i];
    rep(i,1,n-1){
        int u,v;cin>>u>>v;
        e[u].pb(v);e[v].pb(u);
    }
    dfs1(1);
    dfs2(1);
    rep(i,1,n)printf("%d ",ans[i]);
    return 0;
}