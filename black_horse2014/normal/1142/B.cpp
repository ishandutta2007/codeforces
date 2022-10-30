#include <bits/stdc++.h>
using namespace std;

const int N = 220000;

int p[N], a[N], ans[N], seen[N], f[18][N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, q; cin >> n >> m >> q;
    for (int i = 0, x; i < n; i++) cin >> x, p[x] = i;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        a[i] = p[a[i]];
    }
    for (int i = 0; i < n; i++) seen[i] = m + 1;
    for (int i = 0; i < 18; i++) f[i][m + 1] = m + 1;
    ans[m + 1] = m + 1;
    for (int i = m; i > 0; i--) {
    	f[0][i] = seen[(a[i] + 1) % n];
        for (int j = 1; j < 18; j++) f[j][i] = f[j - 1][f[j - 1][i]];
        ans[i] = ans[i + 1];
        int cur = i;
        for (int j = 0; j < 18; j++) if ((n - 1) >> j & 1) cur = f[j][cur];
        ans[i] = min(ans[i], cur);
        seen[a[i]] = i;
    }
    while (q--) {
        int l, r; cin >> l >> r;
        putchar((ans[l] <= r) + '0');
    }
    puts("");
	return 0;
}