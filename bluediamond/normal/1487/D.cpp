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
                int n, ret = 0;
                cin >> n;
                int lo = 0, hi = (n - 3) / 2, cnt = 0;
                while (lo <= hi) {
                        int k = (lo + hi) / 2;
                        int a = 2 * k + 3;
                        if (a * a <= 2 * n - 1) {
                                cnt = k + 1;
                                lo = k + 1;
                        } else
                                hi = k - 1;
                }
                cout << cnt << "\n";
        }
}