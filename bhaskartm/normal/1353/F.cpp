#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define for0(i,n) for(int i=0;i<n;++i)
#define MX 1e18
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >>n >> m;
        vector<vector<ll>> a(n, vector<ll> (m));
        for0(i,n)for0(j,m)
            cin >> a[i][j];
        ll a0 = a[0][0];
        ll ans = MX;
        for0(x,n)for0(y,m){
            ll need = a[x][y] - x - y;
            if(need>a0) continue;
            a[0][0] = need;
            vector<vector<ll>> dp(n, vector<ll> (m, MX));
            dp[0][0] = a0-need;
            for0(i,n)for0(j,m){
                ll need1 = a[0][0]+i+j;
                if(need1>a[i][j])   continue;
                if(i>0) dp[i][j] = min(dp[i][j], dp[i-1][j]+a[i][j]-need1);
                if(j>0) dp[i][j] = min(dp[i][j], dp[i][j-1]+a[i][j]-need1);
            }
            ans = min(ans, dp[n-1][m-1]);
        }
        cout << ans << '\n';
    }
}