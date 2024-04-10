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
        sort(begin(a), end(a));
        auto dead = [&](int k) {
            int i = N - 1, t = 0;
            while (k > 0) {
                while (i >= t && a[i] > k) {
                    i--;
                }
                if (i < t) {
                    return true;
                }
                t++, i--, k--;
            }
            return false;
        };
        int L = 0, R = N + 1;
        while (L + 1 < R) {
            int M = (L + R) / 2;
            dead(M) ? R = M : L = M;
        }
        cout << L << '\n';
    }
    return 0;
}