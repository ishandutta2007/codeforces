#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

void setmax(int& a, int b) { a = max(a, b); }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<array<int, 2>> corners = {{0, 0}, {N - 1, 0}, {0, M - 1}, {N - 1, M - 1}};

        vector<int> dist(N + M + 2, 0);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int d = 0;
                for (auto [x, y] : corners) {
                    setmax(d, abs(i - x) + abs(y - j));
                }
                dist[d]++;
            }
        }

        vector<int> ans;
        for (int d = 0; d <= N + M + 1; d++) {
            while (dist[d]--) {
                ans.push_back(d);
            }
        }
        for (int i = 0; i < N * M; i++) {
            cout << ans[i] << " \n"[i + 1 == N * M];
        }
    }
    return 0;
}