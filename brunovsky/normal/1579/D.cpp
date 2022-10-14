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
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }

        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < N; i++) {
            if (a[i] > 0) {
                pq.emplace(a[i], i);
            }
        }

        vector<pair<int, int>> ans;

        while (pq.size() > 1u) {
            int i = pq.top().second;
            pq.pop();
            int j = pq.top().second;
            pq.pop();
            a[i]--, a[j]--, ans.emplace_back(i, j);
            if (a[i] > 0) {
                pq.emplace(a[i], i);
            }
            if (a[j] > 0) {
                pq.emplace(a[j], j);
            }
        }

        cout << ans.size() << '\n';
        for (auto [i, j] : ans) {
            cout << i + 1 << ' ' << j + 1 << '\n';
        }
    }
    return 0;
}