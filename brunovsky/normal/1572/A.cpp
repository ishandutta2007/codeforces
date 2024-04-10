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
        vector<vector<int>> out(N);
        vector<int> indeg(N);
        for (int i = 0; i < N; i++) {
            cin >> indeg[i];
            for (int j = 0; j < indeg[i]; j++) {
                int u;
                cin >> u, u--;
                out[u].push_back(i);
            }
        }
        int last = -1;
        int loops = 1;
        set<int> can_read;
        for (int i = 0; i < N; i++) {
            if (indeg[i] == 0) {
                can_read.insert(i);
            }
        }
        int total = 0;
        while (!can_read.empty()) {
            auto it = can_read.lower_bound(last);
            if (it == can_read.end()) {
                last = -1;
                loops++;
                it = can_read.begin();
            }
            int u = *it;
            can_read.erase(it);
            total++;
            last = u;
            for (int v : out[u]) {
                if (--indeg[v] == 0) {
                    can_read.insert(v);
                }
            }
        }
        if (total == N) {
            cout << loops << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}