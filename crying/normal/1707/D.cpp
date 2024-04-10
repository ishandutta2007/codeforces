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
const int MAXN=2010;
int mod;
int n;
vector<int>e[MAXN];
int F[MAXN],G[MAXN];
int C[MAXN][MAXN];
int dp[MAXN][MAXN],sum[MAXN][MAXN];
ll premult[MAXN][MAXN],sufmult[MAXN][MAXN],pre[MAXN];
int f(int x){return F[x+1];}
int g(int x){
    int res=0;
    rep(i,0,n)if(even((x-i))){
        res=(res+1ll*C[x][i]*f(i)%mod)%mod;
    }else{
        res=(res-1ll*C[x][i]*f(i)%mod+mod)%mod;
    }
    return res;
}
void dfs(int u,int fa){
    for(auto v:e[u])if(v!=fa){
        dfs(v,u);
    }
    int sz=e[u].size();
    rep(i,1,n)premult[0][i]=sufmult[sz+1][i]=1;
    rep(i,0,sz-1){
        int v=e[u][i];if(v==fa){
            rep(j,1,n)premult[i+1][j]=premult[i][j];
            continue;
        }
        rep(j,1,n)premult[i+1][j]=premult[i][j]*sum[v][j]%mod;
    }
    per(i,sz-1,0){
        int v=e[u][i];if(v==fa){
            rep(j,1,n)sufmult[i+1][j]=sufmult[i+2][j];
            continue;
        }
        rep(j,1,n)sufmult[i+1][j]=sufmult[i+2][j]*sum[v][j]%mod;
    }
    if(u==1)rep(i,1,n)F[i]=premult[sz][i];
    memset(dp[u],0,sizeof dp[u]);
    //case 1
    rep(k,0,sz-1){
        int v=e[u][k];if(v==fa)continue;
        memset(pre,0,sizeof pre);
        rep(i,1,n)pre[i]=(pre[i-1]+premult[k][i]*sufmult[k+2][i]%mod)%mod;
        rep(i,1,n)dp[u][i]=(dp[u][i]+pre[i-1]*dp[v][i]%mod)%mod;
    }
    //case 2
    rep(i,1,n)dp[u][i]=(dp[u][i]+premult[sz][i])%mod;
    rep(i,1,n)sum[u][i]=(sum[u][i-1]+dp[u][i])%mod;
}
void solve(){
    dfs(1,0);
    rep(i,2,n){
        rep(j,1,i-1)F[i]=(F[i]-F[j]+mod)%mod;
    }
}  
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>mod;
    C[0][0]=1;rep(i,1,2000){
        C[i][0]=1;rep(j,1,i)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
    rep(i,1,n-1){
        int u,v;cin>>u>>v;
        e[u].push_back(v);e[v].push_back(u);
    }
    solve();
    rep(i,1,n-1)cout<<g(i-1)<<' ';

    return 0;
}