#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e6+10,LN=20,SQ=547,M=1e6+10;
const ll INF=1e16;
const int MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<pair<pll,ll>, null_type,less<pair<pll,ll>>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,a[N],b[N],p1[N],p2[N];
pll c[N],p={-1,-1};
int main(){
    fast_io;
    cin >> n;
    for(ll i=1; i<=n; i++){
        cin >> a[i];
        p1[i]=p1[i-1]+a[i];
    }
    for(ll i=1; i<=n; i++){
        cin >> b[i];
        p2[i]=p2[i-1]+b[i];
    }
    fill(c,c+N,p);
    if(p2[n]>=p1[n]){
        ll t=-1;
        for(ll i=0; i<=n; i++){
            while(t<n && p2[t+1]<=p1[i]) t++;
            if(c[p1[i]-p2[t]]!=p){
                auto [x,y]=c[p1[i]-p2[t]];
                cout << i-x << '\n';
                for(ll j=x+1; j<=i; j++) cout << j << ' ';
                cout << '\n' << t-y << '\n';
                for(ll j=y+1; j<=t; j++) cout << j << ' ';
                cout << '\n';
                return 0;
            }
            c[p1[i]-p2[t]]={i,t};
        }
    }else{
        ll t=-1;
        for(ll i=0; i<=n; i++){
            while(t<n && p1[t+1]<=p2[i]) t++;
            if(c[p2[i]-p1[t]]!=p){
                auto [x,y]=c[p2[i]-p1[t]];
                cout << t-x << '\n';
                for(ll j=x+1; j<=t; j++) cout << j << ' ';
                cout << '\n' << i-y << '\n';
                for(ll j=y+1; j<=i; j++) cout << j << ' ';
                cout << '\n';
                return 0;
            }
            c[p2[i]-p1[t]]={t,i};
        }
    }
    return 0;
}