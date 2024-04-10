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
#define killshayan kill("done!\n")
#define killmashtali kill("Hello, World!")
const int N=4e5+10,LN=19,M=1e8+10,SQ=256,B=737,inf=1e9;
const ll INF=1e18;
const double pi=acos(-1);
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
ll n,rev[N],x,y,a[N],b[N],c[N],f[N],iv[N];
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
void solve(ll l, ll r){
    if(r-l==1) return;
    ll m=(l+r)>>1,k=1;
    while(k<(r-l)*2) k*=2;
    solve(l,m);
    solve(m,r);
    for(ll i=0; i<k; i++){
        b[i]=c[i]=0;
        if(i<(m-l)*2) b[i]=a[l*2+i];
        if(i<(r-m)*2) c[i]=a[m*2+i];
    }
    ntt(b,k,0);
    ntt(c,k,0);
    for(ll i=0; i<k; i++) b[i]=b[i]*c[i]%MD;
    ntt(b,k,1);
    for(ll i=l*2; i<r*2; i++){
        a[i]=b[i-l*2];
    }
}
ll C(ll n, ll k){
    if(k<0 || k>n) return 0;
    return f[n]*iv[k]%MD*iv[n-k]%MD;
}
int main(){
    fast_io;
    f[0]=iv[0]=1;
    for(ll i=1; i<N; i++){
        f[i]=f[i-1]*i%MD;
        iv[i]=pow(f[i],MD-2,MD);
    }
    cin >> n >> x >> y;
    for(ll i=0; i<n; i++){
        a[i*2]=i;
        a[(i*2)^1]=1;
    }
    if(!x || !y || x+y>n+1){
        kill("0\n");
    }
    if(n==1){
        kill("1\n");
    }
    solve(0,n-1);
    cout << a[x+y-2]*C(x+y-2,x-1)%MD << '\n';
    return 0;
}