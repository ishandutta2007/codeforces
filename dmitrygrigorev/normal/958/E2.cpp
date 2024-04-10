#include <bits/stdc++.h>
#define int long long
using namespace std;
int INF = 1e18;
signed main() {
    int k, n;
    cin >> k >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    vector<int> p(n-1);
    for (int i=0; i < n-1; i++) p[i] = v[i+1] - v[i];
    vector<pair<int, int> > x;
    for (int i=0; i < n-1; i++) x.push_back(make_pair(p[i], i));
    sort(x.begin(), x.end());
    int val = min((int) 20000, n-1);
    while (x.size() > val) x.pop_back();
    for (int i=0; i < x.size(); i++) swap(x[i].first, x[i].second);
    sort(x.begin(), x.end());
    int dp[k+1][2];
    for (int i=0; i <= k; i++) for (int j=0; j< 2; j++) dp[i][j] = INF;
    dp[0][0] = 0;
    dp[1][1] = x[0].second;
    for (int i=1; i < x.size(); i++){
        int dp2[k+1][2];
        for (int q=0; q <= k; q++) for (int j=0; j< 2; j++) dp2[q][j] = INF;
        for (int q=0; q <= k; q++){
            dp2[q][0] = min(dp2[q][0], dp[q][0]);
            dp2[q][0] = min(dp2[q][0], dp[q][1]);
            if (q > 0) dp2[q][1] = min(dp2[q][1], dp[q-1][0] + x[i].second);
            if (q > 0) if (x[i].first - x[i-1].first > 1) dp2[q][1] = min(dp2[q][1], dp[q-1][1] + x[i].second);
        }
        for (int q=0; q <= k; q++) for (int j=0; j< 2; j++) dp[q][j] = dp2[q][j];
    }
    cout << min(dp[k][0], dp[k][1]) << endl;
    return 0;
}