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
        vector<int> a(N), b(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> b[i];
            a[i] -= b[i];
        }
        vector<int64_t> p(N + 1);
        for (int i = 1; i <= N; i++) {
            p[i] = p[i - 1] + a[i - 1];
        }
        vector<vector<array<int, 2>>> intv(N + 1);
        for (int i = 0; i < M; i++) {
            int l, r;
            cin >> l >> r, l--;
            intv[l].push_back({l, r});
            intv[r].push_back({l, r});
        }
        set<int> bad = {N};
        vector<int> bfs;
        int B = 0;
        for (int i = 0; i < N; i++) {
            if (p[i] == 0) {
                bfs.push_back(i), B++;
            } else {
                bad.insert(i);
            }
        }
        for (int b = 0; b < B; b++) {
            for (auto [l, r] : intv[bfs[b]]) {
                if (p[l] == 0 && p[r] == 0) {
                    auto lit = bad.lower_bound(l);
                    auto rit = bad.lower_bound(r);
                    for (auto it = lit; it != rit; it++) {
                        p[*it] = 0;
                        bfs.push_back(*it), B++;
                    }
                    bad.erase(lit, rit);
                }
            }
        }
        int zeros = count(begin(p), end(p), 0);
        cout << (zeros == N + 1 ? "YES\n" : "NO\n");
    }
    return 0;
}