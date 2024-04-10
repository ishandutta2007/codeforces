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
const int N=1e5+10,LN=20,M=2e4+10,SQ=350,B=737,inf=1e9;
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
ll n,a[N],b[N],q;
vector<ll> ans;
struct node{
    vector<pll> v;
} f[N*4];
node operator+(node x, node y){
    node z;
    ll i=0,j=0;
    while(i<x.v.size() || j<y.v.size()){
        ll nx;
        if(i<x.v.size() && j<y.v.size()){
            ll p=x.v[i].S,q=y.v[j].S;
            if(b[p]==b[q]){
                if(a[p]>=a[q]) nx=p;
                else nx=q;
                i++;
                j++;
            }else if(b[p]<b[q]){
                nx=p;
                i++;
            }else{
                nx=q;
                j++;
            }
        }else if(i<x.v.size()){
            nx=x.v[i].S;
            i++;
        }else{
            nx=y.v[j].S;
            j++;
        }
        while(!z.v.empty()){
            auto [t,k]=z.v.back();
            if(t*b[nx]+a[nx]<t*b[k]+a[k]) break;
            z.v.pop_back();
        }
        if(z.v.empty()){
            z.v.pb({0,nx});
        }else{
            auto [t,k]=z.v.back();
            t=(a[k]-a[nx])/(b[nx]-b[k])+1;
            z.v.pb({t,nx});
        }
    }
    return z;
}
void build(ll v, ll l, ll r){
    if(r-l==1){
        f[v].v.pb({0,l});
        return;
    }
    ll m=(l+r)>>1;
    build(lc,l,m);
    build(rc,m,r);
    f[v]=f[lc]+f[rc];
}
void get(ll v, ll l, ll r, ll tl, ll tr, ll x){
    if(tl>=r || l>=tr) return;
    if(l>=tl && r<=tr){
        auto it=upper_bound(f[v].v.begin(),f[v].v.end(),mp(x,INF));
        it--;
        ans.pb(it->S);
        return;
    }
    ll m=(l+r)>>1;
    get(lc,l,m,tl,tr,x);
    get(rc,m,r,tl,tr,x);
}
int main(){
    fast_io;
    cin >> n >> q;
    for(ll i=1; i<=n; i++) cin >> a[i] >> b[i];
    build(1,1,n+1);
    while(q--){
        ll l,r,t,mx;
        cin >> l >> r >> t;
        ans.clear();
        get(1,1,n+1,l,r+1,t);
        mx=ans[0];
        for(ll i=1; i<ans.size(); i++){
            if(b[ans[i]]*t+a[ans[i]]>b[mx]*t+a[mx]) mx=ans[i];
        }
        cout << mx << '\n';
    }
    return 0;
}