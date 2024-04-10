#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

// Score is [length - runs]
// All distinct except two adjacent positions

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
        vector<int> pos;
        for (int i = 0; i + 1 < N; i++) {
            if (a[i] == a[i + 1]) {
                pos.push_back(i);
            }
        }
        if (pos.size() <= 1u) {
            cout << 0 << '\n';
            continue;
        }
        int x = pos.front();
        int y = pos.back();
        int S = pos.size();
        int ops = y - x - 1;
        ops += y == x + 1;
        cout << ops << '\n';
    }
    return 0;
}