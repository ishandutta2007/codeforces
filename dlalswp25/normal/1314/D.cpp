#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> v;
int N, K;

int adj[90][90];
pii E[90][90][3];
ll ans = 1010101010;

void upd(int u, int v, pii x) {
	for(int j = 0; j < 3; j++) {
		if(E[u][v][j] > x) {
			for(int k = 2; k >= j + 1; k--) E[u][v][k] = E[u][v][k - 1];
			E[u][v][j] = x;
			break;
		}
	}
}

ll dist(int a, int b) {
	for(int i = 0; i < 3; i++) {
		bool ok = true;
		for(int j : v) {
			if(E[a][b][i].second == j) ok = false;
		}
		if(ok) return E[a][b][i].first;
	}
	return 1010101010;
}

bool chk[5];

void g(int cnt, int bef, ll sum) {
	// printf("%d %d %lld\n", cnt, bef, sum);
	if(cnt == K / 2 - 1) {
		ans = min(ans, sum + dist(bef, 1));
		return;
	}
	for(int i = 0; i < K / 2 - 1; i++) {
		if(chk[i]) continue;
		chk[i] = true;
		g(cnt + 1, v[i], sum + dist(bef, v[i]));
		chk[i] = false;
	}
}

void f(int n, int k) {
	if(2 * (k + 1) == K) {
		g(0, 1, 0);
		// for(int i : v) printf("%d ", i); puts("");
		// printf("%lld\n", ans);
		return;
	}
	for(int i = n; i <= N; i++) {
		v.push_back(i);
		f(i, k + 1);
		v.pop_back();
	}
}

int main() {
	scanf("%d%d", &N, &K);
	for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) scanf("%d", &adj[i][j]);

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			for(int k = 0; k < 3; k++) E[i][j][k] = {1010101010, 0};
			for(int k = 2; k <= N; k++) {
				if(k == i || k == j) continue;
				upd(i, j, {adj[i][k] + adj[k][j], k});
			}
		}
	}

	f(1, 0);
	printf("%lld\n", ans);
	return 0;
}