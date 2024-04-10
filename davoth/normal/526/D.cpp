#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e6+10,LN=30,SQ=550,M=1e6+10;
const ll INF=1e16;
const int MOD=1000000007 /*998244353*/;
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
ll n,k,h[N],b=737,m=1000696969,c[N],ans[N];
string s;
int main(){
    fast_io;
    cin >> n >> k >> s;
    c[0]=1;
    for(ll i=1; i<N; i++) c[i]=b*c[i-1]%m;
    for(ll i=1; i<=n; i++) h[i]=(h[i-1]*b+s[i-1]-'a'+1)%m;
    for(ll i=1; i*k<=n; i++){
        if(k!=1 && h[i*(k-1)]!=(h[i*k]-h[i]*c[i*(k-1)]%m+m)%m) continue;
        ll l=i*k,r=min(i*(k+1)+1,n+1);
        while(r-l>1){
            ll md=(l+r)/2;
            if((m+h[md]-h[i*k]*c[md-i*k]%m)%m==h[md-i*k]) l=md;
            else r=md;
        }
        ans[i*k]++;
        ans[l+1]--;
    }
    for(ll i=2; i<=n; i++) ans[i]+=ans[i-1];
    for(ll i=1; i<=n; i++){
        if(ans[i]>0) cout << 1;
        else cout << 0;
    }
    cout << '\n';
    return 0;
}