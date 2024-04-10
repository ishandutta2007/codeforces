#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
//#pragma GCC optimize("O2")
/*#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e2+10,LN=20,M=1.1e7+10,SQ=350,B=737,inf=1e9;
const ll INF=1e18;
const int MH=1000696969,MOD=1000000007  /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
int n,m,k,dx[]={1,-1,0,0},dy[]={0,0,1,-1},a[N],dp[128][N];
bitset<N> ans[128][N];
vector<int> adj[N],im;
priority_queue<pii,vector<pii>,greater<pii>> pq;
int id(int x, int y){
    return (x-1)*m+y-1;
}
int main(){
    fast_io;
    memset(dp,63,sizeof dp);
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int v=id(i,j);
            cin >> a[v];
            for(int t=0; t<4; t++){
                int ni=i+dx[t],nj=j+dy[t];
                if(ni && nj && ni<=n && nj<=m){
                    ll u=id(ni,nj);
                    adj[v].pb(u);
                }
            }
        }
    }
    for(int z=0; z<k; z++){
        int i,j;
        cin >> i >> j;
        int v=id(i,j);
        im.pb(v);
        dp[1<<z][v]=a[v];
        ans[1<<z][v][v]=1;
    }
    for(int mk=1; mk<(1<<k); mk++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                int v=id(i,j);
                for(int sb=(mk-1)&mk; sb>0; sb=(sb-1)&mk){
                    int x=dp[sb][v]+dp[mk^sb][v]-a[v];
                    if(x<dp[mk][v]){
                        dp[mk][v]=x;
                        ans[mk][v]=ans[sb][v]|ans[mk^sb][v];
                    }
                }
                pq.push({dp[mk][v],v});
            }
        }
        while(!pq.empty()){
            int v=pq.top().S,t=pq.top().F;
            pq.pop();
            if(t!=dp[mk][v]) continue;
            for(int u : adj[v]){
                ll x=t+a[u];
                if(x<dp[mk][u]){
                    dp[mk][u]=x;
                    ans[mk][u]=ans[mk][v];
                    ans[mk][u][u]=1;
                    pq.push({x,u});
                }
            }
        }
    }
    cout << dp[(1<<k)-1][im[0]] << '\n';
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int v=id(i,j);
            if(ans[(1<<k)-1][im[0]][v]) cout << 'X';
            else cout << '.';
        }
        cout << '\n';
    }
    return 0;
}