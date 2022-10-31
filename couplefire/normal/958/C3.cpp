#include <bits/stdc++.h>
using namespace std;
#define INF 1000000009
pair<int, int> dp[500001][101]; int arr[500001];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k, p; cin >> n >> k >> p; int sum = 0;
    for(int i = 0; i<n; i++) cin >> arr[i+1], arr[i+1] %= p, sum += arr[i+1];
    for(int i = 0; i<=k; i++) dp[0][i] = {-INF, 0}; dp[0][0] = {0, 0};
    for(int i = 1; i<=n; i++) for(int j = 1; j<=k; j++) if(j <= i) dp[i][j] = max(make_pair(dp[i-1][j].first+((dp[i-1][j].second+arr[i])>=p), (dp[i-1][j].second+arr[i])%p), make_pair(dp[i-1][j-1].first, arr[i])); else dp[i][j] = {-INF, 0};
    cout << sum-dp[n][k].first*p<< endl;
}