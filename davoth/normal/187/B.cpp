#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e5+10;
const int MOD=1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int> >, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, int mod){
    if(y==0) return 1;
    ll res=pow(x,y/2);
    return (y%2==0 ? res*res%mod : (res*res%mod)*x%mod);
}
int n,m,r;
int main() {
    fast_io;
    cin >> n >> m >> r;
    ll a[n+2][n+2][m+2];
    memset(a,63,sizeof a);
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++) cin >> a[j][k][i];
        }
    }
    for(int p=1; p<=m; p++){
        for(int k=1; k<=n; k++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    a[i][j][p]=min(a[i][k][p]+a[k][j][p],a[i][j][p]);
                }
            }
        }
    }
    ll dp[n+2][n+2][n+2];
    memset(dp,63,sizeof dp);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int p=1; p<=m; p++){
                dp[i][j][0]=min(dp[i][j][0],a[i][j][p]);
            }
        }
    }
    for(int K=1; K<=n; K++){
        for(int k=1; k<=n; k++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    dp[i][j][K]=min(dp[i][j][K],dp[i][k][K-1]+dp[k][j][0]);
                }
            }
        }
    }
    for(int i=0; i<r; i++){
        int x,y,z;
        cin >> x >> y >> z;
        z=min(z,n);
        cout << dp[x][y][z] << '\n';
    }
    return 0;
}