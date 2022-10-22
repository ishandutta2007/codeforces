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
const int N=2e6+10,LN=22,M=1e6+10,SQ=700,BS=737,inf=1.05e9,NSQ=N/SQ+3;
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
ll n,sz,mx=-inf,mi,f[N*4],lz[N*4],op,h[N],P[N],IP[N];
string S;
bool cmp(ll x, ll y){
    ll l=0,r=n;
    while(r-l>1){
        ll m=(l+r)>>1;
        ll h1=(h[x+m-1]-h[x-1]*P[m]%MH+MH)%MH;
        ll h2=(h[y+m-1]-h[y-1]*P[m]%MH+MH)%MH;
        if(h1==h2) l=m;
        else r=m;
    }
    return S[x+l-1]<S[y+l-1];
}
void shift(ll v, ll l, ll r){
    f[v]+=lz[v];
    if(r-l>1){
        lz[lc]+=lz[v];
        lz[rc]+=lz[v];
    }
    lz[v]=0;
}
void upd(ll v, ll l, ll r, ll tl, ll tr, ll x){
    shift(v,l,r);
    if(l>=tr || tl>=r) return;
    if(l>=tl && r<=tr){
        lz[v]+=x;
        return shift(v,l,r);
    }
    ll m=(l+r)>>1;
    upd(lc,l,m,tl,tr,x);
    upd(rc,m,r,tl,tr,x);
    f[v]=min(f[lc],f[rc]);
}
ll get(ll v, ll l, ll r, ll tl, ll tr){
    shift(v,l,r);
    if(l>=tr || tl>=r) return 0;
    if(l>=tl && r<=tr) return f[v];
    ll m=(l+r)>>1;
    return min(get(lc,l,m,tl,tr),get(rc,m,r,tl,tr));
}
int main(){
    fast_io;
    cin >> S;
    P[0]=IP[0]=1;
    for(ll i=1; i<N; i++){
        P[i]=P[i-1]*3%MH;
        IP[i]=pow(P[i],MH-2,MH);
    }
    n=S.size();
    sz=n*2;
    S+=S;
    for(ll i=1; i<=sz; i++){
        h[i]=h[i-1]*3;
        if(S[i-1]=='(') h[i]++;
        else h[i]+=2;
        h[i]%=MH;
    }
    for(ll i=sz; i; i--){
        if(S[i-1]=='(') op++,upd(1,1,sz+1,i,i+n,1);
        else upd(1,1,sz+1,i,i+n,-1);
        if(i>n) continue;
        ll x=get(1,1,sz+1,i,i+n);
        if(x>mx){
            mx=x;
            mi=i;
        }else if(x==mx && cmp(i,mi)) mi=i;
    }
    op/=2;
    mx*=-1;
    for(ll i=1; i<=mx; i++) cout << '(';
    for(ll i=mi; i<mi+n; i++) cout << S[i-1];
    op+=mx;
    n+=mx;
    op=op*2-n;
    for(ll i=1; i<=op; i++) cout << ')';
    cout << '\n';
    return 0;
}