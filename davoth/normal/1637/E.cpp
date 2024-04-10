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
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define kill(x) cout << x << '\n';exit(0)
#define killshayan kill("done!")
#define killmashtali kill("Hello, World!")
const int N=3e5+10,LN=19,M=1e5+10,SQ=300,BS=737,inf=1e9,NSQ=N/SQ+1;
const ll INF=1e16;
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
int n,t,a[N],m;
int main(){
    fast_io;
    cin >> t;
    while(t--){
        cin >> n >> m;
        ll ans=0;
        map<int,int> cnt;
        vector<pii> p(m*2);
        vector<int> c[n+1],vec;
        for(int i=1; i<=n; i++){
            cin >> a[i];
            cnt[a[i]]++;
        }
        for(int i=1; i<=m; i++){
            int x,y;
            cin >> x >> y;
            p.pb({x,y});
            p.pb({y,x});
        }
        for(auto [x,y] : cnt){
            c[y].pb(x);
        }
        sort(p.begin(),p.end());
        for(int i=1; i<=n; i++){
            reverse(c[i].begin(),c[i].end());
            for(int x : c[i]){
                for(int j=1; j<=i; j++){
                    for(int y : c[j]){
                        if(x!=y && !binary_search(p.begin(),p.end(),mp(x,y))){
                            ans=max(ans,1ll*(x+y)*(i+j));
                            break;
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}