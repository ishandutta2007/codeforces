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
        long n;
        cin >> n;
        if (n % 2)
            n++;
        n = n * 5 / 2;
        n = max<long>(n, 15);
        while (n % 5)
            n++;
        cout << n << '\n';
    }
    return 0;
}