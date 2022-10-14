#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    if (is_sorted(begin(a), end(a))) {
        cout << 0 << '\n';
        return 0;
    }

    int L = 0, R = M;
    while (L + 2 < R) {
        int k = (L + R) / 2;

        vector<int> b = a;
        b.push_back(M - 1);

        bool success = true;
        for (int i = N - 1; i >= 0 && success; i--) {
            if (b[i] <= b[i + 1]) {
                // do not wrap around
                b[i] = min(b[i + 1], b[i] + k);
            } else {
                // need to wrap around
                int need = M - b[i];
                if (need > k) {
                    success = false;
                } else {
                    b[i] = (b[i] + k) % M;
                    b[i] = min(b[i], b[i + 1]);
                }
            }
        }

        if (success) {
            R = k + 1;
        } else {
            L = k;
        }
    }

    int ans = (L + R) / 2;
    cout << ans << '\n';
    return 0;
}