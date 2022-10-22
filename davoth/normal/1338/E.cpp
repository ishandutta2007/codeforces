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
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=8e4+10,LN=18,M=2e4+10,SQ=500,B=737,inf=1e9;
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
ll n,d[N],ans,mn=1,k;
bitset<N> ad[N];
vector<ll> vec;
int main(){
    fast_io;
    cin >> n;
    k=614*n;
    for(ll i=1; i<=n; i++){
        for(ll j=0; j<n/4; j++){
            char c;
            ll k;
            cin >> c;
            if(c>='0' && c<='9') k=c-'0';
            else k=c-'A'+10;
            for(ll t=1; t<=4; t++){
                ad[i][j*4+t]=(k>>(4-t))&1;
            }
        }
        vec.pb(i);
        d[i]=ad[i].count();
        if(d[i]<d[mn]) mn=i;
    }
    sort(vec.begin(),vec.end(),[](ll a, ll b){if(ad[mn][a]!=ad[mn][b]) return ad[mn][b]; return ad[a][b];});
    reverse(vec.begin(),vec.end());
    while(n && d[vec[n-1]]==n-1){
        ans+=(k+1)*(n-1);
        n--;
        vec.pop_back();
    }
    reverse(vec.begin(),vec.end());
    for(ll i=0; i<n; i++){
        ans+=3*(n-1)-2*d[vec[i]]-d[vec[(d[vec[i]]+i)%n]];
    }
    cout << ans << '\n';
    return 0;
}