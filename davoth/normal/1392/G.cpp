#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
//#pragma GCC optimize("O2")
/*#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
using ld = long double;
#define F first
#define S second
#define pb push_back
//#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e6+10,LN=20,M=3.5e7+10,SQ=350,BS=737,inf=1e9+10;
const ll INF=1e15;
const ld ep=1e-7;
const int MH=1000696969,MOD=1000000007,MD=998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
ll n,m,k,s[N],t[N],p[N],l[N],r[N],ans=-1,al,ar,x;
string S,T;
int main(){
    fast_io;
    cin >> n >> m >> k >> S >> T;
    x=k;
    for(ll i=0; i<k; i++){
        s[0]|=(S[i]-'0')<<i;
        t[0]|=(T[i]-'0')<<i;
        x-=S[i]-'0'+T[i]-'0';
        p[i]=i;
    }
    for(ll i=1; i<=n; i++){
        ll a,b;
        cin >> a >> b;
        swap(p[a-1],p[b-1]);
        for(ll j=0; j<k; j++){
            s[i]|=((s[0]>>j)&1)<<p[j];
            t[i]|=((t[0]>>j)&1)<<p[j];
        }
    }
    memset(l,63,sizeof l);
    memset(r,-1,sizeof r);
    for(ll i=0; i<=n; i++){
        l[s[i]]=min(l[s[i]],i);
        r[t[i]]=i;
    }
    for(ll i=0; i<k; i++){
        for(ll j=0; j<(1<<k); j++){
            if(!(j&(1<<i))){
                l[j]=min(l[j],l[j|(1<<i)]);
                r[j]=max(r[j],r[j|(1<<i)]);
            }
        }
    }
    for(ll i=0; i<(1<<k); i++){
        if(r[i]-l[i]>=m && __builtin_popcountll(i)>ans){
            ans=__builtin_popcountll(i);
            al=l[i]+1;
            ar=r[i];
        }
    }
    cout << ans*2+x << '\n' << al << ' ' << ar << '\n';
    return 0;
}