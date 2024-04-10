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
const int N=1e5+10,LN=19,M=3e2+10,SQ=256,BS=737,inf=1e9;
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
struct CHT{
    vector<pair<ll,pll>> A; // {start, {m, h}}
    int sz;
    CHT(){
        sz=0;
    }
    CHT(ll n){
        sz=0;
        A.resize(n);
    }
    inline ll Intersect(pll a, pll b){ // a.first<=b.first
        if (a.first==b.first) return (a.second<=b.second?-INF:INF);
        return (a.second-b.second)/(b.first-a.first) + ((a.second-b.second)%(b.first-a.first)>0);
    }
    inline void Add(pll X){
        while (sz && Intersect(A[sz-1].second, X)<=A[sz-1].first) sz--;
        if (!sz) A[sz++]={-INF, X};
        else A[sz]={Intersect(A[sz-1].second, X), X}, sz++;
    }
    inline ll GetMax(ll x){
        pll B=(upper_bound(A.begin(), A.begin()+sz, pair<ll, pll>(x, pll(INF, INF)))-1)->second;
        return B.first*x+B.second;
    }
} f[N*4];
ll n,q,a[N],ps[N];
void build(ll v, ll l, ll r){
    f[v]=CHT(r-l);
    pll t[r-l];
    for(ll i=l; i<r; i++){
        t[i-l]={a[i],ps[i]-a[i]*i};
    }
    sort(t,t+r-l);
    for(ll i=0; i<r-l; i++) f[v].Add(t[i]);
    if(r-l>1){
        ll m=(l+r)>>1;
        build(lc,l,m);
        build(rc,m,r);
    }
}
ll get(ll v, ll l, ll r, ll tl, ll tr, ll x){
    if(l>=tr || tl>=r) return -INF;
    if(l>=tl && r<=tr) return f[v].GetMax(x);
    ll m=(l+r)>>1;
    return max(get(lc,l,m,tl,tr,x),get(rc,m,r,tl,tr,x));
}
int main(){
    fast_io;
    cin >> n;
    for(ll i=1; i<=n; i++){
        cin >> a[i];
        ps[i]=a[i]+ps[i-1];
    }
    build(1,1,n+1);
    cin >> q;
    while(q--){
        ll x,y;
        cin >> x >> y;
        cout << ps[y]-get(1,1,n+1,y-x+1,y+1,y-x) << '\n';
    }
    return 0;
}