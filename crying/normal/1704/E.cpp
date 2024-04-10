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
const int MAXN=1010,mod=998244353;
ll T,n,m,a[MAXN],ed;
ll deg[MAXN];
vector<int>e[MAXN];
ll dp[MAXN][MAXN],vis[MAXN][MAXN],over[MAXN][MAXN];
ll t[MAXN],tag[MAXN];
int dfs(int u,int k){
    if(vis[u][k])return dp[u][k];
    vis[u][k]=1;
    if(u==ed){
        if(k==0)return dp[u][k]=1;
        else return dp[u][k]=0;
    }
    if(k==0)return dp[u][k]=0;
    for(auto v:e[u]){
        ll tmp=dfs(v,k-1);
        over[u][k]|=over[v][k-1];
        if(dp[u][k]+tmp>=mod)over[u][k]=1;
        dp[u][k]=(dp[u][k]+tmp)%mod;
    }
    return dp[u][k];
}
void solve(){
    cin>>n>>m;
    rep(i,1,n)cin>>a[i],e[i].clear(),deg[i]=0;
    rep(i,1,m){
        int u,v;cin>>u>>v;
        e[u].push_back(v);deg[u]++;
    }
    rep(i,1,n)if(!deg[i])ed=i;
    rep(i,0,n)rep(j,0,m)dp[i][j]=vis[i][j]=over[i][j]=0;
    rep(i,1,n)rep(j,0,m)dfs(i,j);
    memset(t,0,sizeof t);
    memset(tag,0,sizeof tag);
    rep(i,1,n)rep(j,0,m){
        if(!a[i])continue;
        if(!over[i][j] && !dp[i][j])continue;
        tag[j]|=(a[i]>=mod);
        tag[j]|=over[i][j];
        dp[i][j]%=mod;
        if((a[i]%mod)*dp[i][j]>=mod)tag[j]=1;
        ll v=(a[i]%mod)*dp[i][j]%mod;
        if(t[j]+v>=mod)tag[j]=1;
        t[j]=(t[j]+v)%mod;
    }
    ll T=0,presum=0,maxcur=0;
    rep(i,0,m){
        if(presum)presum--,maxcur=i;
        if(tag[i]){
            presum%=mod;
            ll res=(i+presum)%mod;
            rep(j,i,m)res=(res+t[j])%mod;
            cout<<res%mod<<'\n';
            return;
        }else if(t[i]) presum+=t[i],maxcur=i;
    }
    cout<<(maxcur+presum)%mod<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}