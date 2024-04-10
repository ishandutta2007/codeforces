#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e5+10,LN=30,SQ=550,M=1e5+10;
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
ll q,n,a[N],f[N],ans[N],g[N];
pair<pll,ll> u[N];
vector<ll> v[N],c[N];
vector<pll> b[N];
void update(ll t, ll x){
    t+=3;
    while(t<N) f[t]+=x,t+=t&-t;
}
ll get(ll t, ll x=0){
    t+=3;
    while(t) x+=f[t],t-=t&-t;
    return x;
}
int main(){
    fast_io;
    cin >> n;
    for(ll i=1; i<=n; i++){
        cin >> a[i];
        v[a[i]].push_back(i);
    }
    cin >> q;
    for(ll i=1; i<=q; i++){
        cin >> u[i].F.S >> u[i].F.F;
        u[i].S=i;
    }
    sort(u+1,u+q+1);
    for(ll i=1; i<N; i++){
        if(v[i].empty()) continue;
        ll s=1,t=0,k=v[i][0],st=v[i][0];
        c[st-1].push_back(s);
        for(ll j : v[i]){
            if(t==0){
                t=j-k;
                c[j-1].push_back(k+1);
                k=j;
                continue;
            }
            if(j-k!=t){
                b[j-1].emplace_back(s,k);
                s=k-t+1;
                st=k;
                c[st-1].push_back(s);
                c[j-1].push_back(k+1);
                t=j-k;
                k=j;
                continue;
            }
            c[j-1].push_back(k+1);
            k=j;
        }
        if(k) b[n].emplace_back(s,k);
    }
    ll j=q;
    for(ll i=N-1; i>=1; i--){
        for(pll p : b[i]) update(p.F,1),update(p.S+1,-1);
        for(ll t : c[i]) update(t,-1);
        while(j>=1 && u[j].F.F==i){
            if(get(u[j].F.S)) ans[u[j].S]--;
            j--;
        }
    }
    for(ll i=1; i<=q; i++) swap(u[i].F.F,u[i].F.S);
    sort(u+1,u+q+1);
    memset(f,0,sizeof f);
    j=1;
    for(ll i=1; i<N; i++){
        if(v[i].empty()) continue;
        g[i]++;
        update(v[i][0],1);
    }
    while(j<=q && u[j].F.F==1){
        ans[u[j].S]+=get(u[j].F.S)+1;
        j++;
    }
    for(ll i=2; i<=n; i++){
        ll x=a[i-1];
        update(i-1,-1);
        if(g[x]!=v[x].size()) update(v[x][g[x]],1),g[x]++;
        while(j<=q && u[j].F.F==i){
            ans[u[j].S]+=get(u[j].F.S)+1;
            j++;
        }
    }
    for(ll i=1; i<=q; i++) cout << ans[i] << '\n';
    return 0;
}