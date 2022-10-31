#include <bits/stdc++.h>
using namespace std;

const int N = 410000;
const int M = 20;

long long w[N], ma[N][M];
int pr[N][M], ne[N][M], num[N];
long long dp[N][M];

int find(int from, long long w) {
	int j = -1;
	if (w == 0) return from;
	for (int i = 0; i < M; i++) {
		if (ma[from][i] >= w) {
			j = i;
			break;
		}
	}
	if (j < 0) return 0;
	if (j == 0) return from;
	return find(pr[from][j - 1], w);
}

int get(int from, long long w) {
	int j = -1;
	for (int i = 0; i < M; i++) {
		if (dp[from][i] > w) {
			j = i;
			break;
		}
	}
	if (j < 0) return num[from];
	if (j == 0) return 0;
	return (1<<j-1) + get(ne[from][j - 1], w - dp[from][j - 1]);
}

int main() {

	int q, cnt = 1;
	long long last = 0;
	num[1] = 1;
	for (scanf("%d", &q); q--; ) {
		int t; long long p, q; scanf("%d%lld%lld", &t, &p, &q);
		p ^= last, q ^= last;
		if (t == 1) {
			++cnt;
			w[p] = q;
			pr[cnt][0] = p;
			for (int i = 1; i < M; i++) pr[cnt][i] = pr[pr[cnt][i - 1]][i - 1];
			ma[cnt][0] = q;
			for (int i = 1; i < M; i++) ma[cnt][i] = max(ma[cnt][i - 1], ma[pr[cnt][i - 1]][i - 1]);
			ne[cnt][0] = find(p, q);
			for (int i = 1; i < M; i++) ne[cnt][i] = ne[ne[cnt][i - 1]][i - 1];
			dp[cnt][0] = q;
			for (int i = 1; i < M; i++) dp[cnt][i] = dp[cnt][i - 1] + dp[ne[cnt][i - 1]][i - 1];
			num[cnt] = 1 + num[ne[cnt][0]];
		} else {
			int ans = get(p, q);
			printf("%d\n", ans);
			last = ans;
		}
	}
}