#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MX 30005
#define ML 505
#define MD 250

int ans, n, d, val[ML][MX], p[MX], cnt[MX];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	
	int i, j, l;
	scanf("%d%d", &n, &d);
	for (i = 1; i <= n; i++) scanf("%d", &p[i]), cnt[p[i]]++;
	memset(val, -1, sizeof val);
	ans = val[MD][d] = cnt[d];
	for (i = d; i <= p[n]; i++) {
		for (j = 0; j < ML; j++) if (val[j][i] != -1) {
			l = j - MD + d;
			if (l <= 0) continue;
			if (i + l + 1 <= p[n] && j + 1 < ML) {
				val[j + 1][i + l + 1] = max(val[j + 1][i + l + 1], val[j][i] + cnt[i + l + 1]);
				ans = max(ans, val[j + 1][i + l + 1]);
			}
			if (i + l <= p[n]) {
				val[j][i + l] = max(val[j][i + l], val[j][i] + cnt[i + l]);
				ans = max(ans, val[j][i + l]);
			}
			if (l >= 2 && j && i + l - 1 <= p[n]) {
				val[j - 1][i + l - 1] = max(val[j - 1][i + l - 1], val[j][i] + cnt[i + l - 1]);
				ans = max(ans, val[j - 1][i + l - 1]);
			}
		}
	}
	printf("%d\n", ans);
}