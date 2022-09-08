#include <bits/stdc++.h>

using namespace std;

const int max_n = 22, inf = 1000111222;

int n, a[max_n], cost[3];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> cost[2] >> cost[1];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] = 2 - a[i];
    }
    int ans = 0;
    if (n % 2 && a[n / 2] == 0) {
        ans += min(cost[1], cost[2]);
    }
    for (int i = 0; i < n - i - 1; ++i) {
        int to = n - i - 1;
        if (a[i] && a[to]) {
            if (a[i] != a[to]) {
                cout << -1 << endl;
                return 0;
            }
            continue;
        }
        if (a[i] || a[to]) {
            ans += cost[a[i] + a[to]];
        } else {
            ans += 2 * min(cost[1], cost[2]);
        }
    }
    cout << ans << endl;
    return 0;
}