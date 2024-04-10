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
const int N=2e5+10,LN=19,M=3e2+10,SQ=350,BS=737,inf=1e9;
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
    pair<ll, pll> A[SQ]; // {start, {m, h}}
    int L, R;
    CHT(){
        L=R=0;
        memset(A, 0, sizeof(A));
    }
    inline ll Intersect(pll a, pll b){ // a.first<=b.first
        if (a.first==b.first) return (a.second<=b.second?-INF:INF);
        return (a.second-b.second)/(b.first-a.first) + ((a.second-b.second)%(b.first-a.first)>0);
    }
    inline void Add(pll X){
        while (L<R && Intersect(A[R-1].second, X)<=A[R-1].first) R--;
        if (L==R) A[R++]={-INF, X};
        else A[R]={Intersect(A[R-1].second, X), X}, R++;
    }
    inline pll GetMax(ll x){
        while (L+1<R && A[L+1].first<=x) L++;
        return {A[L].second.first*x + A[L].second.second,A[L].second.first};
    }
} cht[N/SQ];
ll n,mxb,w,p[N],lz[N/SQ];
vector<ll> vec[N];
void build(ll k){
    ll l=k*SQ,r=min((ll)N,l+SQ);
    cht[k].L=cht[k].R=0;
    for(ll i=l; i<r; i++){
        p[i]+=i*lz[k];
        cht[k].Add({i,p[i]});
    }
    lz[k]=0;
}
void add(ll l, ll r, ll x){
    ll tl=-1,tr=-1;
    while(l<r && l%SQ){
        tl=l/SQ;
        p[l]+=x*l;
        l++;
    }
    while(l<r && r%SQ){
        r--;
        tr=r/SQ;
        p[r]+=x*r;
    }
    while(l<r){
        lz[l/SQ]+=x;
        l+=SQ;
    }
    if(~tl) build(tl);
    if(~tr) build(tr);
}
int main(){
    fast_io;
    cin >> n >> w;
    for(ll i=0; i<N/SQ; i++) build(i);
    for(ll i=1; i<=n; i++){
        ll a,b;
        cin >> a >> b;
        mxb=max(b,mxb);
        vec[b].pb(a);
    }
    ll k=n;
    for(ll i=0; i<=mxb+1; i++){
        pll t={0,-INF};
        for(ll j=0; j<N/SQ; j++) t=max(t,cht[j].GetMax(lz[j]));
        cout << t.F+k*w*i << ' ' << t.S << '\n';
        for(ll j : vec[i]){
            k--;
            add(0,j+1,1);
        }
    }
    return 0;
}