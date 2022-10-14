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
    int n, a, x, b, y;
    cin >> n >> a >> x >> b >> y;
    bool yes = false;
    while (a != x && b != y) {
        a = a == n ? 1 : a + 1;
        b = b == 1 ? n : b - 1;
        yes |= a == b;
    }
    cout << (yes ? "YES\n" : "NO\n");
    return 0;
}