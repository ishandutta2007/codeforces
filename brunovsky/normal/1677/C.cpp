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
        cin >> N;
        vector<int> a(N), b(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i], a[i]--;
        }
        for (int i = 0; i < N; i++) {
            cin >> b[i], b[i]--;
        }
        vector<int> ain(N), bin(N);
        for (int i = 0; i < N; i++) {
            ain[a[i]] = i;
            bin[b[i]] = i;
        }
        vector<vector<int>> loops;
        vector<bool> vis(N);
        for (int s = 0; s < N; s++) {
            if (vis[s]) {
                continue;
            }
            vector<int> loop = {s};
            int t = s;
            while (b[t] != a[s]) {
                loop.push_back(t = ain[b[t]]);
            }
            for (int i : loop) {
                vis[i] = true;
            }
            loops.push_back(move(loop));
        }
        sort(begin(loops), end(loops),
             [&](const auto& x, const auto& y) { return x.size() > y.size(); });
        while (!loops.empty() && loops.back().size() == 1u) {
            loops.pop_back();
        }
        vector<int> value(N);
        int l = 1, r = N;
        for (const auto& loop : loops) {
            int S = loop.size() / 2 * 2;
            for (int i = 0; i < S; i++) {
                value[a[loop[i]]] = i % 2 == 0 ? l++ : r--;
            }
        }
        for (const auto& loop : loops) {
            if (int S = loop.size(); S % 2 == 1) {
                value[a[loop[S - 1]]] = l++;
            }
        }
        int64_t ans = 0;
        for (int i = 0; i < N; i++) {
            ans += abs(value[a[i]] - value[b[i]]);
        }
        cout << ans << '\n';
    }
    return 0;
}