#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    vector<vector<pair<int, int>>> ans4 = {{{0, 3}, {1, 2}},
                                           {{1, 3}, {0, 2}},
                                           {{2, 3}, {1, 0}}};

    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        if (N == 4 && K == 3) {
            cout << -1 << '\n';
            continue;
        } else if (N == 4) {
            for (auto [x, y] : ans4[K]) {
                cout << x << ' ' << y << '\n';
            }
            continue;
        }

        auto rev = [N](int i) { return i ^ (N - 1); };
        int L = __builtin_ctz(N);

        vector<pair<int, int>> ans;
        vector<bool> used(N);
        if (K > 0 && K < N - 1) {
            ans.push_back({K, N - 1});
            ans.push_back({0, rev(K)});
        } else if (K == N - 1) {
            ans.push_back({N - 1, N - 2});
            ans.push_back({1, N / 2 - 1});
            ans.push_back({N / 2, 0});
        }
        for (auto [x, y] : ans) {
            used[x] = used[y] = true;
        }
        for (int i = 0; i < N; i++) {
            if (i < rev(i) && !used[i] && !used[rev(i)]) {
                ans.push_back({i, rev(i)});
            }
        }
        assert(int(ans.size()) == N / 2);
        int got = 0;
        for (auto [x, y] : ans) {
            cout << x << ' ' << y << '\n';
            got += x & y;
        }
        debug(got, K);
    }
    return 0;
}