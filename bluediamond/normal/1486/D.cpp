#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

const int N = (int) 2e5 + 7;
int n, k, v[N], a[N];

bool ok(int val) {
        for (int i = 1; i <= n; i++)
                if (a[i] >= val)
                        v[i] = v[i - 1] + 1;
                else
                        v[i] = v[i - 1] - 1;
        int mx = -(int) 1e9;
        for (int l = n; l >= 0; l--) {
                int r = l + k;
                if (r <= n)
                        mx = max(mx, v[r]);
                if (mx >= 1 + v[l])
                        return 1;
        }
        return 0;
}

signed main() {
        ios::sync_with_stdio(0); cin.tie(0);

       /// freopen ("input", "r", stdin);

        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
                cin >> a[i];
        }
        int ret = -1;
        int l = 1, r = n;
        while (l <= r) {
                int m = (l + r) / 2;
                if (ok(m)) {
                        ret = m;
                        l = m + 1;
                } else
                        r = m - 1;
        }
        assert(ret != -1);
        cout << ret << "\n";
        return 0;
        for (int i = 1; i <= n; i++) {
                cout << ok(i) << " ";
        }
        cout << "\n";

}