#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e3+10;
const int MOD=1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int> >, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, int mod){
    if(y==0) return 1;
    if(y==1) return x%mod;
    ll a=y/2,b=1;
    if(y%2) b=x;
    return pow(x*x%mod,a,mod)*b%mod;
}
ll n,m,R[N],CN[N][N],q;
bitset<N> cn[N];
pll K[N],C[N];
int main() {
    fast_io;
    cin >> n >> m >> q;
    for(int i=0; i<n; i++) cin >> K[i].F >> K[i].S;
    for(int i=0; i<m; i++) cin >> R[i] >> C[i].F >> C[i].S;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            ll x1=K[i].F,x2=C[j].F,y1=K[i].S,y2=C[j].S,r=R[j];
            if(sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))<=r) cn[i][j]=1;
        }
    for(int i=0; i<n; i++) for(int j=0; j<n; j++){
        bitset<N> t=cn[i]&cn[j];
        CN[i][j]=t.count();
    }
    while(q--){
        ll a,b;
        cin >> a >> b;
        --a;--b;
        cout << cn[a].count()+cn[b].count()-CN[a][b]*2 << '\n';
    }
    return 0;
}