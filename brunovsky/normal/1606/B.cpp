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
        int64_t k, n;
        cin >> n >> k;

        int64_t time = 0;
        int64_t a = 1, b = 1;
        while (b < n && a < k) {
            b += a;
            a += a;
            time++;
        }
        time += (n - b + k - 1) / k;
        cout << time << '\n';
    }
    return 0;
}