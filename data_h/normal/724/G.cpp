#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 7;
const int LOG = 61;
const int MOD = 1e9 + 7;
const int DEBUG = false;

int n, m, father[N], visit[N];
vector<pair<int, long long>> adj[N];
long long a[N], cnt[LOG][2];
long long which[LOG];

void add(long long t) {
	for (int i = LOG - 1; i >= 0; i--) {
		if ((t ^ which[i]) < t) {
			t ^= which[i];
		}
	}
	for (int i = LOG - 1; i >= 0; i--) {
		if (t >> i & 1) {
			which[i] = t;
			break;
		}
	}
}

void dfs(int u, long long val) {
	visit[u] = 1;
	a[u] = val;
	for (int i = 0; i < LOG; i++) {
		cnt[i][val >> i & 1]++;
	}
	for (auto p : adj[u]) {
		int v = p.first;
		long long e = p.second;
		if (!visit[v]) {
			dfs(v, val ^ e);
		} else {
			long long cyc = e ^ a[u] ^ a[v];
			if (cyc != 0) {
				add(cyc);
			}
		}
	}
}

int comb2(int x) {
	return (1LL * x * (x - 1) / 2) % MOD;
}

int pivot;
long long all;

int ask(int i, int d) {
	if (all >> i & 1) {
		return (1LL << (pivot - 1)) % MOD;
	} else {
		if (d == 0) {
			return (1LL << pivot) % MOD;
		} else {
			return 0;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		long long c;
		scanf("%d %d %I64d", &u, &v, &c);
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			father[i] = 0;
			for (int j = 0; j < LOG; j++) {
				cnt[j][0] = cnt[j][1] = 0;
				which[j] = 0;
			}
			dfs(i, 0);

			pivot = all = 0;
			for (int j = 0; j < LOG; j++) {
				if (which[j] != 0) {
					pivot++;
					all |= which[j];
				}
			}

			for (int j = 0; j < LOG; j++) {
				long long bak = ans;
				ans += 1LL * (1LL << j) % MOD * ask(j, 0) % MOD * cnt[j][0] % MOD * cnt[j][1] % MOD;
				ans %= MOD;
				ans += 1LL * (1LL << j) % MOD * ask(j, 1) % MOD *
					((comb2(cnt[j][0]) + comb2(cnt[j][1])) % MOD) % MOD;
				ans %= MOD;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}