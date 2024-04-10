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
        int a, b, c;
        cin >> a >> b >> c;
        bool ok = false;
        ok |= a == b + c || b == c + a || c == a + b;
        ok |= b == c && (a % 2 == 0);
        ok |= c == a && (b % 2 == 0);
        ok |= a == b && (c % 2 == 0);
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}