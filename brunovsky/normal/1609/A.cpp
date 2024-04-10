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
        int64_t twos = 0;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            while (a[i] % 2 == 0) {
                twos++, a[i] /= 2;
            }
        }

        int64_t M = *max_element(begin(a), end(a));
        int64_t sum = accumulate(begin(a), end(a), 0);
        sum -= M;

        cout << (sum + M * (1LL << twos)) << '\n';
    }
    return 0;
}