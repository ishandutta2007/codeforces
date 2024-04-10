/**
 *  created: 13/10/2021, 17:46:35
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 44, inf = 1000111;
const int max_x = 2 * inf;

int t, n, a[max_n], last[max_x], cnt[max_x];
int curt;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            a[i] += inf;
        }
        sort(a, a + n);
        const int need = (n + 1) / 2;
        for (int k = 2 * inf; k >= 1; --k) {
            ++curt;
            bool ok = 0;
            for (int i = 0; i < n; ++i) {
                const int val = a[i] % k;
                if (last[val] != curt) {
                    last[val] = curt;
                    cnt[val] = 0;
                }
                if ((++cnt[val]) >= need) {
                    ok = 1;
                    break;
                }
            }
            if (ok) {
                if (k == 2 * inf) {
                    k = -1;
                }
                cout << k << "\n";
                break;
            }
        }
    }
    return 0;
}