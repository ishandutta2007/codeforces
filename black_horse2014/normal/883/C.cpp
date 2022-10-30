#include <bits/stdc++.h>

using namespace std;
const long long INF = 1e18;
int f, T, t[3], a[3], p[3];

long long solve() {
	
	long long ret = INF;
	for (int u = 0; u <= f; u++) {
		long long c = 1LL * a[1] * (t[1] - t[0]), d = T - 1LL * f * t[0] - 1LL * u * (t[2] - t[0]);
		long long hi = (f - u) / a[1];
		if (c == 0) {
			if (d < 0) continue;
			ret = min(ret, 1LL * (u + a[2] - 1) / a[2] * p[2]);
			continue;
		}
		if (c < 0) {
			
			c = -c, d = -d;
			long long lo = (d < 0 ? 0 : (d + c - 1) / c);
			if (lo > hi) continue;
			ret = min(ret, 1LL * (u + a[2] - 1) / a[2] * p[2] + 1LL * lo * p[1]);
			continue;
		}
		if (d < 0) continue;
		ret = min(ret, 1LL * (u + a[2] - 1) / a[2] * p[2]);
	}
	return ret;
}
int main() {
	
	//freopen("in.txt", "r", stdin);
	scanf("%d%d%d", &f, &T, &t[0]);
	for (int i = 1; i <= 2; i++) scanf("%d%d%d", a + i, t + i, p + i);
	long long ans = INF;
	ans = min(ans, solve()); 
	swap(a[1], a[2]), swap(t[1], t[2]), swap(p[1], p[2]);
	ans = min(ans, solve()); 
	printf("%lld\n", ans == INF ? -1 : ans);
	return 0;
}