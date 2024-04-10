#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        string s;
        cin >> N >> s;
        vector<vector<int>> by_sum(2 * N + 1);
        by_sum[N].push_back(-1);
        int sum = N;
        for (int i = 0; i < N; i++) {
            sum += s[i] == 'a' ? +1 : -1;
            by_sum[sum].push_back(i);
        }
        bool ok = false;
        for (int i = 0; i <= 2 * N; i++) {
            if (by_sum[i].size() > 1u) {
                int l = by_sum[i][0];
                int r = by_sum[i][1];
                l += 2, r += 1;
                cout << l << ' ' << r << '\n';
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << -1 << ' ' << -1 << '\n';
        }
    }
    return 0;
}