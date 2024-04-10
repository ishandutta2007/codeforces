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
        vector<int64_t> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        int m = min_element(begin(a), end(a)) - begin(a);
        int64_t P = 0, S = 0;
        for (int i = m - 1; i >= 0; i--) {
            a[i] -= P;
            if (a[i] >= a[i + 1]) {
                int64_t R = a[i] - a[i + 1];
                P += R, a[i] -= R;
            } else {
                int64_t R = a[i + 1] - a[i];
                S += R, a[m] -= R;
            }
        }
        for (int i = m + 1; i < N; i++) {
            a[i] -= S;
            if (a[i] >= a[i - 1]) {
                int64_t R = a[i] - a[i - 1];
                S += R, a[i] -= R;
            } else {
                int64_t R = a[i - 1] - a[i];
                P += R, a[m] -= R;
            }
        }
        int64_t M = abs(a[m]);
        debug(P, S, M);
        cout << P + S + M << '\n';
    }
    return 0;
}