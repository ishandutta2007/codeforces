#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using cd = complex<double>;

const int maxn = 101010;
const int maxd = 10;
const ld inf = 1e15;
int n, d;
ld dp[maxn][maxd];
int last[maxn][maxd];
int lastD[maxn][maxd];
int a[maxn];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int p = 0; p <= n; ++p)
    for (int i = 0; i < 10; ++i) {
        dp[p][i] = -inf;
    }
    dp[0][1] = 0;

    for (int i = 0; i < n; ++i) {
        for (int dig = 0; dig < 10; ++dig) {
            dp[i + 1][dig] = dp[i][dig];
            last[i + 1][dig] = 0;
            lastD[i + 1][dig] = dig;
        }
        for (int dig = 0; dig < 10; ++dig) {
            int new_dig = (dig * a[i]) % 10;
            if (dp[i + 1][new_dig] <= dp[i][dig] + logl(a[i])) {
                dp[i + 1][new_dig] = max(dp[i + 1][new_dig], dp[i][dig] + logl(a[i]));
                last[i + 1][new_dig] = 1;
                lastD[i + 1][new_dig] = dig;
            }
        }
    }

    if (dp[n][d] < 0) {
        cout << -1;
        return 0;
    }

    vector<int> ans;
    for (int i = n, dig = d; i--; ) {
        if (last[i + 1][dig]) {
            ans.push_back(a[i]);
        }
        dig = lastD[i + 1][dig];
    }
    if (ans.empty()) {
        cout << -1 << "\n";
        return 0;
    }
    cout << ans.size() << "\n";
    for (int &e : ans) {
        cout << e << " ";
    }

    return 0;
}