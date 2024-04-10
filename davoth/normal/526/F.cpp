#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=3e5+10,LN=30,SQ=550,M=1e6+10;
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
ll n,a[N],ans,lmx[N],lmn[N],rmx[N],rmn[N];
int cnt[4*N];
void solve(ll l, ll r){
    if(r-l<=1){
        ans++;
        return;
    }
    ll m=(l+r)/2;
    solve(l,m);
    solve(m,r);
    lmn[m-1]=lmx[m-1]=a[m-1];
    for(ll i=m-2; i>=l; i--){
        lmn[i]=min(a[i],lmn[i+1]);
        lmx[i]=max(a[i],lmx[i+1]);
    }
    rmx[m]=rmn[m]=a[m];
    for(ll i=m+1; i<r; i++){
        rmx[i]=max(a[i],rmx[i-1]);
        rmn[i]=min(a[i],rmn[i-1]);
    }
    ll x=m,y=m;
    for(ll i=m-1; i>=l; i--){
        ll t=lmx[i]-lmn[i]+i;
        if(t>=m && t<r && rmx[t]<lmx[i] && rmn[t]>lmn[i]) ans++;
        while(x<r && rmn[x]>lmn[i]){
            cnt[rmx[x]-x+N*2]++;
            x++;
        }
        while(y<x && rmx[y]<lmx[i]){
            cnt[rmx[y]-y+N*2]--;
            y++;
        }
        ans+=cnt[lmn[i]-i+N*2];
    }
    while(y<x){
        cnt[rmx[y]-y+N*2]--;
        y++;
    }
    x=y=m-1;
    for(ll i=m; i<r; i++){
        ll t=i-rmx[i]+rmn[i];
        if(t>=l && t<m && lmn[t]>rmn[i] && lmx[t]<rmx[i]) ans++;
        while(x>=l && lmn[x]>rmn[i]){
            cnt[lmx[x]+x+N*2]++;
            x--;
        }
        while(y>x && lmx[y]<rmx[i]){
            cnt[lmx[y]+y+N*2]--;
            y--;
        }
        ans+=cnt[rmn[i]+i+N*2];
    }
    while(y>x){
        cnt[lmx[y]+y+N*2]--;
        y--;
    }
}
int main(){
    fast_io;
    cin >> n;
    for(ll i=0; i<n; i++){
        ll x,y;
        cin >> x >> y;
        a[x-1]=y-1;
    }
    solve(0,n);
    cout << ans << '\n';
    return 0;
}