#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXS 10000010
int pri[MAXS], tot, mu[MAXS], lst[MAXS];
bool npri[MAXS];
void sieve() {
	mu[1] = lst[1] = 1;
	for (int i = 2; i != MAXS; ++i) {
		if (!npri[i]) mu[pri[++tot] = i] = -1 ,lst[i] = i;
		for (int j = 1; j <= tot; ++j) {
			int t = i * pri[j];
			if (t >= MAXS) break;
			npri[t] = true; lst[t] = pri[j];
			if (i % pri[j] == 0) { mu[t] = 0; break; }
			mu[t] = -mu[i];
		}
	}
}
int n, p, K, li[2000], cnt[2000], bak, res;
void dfs(int S, int now, int x) {
	if (S == bak + 1) return (void) (res += mu[now] * (x / now));
	for (int i = 0; i <= cnt[S]; ++i, now *= li[S]) dfs(S + 1, now, x);
}
int calc(int x) {
	res = 0;
	dfs(1, 1, x);
	return res;
}
int main() {
	sieve();
	int Q; scanf("%d", &Q);
	while (Q --> 0) {
		scanf("%d%d%d", &n, &p, &K);
		bak = 0; int t = p;
		while (t != 1) {
			int ct = lst[t]; li[++bak] = ct; cnt[bak] = 0;
			while (t % ct == 0) t /= ct, ++cnt[bak];
		}
		int cnt = calc(n), l = n + 1, r = MAXS - 10, ans = -1;
		while (l <= r) {
			int mid = l + r >> 1;
			if (calc(mid) >= cnt + K) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}