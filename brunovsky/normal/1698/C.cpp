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
        for (int64_t i = 0; i < N; i++) {
            cin >> a[i];
        }
        sort(begin(a), end(a));
        set<int64_t> nums(begin(a), end(a));
        bool ok = true;
        if (N == 3) {
            ok &= nums.count(a[0] + a[1] + a[2]) > 0;
        } else if (N == 4) {
            int64_t S = a[0] + a[1] + a[2] + a[3];
            for (int x : {0, 1, 2, 3}) {
                ok &= nums.count(S - a[x]) > 0;
            }
        } else {
            ok &= a[1] == 0 && a[N - 2] == 0 && nums.count(a[0] + a[N - 1]) > 0;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}

// -1 0 0 0 +1 works