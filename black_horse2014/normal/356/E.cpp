#include <cstdio>
#include <cstring>
#include <cmath>
#define MX 110000
#define P 10007LL
#define rep(i, y) for (int i = 1; i <= y; i++)

using namespace std;

int n, a[MX], L;
int s[MX][30];
long long val[MX], bit[30];
long long f[MX], g[MX];
long long sum, ans, tans;
bool chk[MX][30];

inline int calc(int st, int en, int u) {
	return s[en][u] - s[st - 1][u];
}

inline long long get(int st, int en) {
	return f[en] - f[st - 1] * g[en - st + 1];
}

void init() {
	char tp[MX];
	int mid, en;
	scanf("%s", tp + 1);
	n = strlen(tp + 1), L = int(log2(n)) + 1;
	
	g[0] = 1LL, bit[0] = 1LL;
	rep(i, L) bit[i] = bit[i - 1] * 2;
	rep(i, n) a[i] = tp[i] - 'a' + 1;
	rep(i, n) f[i] = f[i - 1] * P + a[i], g[i] = g[i - 1] * P;
	rep(i, n) rep(j, 26)
		s[i][j] = s[i - 1][j] + (a[i] == j);
	
	rep(k, L) {
		rep (i, n) {
			mid = i + bit[k - 1] - 1;
			en = i + bit[k] - 2;
			if (en > n) break;
			if (k == 1 || (calc(i, en, a[mid]) == 1 && chk[i][k - 1] && get(i, mid - 1) == get(mid + 1, en))) {
				long long t = 1LL * (bit[k] - 1) * (bit[k] - 1);
				val[i] += t, val[en + 1] -= t;
				sum += t, chk[i][k] = true;
			}
		}
	}
	rep(i, n) val[i] += val[i - 1];
}

void dfs(int st, int en, long long hash) {
	int len = en - st + 1;
	tans += (long long)len * len;
	
	int mid = st - 1, l = mid - len, r = en;
	if (l > 0 && !calc(l, mid - 1, a[mid]) && get(l, mid - 1) == hash)
		dfs(l, r, get(l, mid) * g[len] + hash);
	
	mid = en + 1, l = st, r = mid + len;
	if (r <= n && !calc(mid + 1, r, a[mid]) && get(mid + 1, r) == hash)
		dfs(l, r, hash * g[len + 1] + get(mid, r));
	
}

void find() {
	ans = sum;
	rep(i, n) {
		rep(j, 26) {
			tans = sum - val[i];
			
			rep(k, L) {
				int st = i - bit[k - 1] + 1, en = i + bit[k - 1] - 1;
				if (st < 1 || en > n) break;
				if (k == 1 || (chk[st][k - 1] && calc(st, i - 1, j) == 0 && get(st, i - 1) == get(i + 1, en)))
					dfs(st, en, get(st, i - 1) * g[bit[k - 1]] + j * g[bit[k - 1] - 1] + get(i + 1, en));
				else break;
			}
			if (ans < tans) ans = tans;
		}
	}
}

main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	init();
	find();
	printf("%I64d\n", ans);
}