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
const int N=3e5+10,LN=18,M=1e6+10,SQ=350,BS=737,inf=1.05e9,NSQ=N/SQ+1;
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
ll n,k,a[N],ans,L[M],R[M];
void solve(ll l, ll r){
    if(r-l==1) return;
    ll m=(l+r)>>1;
    solve(l,m);
    solve(m,r);
    ll x=m-1,y=m,mx=0,p=0,sl=0,sr=0;
    vector<ll> vl,vr;
    for(ll i=x; i>=l; i--){
        if(a[i]>mx){
            mx=a[i];
            vl.pb(i);
        }
    }
    vl.pb(l-1);
    mx=0;
    for(ll i=y; i<r; i++){
        if(a[i]>mx){
            mx=a[i];
            vr.pb(i);
        }
    }
    vr.pb(r);
    for(ll t=0; t+1<(ll)vr.size(); t++){
        mx=a[vr[t]];
        while(p+1<(ll)vl.size() && a[vl[p]]<=mx){
            while(x>vl[p+1]){
                sl=(sl+a[x])%k;
                L[sl]++;
                ans+=R[(k-sl+a[vl[p]])%k];
                x--;
            }
            p++;
        }
        while(y<vr[t+1]){
            sr=(sr+a[y])%k;
            R[sr]++;
            ans+=L[(k-sr+mx)%k];
            y++;
        }
    }
    mx=0;
    while(x>l-1){
        if(a[x]>mx) mx=a[x];
        sl=(sl+a[x])%k;
        ans+=R[(k-sl+mx)%k];
        x--;
    }
    sl=sr=0;
    for(ll i=m; i<r; i++){
        sr=(a[i]+sr)%k;
        R[sr]=0;
    }
    for(ll i=m-1; i>=l; i--){
        sl=(a[i]+sl)%k;
        L[sl]=0;
    }
}
int main(){
    fast_io;
    cin >> n >> k;
    for(ll i=1; i<=n; i++) cin >> a[i];
    solve(1,n+1);
    cout << ans << '\n';
    return 0;
}