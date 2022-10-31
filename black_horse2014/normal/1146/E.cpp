#include <bits/stdc++.h>
using namespace std;

const int N = 110000;

int ans[N], a[N], x[N];
string s[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= q; i++) cin >> s[i] >> x[i];
    int L = -1e5, R = 1e5;
    int sgn = 1;
    for (int i = q; i > 0 && L <= R; i--) {
        if (s[i][0] == '<') {
            if (x[i] <= 0) {
                while (L < x[i]) {
                    ans[R] = sgn * R;
                    L++, R--;
                }
            } else {
                while (L <= -x[i]) {
                    ans[R] = sgn * R;
                    L++, R--;
                }
                sgn *= -1;
            }
        } else {
            if (x[i] >= 0) {
                while (R > x[i]) {
                    ans[R] = -sgn * R;
                    L++, R--;
                }
            } else {
                while (R >= -x[i]) {
                    ans[R] = -sgn * R;
                    L++, R--;
                }
                sgn *= -1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] >= L && a[i] <= R) {
            printf("%d ", sgn * a[i]);
        } else {
            printf("%d ", ans[abs(a[i])]);
        }
    }
    puts("");
    return 0;
}