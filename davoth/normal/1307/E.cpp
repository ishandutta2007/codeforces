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
const int N=5e3+10,LN=18,M=1e6+10,SQ=350,BS=737,inf=1.05e9,NSQ=N/SQ+1;
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
ll n,m,s[N],h[N],L[N],R[N],mx,mw=1,t[N];
vector<ll> f[N];
int main(){
    fast_io;
    cin >> n >> m;
    for(ll i=1; i<=n; i++) cin >> s[i];
    for(ll i=1; i<=m; i++){
        ll x;
        cin >> x >> h[i];
        f[x].pb(i);
    }
    for(ll i=1; i<=n; i++){
        ll p=0,x=0,q=n+1,y=0,k=0;
        sort(f[i].begin(),f[i].end(),[&](ll &a, ll &b){return h[a]<h[b];});
        for(ll j : f[i]){
            while(x<h[j] && p<n){
                if(s[++p]==i) x++;
            }
            if(x<h[j]){
                L[j]=-1;
            }else{
                L[j]=p;
                t[p]=j;
            }
            while(y<h[j] && q>1){
                if(s[--q]==i) y++;
            }
            if(y<h[j]){
                R[j]=-1;
            }else{
                R[j]=q;
                k++;
            }
        }
        if(k){
            mx++;
            mw=(mw*k)%MOD;
        }
    }
    for(ll tf=1; tf<=n; tf++){
        ll az=0,azw=1;
        if(!t[tf]) continue;
        for(ll i=1; i<=n; i++){
            ll g=0,l=0,r=0,lr=0;
            for(ll j : f[i]){
                if(L[j]==-1) continue;
                if(L[j]==tf) g=1;
                else if(L[j]<tf && R[j]>tf) lr++;
                else if(L[j]<tf) l++;
                else if(R[j]>tf) r++;
            }
            if(g){
                az++;
                if(lr+r){
                    az++;
                    azw=azw*(lr+r)%MOD;
                }
            }else{
                if(l+lr+r==0) continue;
                else if(l+lr==0){
                    az++;
                    azw=azw*r%MOD;
                }else if(lr+r==0){
                    az++;
                    azw=azw*l%MOD;
                }else if(l+r==0 && lr==1){
                    az++;
                    azw=azw*2%MOD;
                }else{
                    az+=2;
                    azw=azw*(lr*(lr-1)+l*lr+lr*r+l*r)%MOD;
                }
            }
        }
        if(az>mx){
            mx=az;
            mw=0;
        }
        if(az==mx) mw=(mw+azw)%MOD;
    }
    cout << mx << ' ' << mw << '\n';
    return 0;
}