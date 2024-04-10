#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int INF = 1e9;

int n;
vector<int> a;
vector<int> dp;

void Solve() {
    dp.assign(n + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        dp[i + 1] = min(dp[i + 1], dp[i] + 20);

        {
            int idx = lower_bound(a.begin(), a.end(), a[i] + 90) - a.begin();
            dp[idx] = min(dp[idx], dp[i] + 50);
        }

        {
            int idx = lower_bound(a.begin(), a.end(), a[i] + 1440) - a.begin();
            dp[idx] = min(dp[idx], dp[i] + 120);
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        dp[i] = min(dp[i], dp[i + 1]);
    }
    for (int i = 1; i <= n; ++i) {
        cout << dp[i] - dp[i - 1] << '\n';
    }
    cout << endl;
}

bool Read() {
    if (!(cin >> n)) {
        return false;
    }
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Read()) {
        Solve();
    }

    return 0;
}