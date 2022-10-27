#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int t;
    // cin >> t;

    auto solve = [&]() {
        int n, t;
        cin >> n >> t;

        vector<int> a(n);
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] < t) {
                pq.push(a[i]);
            }
        }

        while (!pq.empty()) {
            int x = pq.top();
            if (x == t) {
                break;
            }
            pq.pop();
            int y = 1;
            while (y <= x) {
                if (pq.empty() || pq.top() != x) {
                    cout << "No\n";
                    return;
                }
                pq.pop();
                ++y;
            }
            pq.push(x + 1);
        }

        cout << "Yes\n";
    };

    // while (t--) {
        solve();
    // }

    return 0;
}