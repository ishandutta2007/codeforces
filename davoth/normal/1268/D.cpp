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
#define kill(x) cout << x << '\n';exit(0);
const int N=2e3+10,LN=24,M=1e7+10,SQ=500,B=737,inf=1e9;
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
ll n,k,ans,s;
vector<ll> vec;
bitset<N> adj[N],fl,rdj[N];
void scc(){
    s=0;
    k=1;
    vec.clear();
    for(ll i=1; i<=n; i++){
        vec.pb(adj[i].count());
        s+=adj[i].count();
    }
    sort(vec.begin(),vec.end());
    for(ll i=1; i<vec.size(); i++){
        s-=vec[i-1];
        if(s==i*(n-i)+(n-i)*(n-i-1)/2) k++;
    }
}
int main(){
    fast_io;
    cin >> n;
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=n; j++){
            char c;
            cin >> c;
            if(c=='1') adj[i][j]=1;
            if(!adj[i][j] && i!=j) rdj[i][j]=1;
        }
    }
    scc();
    if(k==1){
        kill("0 1");
    }
    if(n<=6){
        ll an=n;
        for(ll i=1; i<(1<<n); i++){
            for(ll j=1; j<=n; j++){
                if((i>>(j-1))&1){
                    for(ll x=1; x<=n; x++){
                        ll t=adj[x][j];
                        adj[x][j]=rdj[j][x]=rdj[x][j];
                        rdj[x][j]=adj[j][x]=t;
                    }
                }
            }
            scc();
            if(k==1){
                ll x=__builtin_popcountll(i);
                if(x<an) an=x,ans=0;
                if(an==x) ans++;
            }
            for(ll j=1; j<=n; j++){
                if((i>>(j-1))&1){
                    for(ll x=1; x<=n; x++){
                        ll t=adj[x][j];
                        adj[x][j]=rdj[j][x]=rdj[x][j];
                        rdj[x][j]=adj[j][x]=t;
                    }
                }
            }
        }
        if(ans){
            for(ll i=1; i<=an; i++) ans*=i;
            cout << an << ' ' << ans << '\n';
        }else cout << -1 << '\n';
        return 0;
    }
    for(ll i=1; i<=n; i++){
        swap(adj[i],rdj[i]);
        for(ll j=1; j<=n; j++){
            ll t=adj[j][i];
            adj[j][i]=rdj[j][i];
            rdj[j][i]=t;
        }
        scc();
        if(k==1) ans++;
        swap(adj[i],rdj[i]);
        for(ll j=1; j<=n; j++){
            ll t=adj[j][i];
            adj[j][i]=rdj[j][i];
            rdj[j][i]=t;
        }
    }
    cout << 1 << ' ' << ans << '\n';
    return 0;
}