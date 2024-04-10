#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=5e5+10,LN=30,SQ=550,M=1e9+10;
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
int n,ans,f[N];
pair<pii,int> a[N];
map<int,int> c;
vector<int> v;
vector<pii> up;
void update(int t, int x){
    while(t<N){
        f[t]=max(f[t],x);
        t+=t&-t;
    }
}
int get(int t, int x=0){
    while(t){
        x=max(x,f[t]);
        t-=t&-t;
    }
    return x;
}
int main(){
    fast_io;
    cin >> n;
    for(ll i=0; i<n; i++){
        cin >> a[i].F.F;
        v.push_back(a[i].F.F);
    }
    ll t=1;
    sort(v.begin(),v.end());
    for(ll i : v) if(c[i]==0) c[i]=t++;
    for(ll i=0; i<n; i++){
        a[i].F.F=c[a[i].F.F];
    }
    c.clear();
    v.clear();
    for(ll i=0; i<n; i++){
        cin >> a[i].F.S;
        v.push_back(a[i].F.S);
    }
    t=1;
    sort(v.begin(),v.end());
    for(ll i : v) if(c[i]==0) c[i]=t++;
    for(ll i=0; i<n; i++){
        a[i].F.S=c[a[i].F.S];
    }
    c.clear();
    v.clear();
    for(ll i=0; i<n; i++){
        cin >> a[i].S;
        v.push_back(a[i].S);
    }
    t=1;
    sort(v.begin(),v.end());
    for(ll i : v) if(c[i]==0) c[i]=t++;
    for(ll i=0; i<n; i++){
        a[i].S=c[a[i].S];
    }
    c.clear();
    v.clear();
    sort(a,a+n,greater<pair<pii,int>>());
    for(ll i=0; i<n; i++){
        if(i>0 && a[i].F.F<a[i-1].F.F){
            for(pll p : up){
                update(p.F,p.S);
            }
            up.clear();
        }
        if(get(N-a[i].F.S-1)>a[i].S) ans++;
        up.emplace_back(N-a[i].F.S,a[i].S);
        //cout << ans << ' ' << a[i].F.F << ' ' << a[i].F.S << ' ' << a[i].S << '\n';
    }
    cout << ans;
    return 0;
    }