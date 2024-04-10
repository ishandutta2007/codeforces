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
        deque<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        vector<pair<int, int>> ops;
        vector<int> tandems;
        vector<int> b(begin(a), end(a));
        int add = 0;
        while (!a.empty()) {
            int S = a.size();
            int i = 1;
            while (i < S && a[i] != a[0]) {
                i++;
            }
            if (i == S) {
                break;
            }
            assert(i < S && a[0] == a[i]);
            for (int j = 1; j < i; j++) {
                ops.emplace_back(i + j + add, a[j]);
            }
            add += 2 * i;
            tandems.push_back(2 * i);
            a.erase(begin(a) + i);
            a.erase(begin(a));
            reverse(begin(a), begin(a) + (i - 1));
        }
#ifdef LOCAL
        for (auto [i, c] : ops) {
            assert(i <= int(b.size()));
            b.insert(begin(b) + i, c);
            b.insert(begin(b) + i, c);
        }
        debug(b);
#endif
        if (!a.empty()) {
            cout << -1 << '\n';
        } else {
            cout << ops.size() << '\n';
            for (auto [i, c] : ops) {
                cout << i << ' ' << c << '\n';
            }
            cout << tandems.size() << '\n';
            for (int i = 0, t = tandems.size(); i < t; i++) {
                cout << tandems[i] << " \n"[i + 1 == t];
            }
        }
    }
    return 0;
}