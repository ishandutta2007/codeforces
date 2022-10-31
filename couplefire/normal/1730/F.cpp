#include <bits/stdc++.h>
using namespace std;

struct fen_tree {
    int n;
    vector<int> fen;

    fen_tree(int _n) {
        n = _n;
        fen.assign(n, 0);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += fen[r];
        return ret;
    }

    void inc(int idx) {
        for (; idx < n; idx = idx | (idx + 1))
            fen[idx]++;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n), ind(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        ind[p[i]] = i;
    }

    vector<vector<int>> dp(n + 2, vector<int>(1 << (k + 1), INT_MAX));
    fen_tree ft(n);

    auto get_inversions = [&](int i, int nxt, int mask) -> int {
        int ret = 0;
        ret += (i - 1) - ft.sum(ind[i + nxt]);
        for (int bit = 0; bit <= k; ++bit) {
            if (i + bit <= n && bit != nxt && mask & 1 << bit &&
                ind[i + bit] > ind[i + nxt]) {
                ret++;
            }
        }
        return ret;
    };

    auto do_transitions = [&](int i, int mask) -> void {
        for (int nxt = 0; nxt <= k; ++nxt) {
            if (i + nxt <= n && (mask & 1 << nxt) == 0) {
                int to_add = get_inversions(i, nxt, mask);
                int nxt_min = i, nxt_mask = mask | (1 << nxt);
                while (nxt_mask & 1) {
                    nxt_min++;
                    nxt_mask >>= 1;
                }
                dp[nxt_min][nxt_mask] =
                    min(dp[nxt_min][nxt_mask], dp[i][mask] + to_add);
            }
        }
    };

    dp[1][0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int mask = 0; mask < 1 << (k + 1); ++mask) {
            if (dp[i][mask] == INT_MAX)
                continue;
            do_transitions(i, mask);
        }
        ft.inc(ind[i]);
    }

    cout << dp[n + 1][0] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while (t--) {
        solve();
    }
}