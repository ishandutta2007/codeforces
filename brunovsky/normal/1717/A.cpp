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
        int64_t n;
        cin >> n;
        int64_t ans = 0;
        ans += n;
        ans += n / 2;
        ans += n / 2;
        ans += n / 3;
        ans += n / 3;
        cout << ans << '\n';
    }
    return 0;
}

// xy = lg
// l/g <= 3 => xy <= 3gg  but xy=kgg so k=1,2,3
// 10 10
// 10 20
// 10 30