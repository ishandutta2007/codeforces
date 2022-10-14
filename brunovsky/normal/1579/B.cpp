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

        vector<pair<int, int>> ans;
        for (int i = 0; i < N; i++) {
            int j = min_element(begin(a) + i, end(a)) - begin(a);
            if (i != j) {
                ans.emplace_back(i, j);
                rotate(begin(a) + i, begin(a) + j, begin(a) + j + 1);
            }
        }

        cout << ans.size() << '\n';
        for (auto [i, j] : ans) {
            cout << i + 1 << ' ' << j + 1 << ' ' << j - i << '\n';
        }
    }
    return 0;
}