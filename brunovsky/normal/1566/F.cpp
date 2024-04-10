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
        int N, M;
        cin >> N >> M;

        vector<int> pts(N);
        for (int i = 0; i < N; i++) {
            cin >> pts[i];
        }
        sort(begin(pts), end(pts));
        pts.push_back(INT_MAX);
        auto first_point_after = [&](int i) {
            return lower_bound(begin(pts), end(pts), i) - begin(pts);
        };

        vector<array<int, 2>> all_segs;
        for (int i = 0; i < M; i++) {
            int L, R;
            cin >> L >> R;
            if (auto j = first_point_after(L); pts[j] > R) {
                all_segs.push_back({L, R});
            }
        }
        M = all_segs.size();
        if (M == 0) {
            cout << 0 << '\n';
            continue;
        }
        sort(begin(all_segs), end(all_segs), [&](auto a, auto b) {
            return make_pair(a[1], -a[0]) < make_pair(b[1], -b[0]);
        });

        vector<array<int, 2>> segs = {all_segs[0]};
        for (int k = all_segs[0][0], i = 1; i < M; i++) {
            if (k < all_segs[i][0]) {
                k = all_segs[i][0];
                segs.push_back(all_segs[i]);
            }
        }
        M = segs.size();

        vector<int> rightof(M);
        vector<array<int, 2>> range(N + 1);
        for (int i = 0, b = 0; b <= N; b++) {
            int l = i;
            while (i < M && pts[b] > segs[i][1]) {
                rightof[i++] = b;
            }
            range[b] = {l, i};
        }

        vector<vector<int64_t>> dp(N);
        for (int p = 0; p < N; p++) {
            int ls = range[p][0], ms = range[p][1], rs = range[p + 1][1];
            int L = ms - ls + 1, R = rs - ms + 1;
            vector<int64_t> ldist(L), rdist(R);

            for (int i = 0; i < ms - ls; i++) {
                ldist[i] = pts[p] - segs[i + ls][1];
            }
            for (int i = 0; i < rs - ms; i++) {
                rdist[i + 1] = segs[i + ms][0] - pts[p];
            }

            dp[p].assign(R, 0);

            if (p == 0) {
                // p must visit everything to the left of it
                for (int i = 0; i < R; i++) {
                    dp[p][i] = ldist[0] + rdist[i] + min(ldist[0], rdist[i]);
                }
            } else {
                // stay: i goes left and stays
                // back: i goes left and goes back right
                vector<int64_t> stay(L), back(L);

                for (int i = 0; i < L; i++) {
                    stay[i] = dp[p - 1][i] + ldist[i];
                    back[i] = dp[p - 1][i] + 2 * ldist[i];
                }
                for (int i = 1; i < L; i++) {
                    stay[i] = min(stay[i], stay[i - 1]);
                }
                for (int i = L - 2; i >= 0; i--) {
                    back[i] = min(back[i], back[i + 1]);
                }

                auto cost = [&](int l, int r) {
                    return min(stay[l] + 2 * rdist[r], back[l] + rdist[r]);
                };
                for (int l = L - 1, i = 0; i < R; i++) {
                    while (l > 0 && ldist[l - 1] < rdist[i]) {
                        l--;
                    }
                    dp[p][i] = cost(l, i);
                }
            }
        }

        cout << dp[N - 1].back() << '\n';
    }
    return 0;
}