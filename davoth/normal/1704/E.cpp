/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
using ld=long double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
using point=complex<double>;
#define F first
#define S second
//#define X real()
//#define Y imag()
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define kill(x) cout << x << '\n';exit(0)
#define killshayan kill("done!")
#define killmashtali kill("Hello, World!")
const int N=2e6+10,LN=20,M=1e6+10,SQ=700,BS=737,inf=1.05e9,NSQ=N/SQ+3;
const ll INF=1e18;
const double pi=acos(-1);
const ld ep=1e-7;
const int MH=1000696969,MD=998244353,MOD=1000000007;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pii, null_type,greater<pii>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll t,n,m,a[N],f[N],b[N];
vector<ll> tp,out[N],in[N];

void dfs(ll v){
    f[v]=1;
    for(ll u : out[v]) if(!f[u]) dfs(u);
    tp.pb(v);
}

int main(){
    fast_io;
    cin >> t;
    while(t--){
        cin >> n >> m;
        tp.clear();
        for(ll i=1; i<=n; i++){
            in[i].clear();
            out[i].clear();
            f[i]=0;
            b[i]=0;
            cin >> a[i];
        }
        for(ll i=1; i<=m; i++){
            ll v,u;
            cin >> v >> u;
            out[v].pb(u);
            in[u].pb(v);
        }
        for(ll i=1; i<=n; i++) if(!f[i]) dfs(i);
        reverse(tp.begin(),tp.end());
        for(ll i : tp){
            b[i]=(a[i]+b[i])%MD;
            for(ll j : out[i]) b[j]=(b[j]+b[i])%MD;
        }
        ll ans=b[tp.back()];
        reverse(tp.begin(),tp.end());
        for(ll i=0; i<n; i++){
            bool f=0;
            for(ll j : tp){
                if(a[j]){
                    f=1;
                    a[j]--;
                    for(ll u : out[j]) a[u]++;
                }else if(j==tp[0]){
                    ans++;
                }
            }
            if(!f){
                ans=i;
                break;
            }
        }
        cout << ans%MD << '\n';
    }
    return 0;
}