#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

bool t0(int r, int c, int n) { return (r == 1 || r == n) && (c == 1 || c == n); }
bool t1(int r, int c, int n) { return (r == 2 || r == n - 1) && (c == 2 || c == n - 1); }

int rep(int a, int b, int c) { return (a + b + c - (a ^ b ^ c)) / 2; }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int r1, c1;
        int r2, c2;
        int r3, c3;
        int r4, c4;
        cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3 >> r4 >> c4;
        bool ok = false;
        ok |= r1 == r4 && c1 == c4;
        ok |= r2 == r4 && c2 == c4;
        ok |= r3 == r4 && c3 == c4;
        int dr = rep(r1, r2, r3);
        int dc = rep(c1, c2, c3);
        assert((r1 == dr) + (r2 == dr) + (r3 == dr) == 2);
        assert((c1 == dc) + (c2 == dc) + (c3 == dc) == 2);
        bool corner = t0(r1, c1, n) || t0(r2, c2, n) || t0(r3, c3, n);
        corner &= !t1(r1, c1, n) && !t1(r2, c2, n) && !t1(r3, c3, n);
        if (corner) {
            ok |= dr == r4 || dc == c4;
        } else {
            ok |= r1 % 2 == r4 % 2 && c1 % 2 == c4 % 2;
            ok |= r2 % 2 == r4 % 2 && c2 % 2 == c4 % 2;
            ok |= r3 % 2 == r4 % 2 && c3 % 2 == c4 % 2;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}