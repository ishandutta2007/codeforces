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
const int N=1e2+10,LN=60,M=1e6+10,SQ=700,BS=737,inf=1.05e9,NSQ=N/SQ+3;
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
ll t, n, ans, mn, h[N][N];
bool d[N][N][N], g[N];
vector<pll> ed;
vector<ll> cn, adj[N];
vector<vector<ll>> vec[N];
void dfs(ll v, ll p){
    g[v] = 1;
    for(auto a : vec[v]){
        ll f = 0;
        for(ll i : a) if(i == p) f = 1;
        if(!f) continue;
        for(ll i : a){
            if(i != p){
                if(g[i]){
                    ans = 0;
                    return;
                }
                ed.pb({i, v});
                adj[i].pb(v);
                adj[v].pb(i);
                dfs(i, v);
            }
        }
    }
}
void sfd(ll v, ll p, ll r){
    for(ll u : adj[v]){
        if(u == p) continue;
        h[r][u] = h[r][v] + 1;
        sfd(u, v, r);
    }
}
int main(){
    fast_io;
    cin >> t;
    while(t--){
        cin >> n;
        ans = 1;
        ed.clear();
        cn.clear();
        mn = n + 1;
        for(ll i = 1; i <= n; i++){
            vec[i].clear();
            adj[i].clear();
            g[i] = 0;
        }
        for(ll i = 1; i <= n; i++) for(ll j = 1; j <= n; j++) d[i][j][j] = 1;
        for(ll i = 1; i < n; i++){
            for(ll j = 1; j <= n - i; j++){
                string s;
                cin >> s;
                for(ll k = 1; k <= n; k++){
                    if(s[k - 1] == '1') d[k][i][i + j] = d[k][i + j][i] = 1;
                    else d[k][i][i + j] = d[k][i + j][i] = 0;
                }
            }
        }
        for(ll i = 1; i <= n; i++){
            ll f[N];
            memset(f,0,sizeof f);
            for(ll j = 1; j <= n; j++){
                if(f[j]) continue;
                vector<ll> v = {j};
                f[j] = j;
                for(ll k = 1; k <= n; k++){
                    if(d[i][j][k] && f[k] != j && f[k]){
                        ans = 0;
                    }
                    if(d[i][j][k] && !f[k]){
                        v.pb(k);
                        f[k] = j;
                    }
                }
                for(ll k : v){
                    for(ll x = 1; x <= n; x++){
                        if((f[x] != j && d[i][k][x]) || (f[x] == j && !d[i][k][x])){
                            ans = 0;
                        }
                    }
                }
                if(j == i && (ll)v.size() > 1) ans = 0;
                vec[i].pb(v);
            }
            if((ll)vec[i].size() < mn) mn = (ll)vec[i].size(), cn.clear();
            if((ll)vec[i].size() == mn) cn.pb(i);
        }
        if((ll)cn.size() > 2){
            ans = 0;
        }else{
            if((ll)cn.size() == 2){
                ed.pb({cn[0], cn[1]});
                adj[cn[0]].pb(cn[1]);
                adj[cn[1]].pb(cn[0]);
                dfs(cn[0], cn[1]);
                dfs(cn[1], cn[0]);
            }else{
                g[cn[0]] = 1;
                for(ll i = 1; i <= n; i++){
                    if((ll)vec[i].size() == mn + 1){
                        ed.pb({cn[0], i});
                        adj[i].pb(cn[0]);
                        adj[cn[0]].pb(i);
                        dfs(i, cn[0]);
                    }
                }
            }
        }
        bool f = 1;
        for(ll i = 1; i <= n; i++) if(!g[i]) f = 0;
        if(!ans || !f || (ll)ed.size()!= n - 1) cout << "No\n";
        else{
            for(ll i = 1; i <= n; i++){
                h[i][i] = 0;
                sfd(i, 0, i);
                for(ll j = 1; j <= n; j++){
                    for(ll k = 1; k <= n; k++){
                        if((h[i][j] == h[i][k] && !d[i][j][k]) || (h[i][j] != h[i][k] && d[i][j][k])) ans = 0;
                    }
                }
            }
            if(ans){
                cout << "Yes\n";
                for(auto [x,y] : ed) cout << x << ' ' << y << '\n';
            }else cout << "No\n";
        }
    }
    return 0;
}