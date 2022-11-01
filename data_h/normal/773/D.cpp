#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 7;
const int INF = 1e9 + 7;

int cost[N][N], imp[N];
int n, visit[N];
long long f[N];

int main() {
	scanf("%d", &n);
	int mv = INF;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			scanf("%d", &cost[i][j]);
			cost[j][i] = cost[i][j];
			if (cost[i][j] < mv) {
				mv = cost[i][j];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j && cost[i][j] == mv) {
				imp[i] = true;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		f[i] = 1LL * INF * n;
		if (imp[i]) {
			f[i] = 1LL * (n - 1) * mv;
		}
	}
	if (n > 2) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i != j) {
					f[i] = min(f[i], cost[i][j] * 2LL + 1LL * (n - 3) * mv);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int who = -1;
		for (int j = 1; j <= n; j++) {
			if (visit[j]) continue;
			if (who == -1 || f[j] < f[who]) who = j;
		}
		visit[who] = 1;
		for (int j = 1; j <= n; j++) {
			if (visit[j]) continue;
			f[j] = min(f[j], f[who] + cost[who][j] - mv);
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%lld\n", f[i]);
	}
	return 0;
}