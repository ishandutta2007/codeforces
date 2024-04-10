#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

bool within(int a, int b, int c) { return a <= b && b <= c; }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;

    vector<array<int, 2>> ga(N, {-1, -1}), gb(N, {-1, -1});
    for (int i = 0; i < 2 * N; i++) {
        int u, v;
        cin >> u >> v, u--, v--, v -= N;
        ga[u][ga[u][0] != -1] = v;
        gb[v][gb[v][0] != -1] = u;
    }

    vector<vector<int>> cycles;
    vector<int8_t> visited(N);

    for (int u = 0; u < N; u++) {
        if (visited[u]) {
            continue;
        }
        int a = u;
        int b = ga[u][0];
        vector<int> cycle;
        do {
            visited[a] = true;
            cycle.push_back(a);
            cycle.push_back(b);
            a = gb[b][gb[b][0] == a];
            b = ga[a][ga[a][0] == b];
        } while (a != u);
        cycles.push_back(move(cycle));
    }

    int64_t ans = 0;

    // Start on the left, odd or even number of times
    for (auto& cycle : cycles) {
        int S = cycle.size();
        debug(cycle);

        for (int s = 0; s < S; s++) {
            int a = cycle[0], b = cycle[1], c = cycle[S - 1];
            int l = a, r = a;
            int L = b, R = b;

            int x = 0, y = N - 1;
            int X = b < c ? 0 : c + 1;
            int Y = b < c ? c - 1 : N - 1;

            for (int i = 2; i < S && !within(L, c, R); i++) {
                int64_t w = i / 2;
                if (i % 2 == 0) {
                    int u = cycle[i];
                    if (u < l) {
                        int d = l - u;
                        ans += w * d * (y - r + 1) * (L - X + 1) * (Y - R + 1);
                        l = u;
                    } else if (l < u && u < r) {
                        // no gain
                    } else if (r < u) {
                        int d = u - r;
                        ans += w * (l - x + 1) * d * (L - X + 1) * (Y - R + 1);
                        r = u;
                    } else {
                        assert(false);
                    }
                } else {
                    int v = cycle[i];
                    if (v < L) {
                        int d = min(L - v, L - X + 1);
                        ans += w * (l - x + 1) * (y - r + 1) * d * (Y - R + 1);
                        L = v;
                    } else if (L < v && v < R) {
                        // no gain
                    } else if (R < v) {
                        int d = min(v - R, Y - R + 1);
                        ans += w * (l - x + 1) * (y - r + 1) * (L - X + 1) * d;
                        R = v;
                    } else {
                        assert(false);
                    }
                }
            }

            rotate(begin(cycle), begin(cycle) + 1, end(cycle));
        }

        int l = N, r = 0;
        int L = N, R = 0;
        for (int i = 0; i < S; i++) {
            if (i % 2 == 0) {
                int u = cycle[i];
                l = min(l, u);
                r = max(r, u);
            } else {
                int v = cycle[i];
                L = min(L, v);
                R = max(R, v);
            }
        }

        int64_t w = S / 2;
        ans += w * (l + 1) * (N - r) * (L + 1) * (N - R);
    }

    cout << ans << '\n';
    return 0;
}