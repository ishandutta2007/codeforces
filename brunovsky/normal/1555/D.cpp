#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    string s;
    cin >> s;
    assert(int(s.size()) == N);

    vector<string> want = {"abc", "acb", "bac", "bca", "cab", "cba"};
    vector<array<int, 6>> cost(N + 1);

    debug(s);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 6; j++) {
            cost[i + 1][j] = s[i] != want[j][i % 3];
        }
    }
    vector<array<int, 6>> prefix(N + 1);
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 6; j++) {
            prefix[i][j] = prefix[i - 1][j] + cost[i][j];
        }
    }

    auto get = [&](int i, int l, int r) {
        return (l > r) ? 0 : prefix[r][i] - prefix[l - 1][i];
    };

    for (int q = 0; q < Q; q++) {
        int l, r;
        cin >> l >> r;
        int ans = INT_MAX;
        for (int j = 0; j < 6; j++) {
            ans = min(ans, get(j, l, r));
        }
        cout << ans << '\n';
    }
    return 0;
}