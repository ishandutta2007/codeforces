#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll=long long int;
using ld=long double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=4e3+10,LN=20,M=2e4+10,SQ=350,B=737,inf=1e9;
const ll INF=1e18;
const ld ep=1e-7;
const int MH=1000696969,MD=998244353,MOD=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
int n,p,dp[20][N],q,c[N],h[N],ans[M],b[M];
vector<int> vec[M*4],qu[M];
void upd(int v, int l, int r, int tl, int tr, int x){
    if(tl>=r || l>=tr) return;
    if(l>=tl && r<=tr){
        vec[v].pb(x);
        return;
    }
    int m=(l+r)>>1;
    upd(lc,l,m,tl,tr,x);
    upd(rc,m,r,tl,tr,x);
}
void solve(int v, int l, int r, int k){
    for(int i : vec[v]){
        for(int j=N-1; j>=c[i]; j--) dp[k][j]=max(dp[k][j],dp[k][j-c[i]]+h[i]);
    }
    if(r-l==1){
        for(int i : qu[l]) ans[i]=dp[k][b[i]];
        return;
    }
    int m=(l+r)>>1;
    for(int i=0; i<N; i++) dp[k+1][i]=dp[k][i];
    solve(lc,l,m,k+1);
    for(int i=0; i<N; i++) dp[k+1][i]=dp[k][i];
    solve(rc,m,r,k+1);
}
int main(){
    fast_io;
    cin >> n >> p;
    for(int i=1; i<=n; i++){
        int t;
        cin >> c[i] >> h[i] >> t;
        upd(1,1,M,t,t+p,i);
    }
    cin >> q;
    for(int i=1; i<=q; i++){
        int t;
        cin >> t >> b[i];
        qu[t].pb(i);
    }
    solve(1,1,M,0);
    for(int i=1; i<=q; i++) cout << ans[i] << '\n';
    return 0;
}