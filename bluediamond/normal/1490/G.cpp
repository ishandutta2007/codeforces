#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

const int N = (int) 2e5 + 7;
int n, q, a[N], sum[N], pre[N];

signed main() {
        ios::sync_with_stdio(0); cin.tie(0);

      //  freopen ("input", "r", stdin);

        int t;
        cin >> t;
        while (t--) {
                cin >> n >> q;
                for (int i = 1; i <= n; i++)
                        cin >> a[i];
                for (int i = 1; i <= n; i++)
                        sum[i] = sum[i - 1] + a[i];
                int mx = sum[1];
                pre[1] = mx;
                for (int i = 2; i <= n; i++)
                        mx = max(mx, sum[i]),
                        pre[i] = mx;
                while (q--) {
                        int x, ret = 0;
                        cin >> x;
                        if (sum[n] <= 0 && mx < x) {
                                cout << "-1 ";
                                continue;
                        }
                        int cnt = 0;
                        if (cnt * sum[n] + mx < x) {
                                assert(sum[n] != 0);
                                cnt = (x - mx + sum[n] - 1) / sum[n];
                        }
                        x -= cnt * sum[n];
                        int l = 1, r = n, add = -1;
                        while (l <= r) {
                                int i = (l + r) / 2;
                                if (pre[i] >= x) {
                                        add = i - 1;
                                        r = i - 1;
                                } else
                                        l = i + 1;
                        }
                        assert(add != -1);
                        ret = add;
                        cout << ret + cnt * n << " ";
                }
                cout << "\n";
        }

}