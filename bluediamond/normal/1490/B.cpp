#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

signed main() {
        ios::sync_with_stdio(0); cin.tie(0);

        int t;
        cin >> t;
        while (t--) {
                int n;
                cin >> n;
                n /= 3;
                vector<int> f(3, 0);
                int ret = 0;
                for (int i = 1; i <= 3 * n; i++) {
                        int x;
                        cin >> x;
                        f[x % 3]++;
                }
                for (int it = 1; it <= 3; it++)
                for (int i = 0; i < 3; i++) {
                        if (f[i] > n) {
                                 ret += f[i] - n;
                                 f[(i + 1) % 3] += f[i] - n;
                                 f[i] = n;
                        }
                }
                assert(f[0] == n && f[1] == n && f[2] == n);
                cout << ret << "\n";
        }

}