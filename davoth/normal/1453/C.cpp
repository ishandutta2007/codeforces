#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e3+10,LN=20,SQ=550,M=5e4+10;
const ll INF=1e18;
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
ll n,q,a[N],b[N],l[10][2][N],r[10][2][N],ans[10],L[10][2],R[10][2];
int main(){
    fast_io;
    cin >> q;
    while(q--){
        cin >> n;
        for(ll i=0; i<10; i++) ans[i]=0;
        memset(l,31,sizeof l);
        memset(L,31,sizeof L);
        memset(r,-1,sizeof r);
        memset(R,-1,sizeof R);
        for(ll i=0; i<n; i++){
            for(ll j=0; j<n; j++){
                char c;
                ll x;
                cin >> c;
                x=c-'0';
                r[x][0][i]=max(j,r[x][0][i]);
                l[x][0][i]=min(j,l[x][0][i]);
                r[x][1][j]=max(i,r[x][1][j]);
                l[x][1][j]=min(i,l[x][1][j]);
                R[x][0]=max(R[x][0],j);
                R[x][1]=max(R[x][1],i);
                L[x][0]=min(L[x][0],j);
                L[x][1]=min(L[x][1],i);
            }
        }
        for(ll i=0; i<10; i++){
            for(ll k=0; k<n; k++){
                ans[i]=max({max(0ll,r[i][0][k]-l[i][0][k])*max(k,n-k-1),max({n-1-l[i][0][k],r[i][0][k],0ll})*max({R[i][1]-k,k-L[i][1],0ll}),ans[i]});
                ans[i]=max({max(0ll,r[i][1][k]-l[i][1][k])*max(k,n-k-1),max({n-1-l[i][1][k],r[i][1][k],0ll})*max({R[i][0]-k,k-L[i][0],0ll}),ans[i]});
            }
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}