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
    int T;
    cin >> T;
    while (T--) {
        long n, a, b;
        cin >> n >> a >> b;
        long x = 1;
        if (a == 1 && (x % b) != (n % b)) {
            cout << "No\n";
            continue;
        }
        while (x < n && (x % b) != (n % b)) {
            x *= a;
        }
        if (x > n) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }
    return 0;
}