#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <set>
#include <cmath>
#include <map>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <sstream>


using namespace std;

typedef long long ll;

const long long inf = 2000000000000000000;

long long dp[2010][2010];

ll tabs(ll x) {
    if (x > 0)
        return x;
    else
        return -x;
}

void solve() {
    ll n, k, p;
    cin >> n >> k >> p;
    vector<int> keys(k);
    vector<int> mans(n);
    for (int i = 0; i < n; ++i) {
        cin >> mans[i];
    }
    for (int i = 0; i < k; ++i) {
        cin >> keys[i];
    }
    sort(mans.begin(), mans.end());
    sort(keys.begin(), keys.end());
    for (int i = 1; i <= n; ++i)
        for (int j= 0 ;j <= k; ++j) {
            dp[i][j] = inf;
        }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
            dp[i + 1][j + 1] = min(dp[i + 1][j + 1], max(dp[i][j], tabs(keys[j] - mans[i]) + tabs(keys[j] - p)));
        }
    }
    ll ans = inf;
    for (int i = 0; i <= k; ++i) {
        ans = min(dp[n][i], ans);
    }
    cout << ans << endl;
}


int main() {
    iostream::sync_with_stdio(false);
    cout.precision(20);
    solve();
}