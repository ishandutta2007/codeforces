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
        vector<array<int, 5>> rank(N);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> rank[i][j];
            }
        }
        vector<int> candidates;
        for (int i = 0; i < N; i++) {
            candidates.push_back(i);
        }
        while (candidates.size() > 1u) {
            int u = candidates.back();
            candidates.pop_back();
            int v = candidates.back();
            candidates.pop_back();
            int a = 0, b = 0;
            for (int j = 0; j < 5; j++) {
                a += rank[u][j] < rank[v][j];
                b += rank[u][j] > rank[v][j];
            }
            if (a >= 3) {
                candidates.push_back(u);
            } else {
                candidates.push_back(v);
            }
        }
        if (candidates.empty()) {
            cout << -1 << '\n';
            continue;
        }
        int u = candidates.front();
        bool busted = false;
        for (int i = 0; i < N; i++) {
            if (u != i) {
                int a = 0;
                for (int j = 0; j < 5; j++) {
                    a += rank[u][j] < rank[i][j];
                }
                busted |= a < 3;
            }
        }
        if (busted) {
            cout << -1 << '\n';
        } else {
            cout << u + 1 << '\n';
        }
    }
    return 0;
}