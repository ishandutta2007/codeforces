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
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }

        sort(begin(a), end(a));
        vector<int> vals, count;

        for (int i = 0; i < N; i++) {
            if (i == 0 || a[i] != a[i - 1]) {
                vals.push_back(a[i]);
                count.push_back(1);
            } else {
                count.back()++;
            }
        }

        auto get = [&](int v) {
            return lower_bound(begin(vals), end(vals), v) - begin(vals);
        };

        int V = vals.size();
        vector<vector<int>> bans(V);

        vector<vector<int>> by_count(N + 1);
        for (int v = V - 1; v >= 0; v--) {
            by_count[count[v]].push_back(v);
        }

        vector<int> counts;
        for (int n = 1; n <= N; n++) {
            if (!by_count[n].empty()) {
                counts.push_back(n);
            }
        }

        for (int i = 0; i < M; i++) {
            int x, y;
            cin >> x >> y;
            x = get(x), y = get(y);
            bans[x].push_back(y);
            bans[y].push_back(x);
        }
        for (int v = 0; v < V; v++) {
            sort(begin(bans[v]), end(bans[v]));
        }

        auto banned = [&](int x, int y) {
            int i = lower_bound(begin(bans[x]), end(bans[x]), y) - begin(bans[x]);
            int B = bans[x].size();
            return i < B && bans[x][i] == y;
        };

        long long ans = 0;
        for (int a : counts) {
            for (int x : by_count[a]) {
                for (int b : counts) {
                    for (int y : by_count[b]) {
                        if (x != y && !banned(x, y)) {
                            ans = max(ans, 1LL * (a + b) * (vals[x] + vals[y]));
                            break;
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}