/**
 *  created: 03/06/2022, 19:16:21
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;

int n, a[max_n], b[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    if (1) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
    } else {
        n = 1000000;
        for (int i = 1; i <= n; ++i) {
            a[i] = n + i;
        }
    }
    for (int i = 0; i < n; ++i) {
        b[i] = a[i] - a[0];
    }
    for (int m = 1; ; ++m) {
        if (a[0] > 1LL * m * (m + 1)) {
            continue;
        }
        int mx = max(0LL, a[0] - 1LL * m * m), mn = m;
        int from = 0;
        for (int d = 0; from < n; ++d) {
            int to = lower_bound(b, b + n, 2 * m * (d + 1) + (d + 1) * (d + 1)) - b;
            if (from < to) {
                int val = 2 * m * d + d * d;
                int X = m + d;
                int l = from - 1, r = to;
                while (r - l > 1) {
                    int mid = (l + r) / 2;
                    if (b[mid] - val <= m + d) {
                        l = mid;
                    } else {
                        r = mid;
                    }
                }
                if (l != from - 1) {
                    mn = min(mn, m + d - (b[l] - val));
                }
                if (l + 1 < to) {
                    mx = max(2 * (m + d) + 1 - (b[l + 1] - val), mx);
                }
                //cout << d << ": " << from << " " << to << "     " << b[l] - val << " " << b[l + 1] - val << "      " << mn << " " << mx << endl;
            }
            from = to;
        }

        //cout << m << ": " << mn << " " << mx << endl;
        //return 2;
        if (mx <= mn) {
            cout << 1LL * m * m + mx - a[0] << "\n";
            return 0;
        }
    }
    return 0;
}