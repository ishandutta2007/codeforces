#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#pragma GCC optimize("O2")
/*#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e6+10,LN=20,M=1e3+10,SQ=600,inf=1e9;
const ll INF=1e18;
const int MH=1000696969,MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,m,q,fl[N],c[N],p[7]={2,3,5,7,11,13,17},a[N],b[N],d[M][M],ans[M][M];
vector<ll> f[N];
void dfs(ll t, ll w, ll x, ll y, ll l1, ll l2){
    if(!a[x]) a[x]=++n;
    if(!b[y]) b[y]=++m;
    if(d[a[x]][b[y]]<=w){
        return;
    }
    if(t==7){
        d[a[x]][b[y]]=w;
        return;
    }
    for(ll i=0; i<=l1; i++){
        if(x<=1e6){
            for(ll j=0; j<=l2; j++){
                if(w+abs(i-j)<=10){
                    dfs(t+1,w+abs(i-j),x,y*(j+1),i,j);
                }
            }
            x*=p[t];
        }
    }
}
int main(){
    fast_io;
    for(ll i=2; i<=1e6; i++){
        if(fl[i]) continue;
        for(ll j=i; j<=1e6; j+=i){
            fl[j]=1;
            ll t=j,k=0;
            while(t%i==0){
                t/=i;
                k++;
            }
            f[j].pb(k);
        }
    }
    for(ll i=1; i<=1e6; i++){
        sort(f[i].begin(),f[i].end(),greater<ll>());
        c[i]=1;
        for(ll j=0; j<f[i].size(); j++){
            c[i]*=pow(p[j],f[i][j],INF);
        }
    }
    memset(d,63,sizeof d);
    dfs(0,0,1,1,20,20);
    cin >> q;
    while(q--){
        ll x,y;
        cin >> x >> y;
        x=a[c[x]];
        y=a[c[y]];
        if(x>y) swap(x,y);
        if(x==y || ans[x][y]){
            cout << ans[x][y] << '\n';
            continue;
        }
        ans[x][y]=30;
        for(ll i=1; i<=m; i++){
            ans[x][y]=min(ans[x][y],d[x][i]+d[y][i]);
        }
        cout << ans[x][y] << '\n';
    }
    return 0;
}