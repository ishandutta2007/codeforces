#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
//#pragma GCC optimize("O2")
/*#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e6+10,LN=20,M=1.1e7+10,SQ=350,B=737,inf=1e9;
const ll INF=1e18;
const int MH=1000696969,MOD=/*1000000007*/ 998244353;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
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
ll d,q,s,x[60],f[200],iv[200];
vector<ll> p;
int main(){
    fast_io;
    cin >> d >> q;
    f[0]=iv[0]=1;
    for(ll i=1; i<200; i++) f[i]=f[i-1]*i%MOD,iv[i]=pow(f[i],MOD-2,MOD);
    ll s=sqrt(d)+1;
    for(ll i=2; i<=s; i++){
        if(d%i==0) p.pb(i);
        while(d%i==0) d/=i;
    }
    if(d>1) p.pb(d);
    while(q--){
        ll v,u,ans=1,s=0,t=0;
        cin >> v >> u;
        memset(x,0,sizeof x);
        for(ll i=0; i<p.size(); i++){
            while(v%p[i]==0) x[i]++,v/=p[i];
            while(u%p[i]==0) x[i]--,u/=p[i];
            if(x[i]<0) x[i]*=-1,t+=x[i];
            else s+=x[i];
            ans=ans*iv[x[i]]%MOD;
        }
        ans=ans*f[s]%MOD*f[t]%MOD;
        cout << ans << '\n';
    }
    return 0;
}