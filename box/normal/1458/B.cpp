#include <bits/stdc++.h>
using namespace std;
#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, (a))
#define rep1(i, a) iter(i, 1, (a)+1)
 
int a[105]; double b[105];
double dp[105][10005];
 
pair<int,int> v[105];
int main() {
    ios_base::sync_with_stdio(false); 
	cin.tie(0);
	int n; cin >> n;
    rep(i, n+1) rep(j, 10003) dp[i][j] = -1e18;
    dp[0][0] = 0;
    double tv = 0;
    rep(i, n) {
        cin >> v[i].second >> v[i].first;
        tv += v[i].first;
        for(int j=n; j>=1; j--) iter(k, v[i].second, 10003) dp[j][k] = max(dp[j][k], dp[j-1][k-v[i].second]+v[i].first);
    }
    rep1(k, n) {
        double ans = 0;
        rep(i, 10003) ans = max(ans, min(1.0*i, (tv+dp[k][i])/2));
        cout << fixed << setprecision(10) << ans << " \n"[k==n];
    }
    return 0;
}