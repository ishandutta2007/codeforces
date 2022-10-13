#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, l; cin >> n >> l;

    vector<long long> costs(31);
    for (int i = 0; i <= 30; ++i) {
        if (i < n)
            cin >> costs[i];
        else costs[i] = 1e18;
    }

    for (int it = 0; it < 100; ++it) {
        for (int i = 29; i >= 0; --i)
            costs[i] = min(costs[i], costs[i + 1]);
        for (int i = 1; i <= 30; ++i) {
            costs[i] = min(costs[i], 2 * costs[i - 1]);
        }
    }

    long long ans = 1e18;
    long long pref = 0;
    for (int bit = 30; bit >= 0; --bit) {
        if (l & (1 << bit)) pref += costs[bit];
        ans = min(ans, pref + costs[bit]);
    }
    ans = min(ans, pref);

    cout << ans << endl;
    return 0;
}