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
const int N=2e5+10,LN=20,M=1e5+10,SQ=500,BS=737,inf=1.05e9,NSQ=N/SQ+1;
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
ll n,q,f[N*4];
set<ll> st;
void build(ll v, ll l, ll r){
    f[v]=INF;
    if(r-l>1){
        ll m=(l+r)>>1;
        build(lc,l,m);
        build(rc,m,r);
    }
}
void upd(ll v, ll l, ll r, ll p, ll x){
    if(r-l==1){
        f[v]=min(f[v],x);
        return;
    }
    ll m=(l+r)>>1;
    if(p<m) upd(lc,l,m,p,x);
    else upd(rc,m,r,p,x);
    f[v]=min(f[lc],f[rc]);
}
ll get(ll v, ll l, ll r, ll tl, ll tr){
    if(tl>=tr || l>=tr || tl>=r) return INF;
    if(l>=tl && r<=tr) return f[v];
    ll m=(l+r)>>1;
    return min(get(lc,l,m,tl,tr),get(rc,m,r,tl,tr));
}
int main(){
    fast_io;
    cin >> n >> q;
    build(1,1,n+1);
    for(ll i=0; i<=n+1; i++) st.insert(i);
    while(q--){
        ll t;
        cin >> t;
        if(!t){
            ll l,r,x;
            cin >> l >> r >> x;
            if(!x){
                auto it=st.lower_bound(l);
                while(it!=st.end() && *it<=r) it=st.erase(it);
            }else{
                upd(1,1,n+1,l,r);
            }
        }else{
            ll x;
            cin >> x;
            auto it=st.lower_bound(x);
            if(*it!=x){
                cout << "NO\n";
            }else{
                auto ti=it;
                ti--;
                it++;
                ll l=*ti,r=*it;
                if(get(1,1,n+1,l+1,n+1)<r) cout << "YES\n";
                else cout << "N/A\n";
            }
        }
    }
    return 0;
}