#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=2e5+10,INF=1e9;
int T,n,ans,f[MAXN],g[MAXN];
vector<int>e[MAXN];
void dfs1(int u,int fa){
    f[u]=0;int cnt=0;
    for(auto v:e[u])if(v!=fa){
        dfs1(v,u);
        f[u]+=f[v];
        if(!f[v])cnt++;
    }
    f[u]+=max(cnt-1,0);
    g[u]=cnt;
}
void dfs2(int u,int fa){
    ans=min(ans,f[u]+1);
    for(auto v:e[u])if(v!=fa){
        int tag=0;if(!f[v])tag=1;
        f[u]-=max(g[u]-1,0);f[u]-=f[v];g[u]-=tag;f[u]+=max(g[u]-1,0);
        int tag2=0;if(!f[u])tag2=1;
        f[v]-=max(g[v]-1,0);f[v]+=f[u];g[v]+=tag2;f[v]+=max(g[v]-1,0);
        dfs2(v,u);
        f[v]-=max(g[v]-1,0);g[v]-=tag2;f[v]+=max(g[v]-1,0);f[v]-=f[u];
        f[u]-=max(g[u]-1,0);g[u]+=tag;f[u]+=max(g[u]-1,0);f[u]+=f[v];
    }
}
void solve(){
    cin>>n;
    rep(i,1,n)e[i].clear();
    rep(i,1,n-1){
        int u,v;cin>>u>>v;
        e[u].push_back(v);e[v].push_back(u);
    }
    if(n==1){
        cout<<"0\n";return;
    }
    ans=INF;
    dfs1(1,0);
    dfs2(1,0);
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();


    return 0;
}