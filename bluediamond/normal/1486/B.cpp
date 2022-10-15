#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

const int N = 1000 + 7;
int n, x[N], y[N];

signed main() {
        ios::sync_with_stdio(0); cin.tie(0);

       /// freopen ("input", "r", stdin);

        int t;
        cin >> t;
        while (t--) {
                cin >> n;
                for (int i = 1; i <= n; i++)
                        cin >> x[i] >> y[i];
                int c1 = 0, c2 = 0;
                for (int it = 1; it <= 2; it++) {
                        int cnt = 0;
                        sort(x + 1, x + n + 1);
                        if (n & 1)
                                cnt = 1;
                        else
                                cnt = x[n / 2 + 1] - x[n / 2] + 1;
                        for (int i = 1; i <= n; i++) {
                                swap(x[i], y[i]);
                        }
                        if (it == 1)
                                c1 = cnt;
                        else
                                c2 = cnt;
                }
                cout << c1 * c2 << "\n";
        }

}