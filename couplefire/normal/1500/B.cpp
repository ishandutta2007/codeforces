#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e5 + 5;

int n, m, k;
int a[N], b[N];
int pos_a[2 * N], pos_b[2 * N];
int ans_a[2 * N], nxt[2 * N];
bool big_a[2 * N];

int exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

bool check(int x) {
    int duplicated = 0;
    for (int i = 0; i < n; i++) {
        if (ans_a[i] == -1) continue;
        duplicated += x / nxt[i];
        if (x % nxt[i] - 1 >= ans_a[i]) duplicated += 1;
        // cout << duplicated << " ";
    }
    // cout << endl;
    // cout << duplicated << " " << x - duplicated << endl;
    return x - duplicated >= k;
}

signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    memset(pos_b, -1, sizeof pos_b);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        pos_b[b[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        int b_i = pos_b[a[i]];
        big_a[a[i]] = (i >= b_i);

        if (pos_b[a[i]] == -1) {
            ans_a[i] = -1;
            continue;
        }

        int x0, y0, gcd_val;

        if (big_a[a[i]]) {
            int c = i - b_i;
            gcd_val = exgcd(m, -n, y0, x0);
            if (c % gcd_val != 0) {
                ans_a[i] = -1;
                nxt[i] = -1;
            } else {
                y0 *= c / gcd_val;
                int tm = n / gcd_val;
                if (tm < 0) tm *= -1;
                if (y0 > 0)
                    y0 -= (y0 / tm) * tm;
                else {
                    y0 += ((-y0 + tm - 1) / tm + 1) * tm;
                    if (y0 > 0) y0 -= (y0 / tm) * tm;
                }
                // cout << i << " " << a[i] << " " << ans << " " << tm << " " << m * y0 + b_i << endl;
                ans_a[i] = m * y0 + b_i, nxt[i] = m * tm;
                // cout << nxt[i] << endl;
            }
        } else {
            int c = b_i - i;
            gcd_val = exgcd(n, -m, x0, y0);
            if (c % gcd_val != 0) {
                ans_a[i] = -1;
                nxt[i] = -1;
            } else {
                x0 *= c / gcd_val;
                int tm = m / gcd_val;
                if (tm < 0) tm *= -1;
                if (x0 > 0)
                    x0 -= (x0 / tm) * tm;
                else {
                    x0 += ((-x0 + tm - 1) / tm + 1) * tm;
                    if (x0 > 0) x0 -= (x0 / tm) * tm;
                }
                // cout << i << " " << a[i] << " " << ans << " " << tm << " " << n * x0 + i << endl;
                ans_a[i] = n * x0 + i, nxt[i] = n * tm;
                // cout << nxt[i] << endl;
            }
        }
    }
    int l = 1, r = 2e18, md;
    for (int cs = 0; cs < 66; cs++) {
        md = (l + r) >> 1;
        if (!check(md))
            l = md + 1;
        else
            r = md;
    }
    cout << md << endl;
    return 0;
}