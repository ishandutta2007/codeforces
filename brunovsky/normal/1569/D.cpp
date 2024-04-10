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
        int N, M, K;
        cin >> N >> M >> K;
        vector<int> xs(N), ys(M);
        for (int i = 0; i < N; i++) {
            cin >> xs[i];
        }
        for (int j = 0; j < M; j++) {
            cin >> ys[j];
        }
        auto get_x = [&](int x) {
            auto it = prev(upper_bound(begin(xs), end(xs), x));
            return it - begin(xs);
        };
        auto get_y = [&](int y) {
            auto it = prev(upper_bound(begin(ys), end(ys), y));
            return it - begin(ys);
        };

        vector<array<int, 2>> people(K);
        vector<vector<int>> on_x(M - 1);
        vector<vector<int>> on_y(N - 1);
        for (auto& [x, y] : people) {
            cin >> x >> y;
            int i = get_x(x);
            int j = get_y(y);
            assert(x == xs[i] || y == ys[j]);
            if (x != xs[i]) {
                // on a vertical road
                on_y[i].push_back(y);
            } else if (y != ys[j]) {
                // on a horizontal road
                on_x[j].push_back(x);
            }
        }

        int64_t ans = 0;
        for (int i = 0; i < M - 1; i++) {
            sort(begin(on_x[i]), end(on_x[i]));
            int O = on_x[i].size();
            int l = 0;
            while (l < O) {
                int r = l + 1;
                while (r < O && on_x[i][l] == on_x[i][r]) {
                    r++;
                }
                int S = r - l;
                ans += 1LL * S * l;
                l = r;
            }
        }
        for (int i = 0; i < N - 1; i++) {
            sort(begin(on_y[i]), end(on_y[i]));
            int O = on_y[i].size();
            int l = 0;
            while (l < O) {
                int r = l + 1;
                while (r < O && on_y[i][l] == on_y[i][r]) {
                    r++;
                }
                int S = r - l;
                ans += 1LL * S * l;
                l = r;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}