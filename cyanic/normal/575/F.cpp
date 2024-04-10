#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;

const int maxn = 10005;
int x[maxn], l[maxn], r[maxn];
long long f[2][maxn], best;
int n, cnt, start, cur;

int main() {
	scanf("%d%d", &n, &start);
	x[++cnt] = start;
	rep (i, 1, n) {
		scanf("%d%d", &l[i], &r[i]);
		x[++cnt] = l[i]; x[++cnt] = r[i];
	}
	sort(x+1, x+cnt+1); cnt = unique(x+1, x+cnt+1) - x - 1;
	rep (i, 1, n) {
		l[i] = lower_bound(x+1, x+cnt+1, l[i]) - x;
		r[i] = lower_bound(x+1, x+cnt+1, r[i]) - x;
	}
	memset(f, 0x3f, sizeof f);
	f[0][lower_bound(x+1, x+cnt+1, start)-x] = 0;
	rep (i, 1, n) {
		cur = i & 1; best = 1e18;
		memset(f[cur], 0x3f, sizeof f[cur]);
		rep (j, 1, cnt) {
			best = min(best, f[cur^1][j] - x[j]);
			f[cur][j] = min(f[cur][j], best + x[j]);
		}
		best = 1e18;
		per (j, cnt, 1) {
			best = min(best, f[cur^1][j] + x[j]);
			f[cur][j] = min(f[cur][j], best - x[j]);
		}
		rep (j, 1, l[i]-1) f[cur][j] += x[l[i]] - x[j];
		rep (j, r[i]+1, cnt) f[cur][j] += x[j] - x[r[i]];
	}
	best = 1e18;
	rep (i, 1, cnt) best = min(best, f[n&1][i]);
	printf("%I64d\n", best);
	return 0;
}