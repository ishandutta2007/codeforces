#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

void solve() {
    int N;
    string s;
    cin >> N >> s;
    assert(int(s.size()) == 2 * N);

    int ans = 0, cur = 0;

    vector<vector<int>> depth(2 * N);
    for (int i = 0; i < 2 * N; i++) {
        cur += s[i] == '(' ? +1 : -1;
        depth[s[i] == '(' ? cur : cur + 1].push_back(i);
    }

    for (int d = 1; d < 2 * N; d++) {
        if (int S = depth[d].size()) {
            ans += S / 2;
            for (int i = 1; i + 1 < S; i += 2) {
                ans -= depth[d][i + 1] - depth[d][i] == 1;
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}