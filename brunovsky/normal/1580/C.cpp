#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    vector<vector<array<int, 2>>> runs(N); // alive in [L,R)
    for (int i = 0; i < M; i++) {
        int op, u;
        cin >> op >> u, u--;
        if (op == 1) {
            runs[u].push_back({i, M});
        } else {
            runs[u].back()[1] = i;
        }
    }
    debug(runs);

    const int B = 337;

    vector<int> ans(M + 1);
    vector<array<int, 4>> starting(M), ending(M);

    for (int u = 0; u < N; u++) {
        int period = X[u] + Y[u];
        for (auto [L, R] : runs[u]) {
            if (period <= B) {
                starting[L] = {period, R, X[u], Y[u]};
                if (R < M) {
                    ending[R] = {period, L, X[u], Y[u]};
                }
            } else {
                for (int i = L; i < R; i += period) {
                    ans[min(R, i + X[u])]++;
                    ans[min(R, i + X[u] + Y[u])]--;
                }
            }
        }
    }

    vector<vector<array<int, 4>>> lefts(B + 1), rights(B + 1);

    for (int L = 0; L < M; L++) {
        if (auto [period, R, x, y] = starting[L]; period) {
            lefts[period].push_back({L, R, x, y});
        }
    }
    for (int R = 0; R < M; R++) {
        if (auto [period, L, x, y] = ending[R]; period) {
            rights[period].push_back({L, R, x, y});
        }
    }

    for (int i = 1; i < M; i++) {
        ans[i] += ans[i - 1];
    }

    for (int period = 2; period <= B; period++) {
        int S = lefts[period].size(), V = rights[period].size();
        if (S == 0) {
            continue;
        }
        vector<int> delta(period);
        int maintenance = 0;
        for (int i = 0, l = 0, r = 0, id = 0; i < M; i++) {
            if (l < S && lefts[period][l][0] == i) {
                auto [L, R, x, y] = lefts[period][l++];
                int s = (L + x) % period, e = L % period;
                delta[s]++, delta[e]--;
                maintenance += 1; // cancel decrement from e below
            }
            if (r < V && rights[period][r][1] == i) {
                auto [L, R, x, y] = rights[period][r++];
                int s = (L + x) % period, e = L % period;
                delta[s]--, delta[e]++;
                // Must deactivate by hand if i lies in (s,e] mod period
                maintenance -= s < id && id <= e;
                maintenance -= e < s && (s < id || id <= e);
            }
            ans[i] += maintenance += delta[id];
            id = id + 1 < period ? id + 1 : 0;
        }
    }

    for (int i = 0; i < M; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}

// The period is X[i]+Y[i]
// If this is large,  >B, brute force
// If this is small, <=B, add it to save[X[i]][Y[i]] or something and process together?
// We want to process every period in linear time + preprocessing
// We split in blocks [0,P),[P,2P),[2P,3P),...
// Suppose we add X* at time L=L%period in current block
// Maintain a difference array as you go around as well :)