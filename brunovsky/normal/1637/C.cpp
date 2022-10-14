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
        int M = *max_element(begin(a) + 1, end(a) - 1);
        if (M == 1) {
            cout << -1 << '\n';
        } else if (M == 0) {
            cout << 0 << '\n';
        } else if (N == 3 && M % 2 == 1) {
            cout << -1 << '\n';
        } else {
            int64_t sum = 0;
            for (int i = 1; i + 1 < N; i++) {
                sum += a[i];
                if (a[i] % 2 == 1) {
                    sum++;
                }
            }
            cout << sum / 2 << '\n';
        }
    }
    return 0;
}