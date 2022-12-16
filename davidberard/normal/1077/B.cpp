#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int dp[1000][2][2];
const int INF = 0x3f3f3f3f;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;
    vector<int> a(N);
    for(auto& x : a) cin >> x;
    dp[1][0][0] = (a[0] != 0) + (a[1] != 0);
    dp[1][0][1] = (a[0] != 0) + (a[1] != 1);
    dp[1][1][0] = (a[0] != 1) + (a[1] != 0);
    dp[1][1][1] = (a[0] != 1) + (a[1] != 1);
    int best = INF;
    for(int i=2;i<N;++i)
    {
        best = INF;
        dp[i][0][0] = min(dp[i-1][0][0], dp[i-1][1][0]) + (a[i] != 0);
        dp[i][0][1] = dp[i-1][0][0] + (a[i] != 1);
        dp[i][1][0] = min(dp[i-1][0][1], dp[i-1][1][1]) + (a[i] != 0);
        dp[i][1][1] = min(dp[i-1][1][1], dp[i-1][0][1]) + (a[i] != 1);
        best = min(best, dp[i][0][0]);
        best = min(best, dp[i][0][1]);
        best = min(best, dp[i][1][0]);
        best = min(best, dp[i][1][1]);
    }
    cout << best << endl;
    return 0;
}