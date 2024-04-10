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
const int N=2e5+10,LN=19,M=3e2+10,SQ=450,BS=737,inf=1e9,NSQ=N/SQ+1;
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
    inline ll GetMax(ll x){
        while (L+1<R && A[L+1].first<=x) L++;
        return A[L].second.first*x + A[L].second.second;
    }
} cht[NSQ][2];
ll n,q,st[N],fn[N],T,a[N],b[N],A[N],B[N],lz[N];
vector<ll> adj[N],vec[NSQ];
void Build(ll k){
    cht[k][0].L=cht[k][0].R=cht[k][1].L=cht[k][1].R=0;
    for(ll i : vec[k]){
        a[i]+=lz[k]*b[i];
        cht[k][0].Add({b[i],a[i]});
    }
    for(ll i=vec[k].size()-1; i>=0; i--) cht[k][1].Add({-b[vec[k][i]],-a[vec[k][i]]});
    lz[k]=0;
}
void Add(ll l, ll r, ll x){
    ll tl=-1,tr=-1;
    while(l<r && l%SQ){
        a[l]+=x*b[l];
        tl=l/SQ;
        l++;
    }
    while(l<r && r%SQ){
        r--;
        a[r]+=x*b[r];
        tr=r/SQ;
    }
    while(l<r){
        lz[l/SQ]+=x;
        l+=SQ;
    }
    if(~tl) Build(tl);
    if(~tr) Build(tr);
}
ll Get(ll l, ll r){
    ll ans=0;
    while(l<r && l%SQ){
        ans=max(ans,abs(a[l]+lz[l/SQ]*b[l]));
        l++;
    }
    while(l<r && r%SQ){
        r--;
        ans=max(ans,abs(a[r]+lz[r/SQ]*b[r]));
    }
    while(l<r){
        ans=max(ans,max(cht[l/SQ][0].GetMax(lz[l/SQ]),cht[l/SQ][1].GetMax(lz[l/SQ])));
        l+=SQ;
    }
    return ans;
}
void dfs(ll v){
    st[v]=++T;
    b[T]=abs(B[v]);
    a[T]=b[T]*A[v];
    for(ll u : adj[v]){
        A[u]+=A[v];
        B[u]+=B[v];
        dfs(u);
    }
    fn[v]=T;
}
int main(){
    fast_io;
    cin >> n >> q;
    for(ll i=2; i<=n; i++){
        ll p;
        cin >> p;
        adj[p].pb(i);
    }
    for(ll i=1; i<=n; i++) cin >> A[i];
    for(ll i=1; i<=n; i++) cin >> B[i];
    dfs(1);
    for(ll i=1; i<=n; i++){
        vec[i/SQ].pb(i);
    }
    for(ll i=0; i*SQ<=n; i++){
        sort(vec[i].begin(),vec[i].end(),[&](ll x, ll y){return b[x]<b[y];});
        Build(i);
    }
    while(q--){
        ll t,v,x;
        cin >> t >> v;
        if(t==1){
            cin >> x;
            Add(st[v],fn[v]+1,x);
        }else{
            cout << Get(st[v],fn[v]+1) << '\n';
        }
    }
    return 0;
}