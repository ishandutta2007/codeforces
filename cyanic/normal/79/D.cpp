#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
#define _rep(i,a,b) for (int i=(a); i>=int(b); i--)
using namespace std;

const int maxn = 10009, maxK = 25, maxm = 109;
int val[maxn], d[maxK][maxn], f[1<<20], s[maxK], a[maxm], q[maxn];
int n, K, m, cnt, x, r;

int main() {
	scanf("%d%d%d", &n, &K, &m);
	rep (i, 1, K) scanf("%d", &x), val[x] = 1;
	rep (i, 1, m) scanf("%d", &a[i]);
	_rep (i, n + 1, 1) val[i] ^= val[i-1];
	rep (i, 1, n + 1) val[i] && (s[++cnt] = i);
	rep (i, 1, cnt) {
		memset(d[i], 0x3f, sizeof d[i]);
		d[i][s[i]] = 0; q[r = 1] = s[i];
		rep (l, 1, r) {
			x = q[l];
			rep (k, 1, m) {
				if (x + a[k] <= n + 1 && d[i][x] + 1 < d[i][x+a[k]]) 
					d[i][x+a[k]] = d[i][x] + 1, q[++r] = x + a[k];
				if (x - a[k] >= 1 && d[i][x] + 1 < d[i][x-a[k]])
					d[i][x-a[k]] = d[i][x] + 1, q[++r] = x - a[k];
			}
		}
	}
	memset(f, 0x3f, sizeof f); f[0] = 0;
	rep (i, 0, (1 << cnt) - 2)
		rep (j, 0, cnt - 1) if (!(i >> j & 1))
			rep (k, j + 1, cnt - 1) if (!(i >> k & 1))
				f[i | (1 << j) | (1 << k)] = min(f[i | (1 << j) | (1 << k)], f[i] + d[j+1][s[k+1]]);
	printf("%d\n", f[(1 << cnt) - 1] <= 1e9 ? f[(1 << cnt)-1] : -1);
	return 0;
}