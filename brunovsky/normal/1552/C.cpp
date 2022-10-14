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
        int N, K;
        cin >> N >> K;
        vector<int> mate(2 * N, -1);
        vector<pair<int, int>> edges(K);
        for (auto& [a, b] : edges) {
            cin >> a >> b, a--, b--;
            if (a > b) {
                swap(a, b);
            }
            mate[a] = b, mate[b] = a;
        }
        vector<int> unmated;
        for (int i = 0; i < 2 * N; i++) {
            if (mate[i] == -1) {
                unmated.push_back(i);
            }
        }
        for (int i = 0; i < N - K; i++) {
            int a = unmated[i];
            int b = unmated[i + (N - K)];
            edges.push_back({a, b});
            mate[a] = b, mate[b] = a;
        }
        int ans = 0;
        for (auto [a, b] : edges) {
            for (auto [c, d] : edges) {
                if (a < c) {
                    ans += (a < c && c < b) != (a < d && d < b);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}