#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e3+10,LN=20,SQ=550,M=5e4+10;
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
ll n,q,a[3],b[3],k;
char c[N][N];
int main(){
    fast_io;
    cin >> q;
    while(q--){
        cin >> n;
        k=b[0]=b[1]=b[2]=a[0]=a[1]=a[2]=0;
        for(ll i=0; i<n; i++){
            for(ll j=0; j<n; j++){
                cin >> c[i][j];
                if(c[i][j]=='X') a[(i+j)%3]++;
                if(c[i][j]=='O') b[(i+j)%3]++;
                if(c[i][j]!='.') k++;
            }
        }
        ll t1,t2;
        for(ll i=0; i<3; i++){
            for(ll j=0; j<3; j++){
                if(i==j) continue;
                if((b[i]+a[j])*3<=k) t1=i,t2=j;
                //cout << i << ' ' << j << ' ' << b[i] << 
            }
        }
        for(ll i=0; i<n; i++) for(ll j=0; j<n; j++){
            if((i+j)%3==t1 && c[i][j]=='O') c[i][j]='X';
            if((i+j)%3==t2 && c[i][j]=='X') c[i][j]='O';
        }
        for(ll i=0; i<n; i++){
            for(ll j=0; j<n; j++) cout << c[i][j];
            cout << '\n';
        }
    }
    return 0;
}