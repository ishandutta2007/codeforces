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
using point=complex<ld>;
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
#define killshayan kill("done!\n")
const int N=4e6+10,LN=19,M=1e8+10,SQ=256,B=737,inf=1e9;
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
ll n,m,rev[N],a[N],b[N];
vector<ll> ans;
void fix(ll &x){
    if(x<0) x+=MD;
    if(x>=MD) x-=MD;
}
void ntt(ll *A, ll n, bool inv){
    ll lg=__builtin_ctzll(n);
    for(ll i=1; i<n; i++){
        rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
        if(rev[i]<i) swap(A[rev[i]],A[i]);
    }
    for(ll len=1; len<n; len<<=1){
        ll wn=pow(5,MD/2/len,MD);
        if(inv) wn=pow(wn,MD-2,MD);
        for(ll i=0; i<n; i+=len+len){
            ll w=1;
            for(ll j=i; j<i+len; j++){
                ll x=A[j],y=w*A[j+len]%MD;
                fix(A[j]=x+y);
                fix(A[j+len]=x-y);
                w=w*wn%MD;
            }
        }
    }
    if(inv){
        ll nn=pow(n,MD-2,MD);
        for(ll i=0; i<n; i++) A[i]=A[i]*nn%MD;
    }
}
int main(){
    fast_io;
    cin >> n >> m;
    ll t=1;
    while(m*2>=t) t*=2;
    for(ll i=1; i<=n; i++){
        ll x;
        cin >> x;
        a[x]=b[x]=1;
    }
    b[0]=1;
    ntt(b,t,0);
    for(ll i=0; i<t; i++){
        b[i]=b[i]*b[i]%MD;
    }
    ntt(b,t,1);
    b[0]=0;
    for(ll i=0; i<=m; i++){
        if(a[i]==0 && b[i]){
            kill("NO\n");
        }
        if(b[i]==2) ans.pb(i);
    }
    cout << "YES\n" << ans.size() << '\n';
    for(ll i : ans) cout << i << ' ';
    cout << '\n';
    return 0;
}