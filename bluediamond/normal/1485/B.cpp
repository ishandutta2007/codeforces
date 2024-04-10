#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

const int N = (int) 1e5 + 7;
int n, q, k, a[N], s[N];

int f(int l, int r) {
        return s[r] - s[l - 1];
}

signed main() {
        ios::sync_with_stdio(0); cin.tie(0);

        cin >> n >> q >> k;
        for (int i = 1; i <= n; i++) {
                cin >> a[i];
                s[i] = s[i - 1] + a[i];
        }
        while (q--) {
                int l, r, ret = 0;
                cin >> l >> r;
                l++;
                r--;
                if (l <= r) {
                        ret += f(l + 1, r + 1);
                        ret -= f(l - 1, r - 1);
                        ret -= (r - l + 1);
                }
                l--;
                r++;
                for (int j = l; j <= r; j += r - l) {
                        int mn, mx;
                        if (j == r)
                                mx = k;
                        else
                                mx = a[j + 1] - 1;
                        if (j == l)
                                mn = 1;
                        else
                                mn = a[j - 1] + 1;
                        ret += mx - mn + 1;
                        if (j == r)
                                break;
                }
                ret -= (r - l + 1);
                cout << ret << "\n";
        }
}