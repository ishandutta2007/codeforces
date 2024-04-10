#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

int sum(int x) {
        if (x <= 0)
                return 0;
        return x * (x + 1) / 2;
}

signed main() {
        ios::sync_with_stdio(0); cin.tie(0);

       // freopen ("input", "r", stdin);

        int tt;
        cin >> tt;
        while (tt--) {
                int x, y;
                cin >> x >> y;
                int ret = 0;
                /// j - 1 <= x / (j + 1) =>
                /// (j - 1) * (j + 1) <= x
                int l = 1, r = x, jlim = 0;
                while (l <= r) {
                        int j = (l + r) / 2;
                        if ((j - 1) * (j + 1) <= x) {
                                jlim = j;
                                l = j + 1;
                        } else
                                r = j - 1;
                }
                jlim = min(jlim, y);
                ret += sum(jlim - 1);
                jlim++;
                jlim++;
                y++;
                y = min(y, x);
                int j = jlim;
                int steps = 0;
                while (j <= y) {
                        int c = x / j;
                        int j2 = min(y, x / c);
                       // j2 = j;
                        ret += c * (j2 - j + 1);
                        j = j2 + 1;
                        steps++;
                }
                assert(steps <= (int) 2e5);
                cout << ret << "\n";
        }
}