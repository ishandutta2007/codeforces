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
        const int LARGE = int(2e9);
        vector<vector<int>> b(N);
        for (int i = 0; i < N; i++) {
            if (a[i] % 10 == 0) {
                b[i].push_back(a[i]);
            } else if (a[i] % 10 == 5) {
                b[i].push_back(a[i]);
                b[i].push_back(a[i] + 5);
            } else {
                b[i].push_back(a[i]);
                while (a[i] % 10 != 2) {
                    a[i] += a[i] % 10;
                    b[i].push_back(a[i]);
                }
                b[i].push_back(LARGE + 10 * (a[i] % 20 < 10));
            }
        }
        vector<int> c = b[0];
        for (int i = 1; i < N; i++) {
            vector<int> d;
            set_intersection(begin(c), end(c), begin(b[i]), end(b[i]), back_inserter(d));
            swap(c, d);
        }
        cout << (c.size() ? "Yes\n" : "No\n");
    }
    return 0;
}

// period of twenty
// 1 2 4 8 16 22 24
// 1 2 4 8 6 2 4 8 6 2
// 3 6
// 5 0
// 7 4
// 9 8