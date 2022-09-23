#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int dist[3030][3030];
ll D[3030][3030];
vector<int> adj[3030];
int z[3030];
int sz[3030][3030];
int sp[15][3030];

void init(int r, int v, int p) {
	if(p) dist[r][v] = dist[r][p] + 1;
	if(r == 1) { z[v] = 1; sp[0][v] = p; }
	for(int i : adj[v]) {
		if(i == p) continue;
		init(r, i, v);
		if(r == 1) z[v] += z[i];
	}
}

ll f(int i, int j) {
	if(D[i][j] != -1) return D[i][j];
	if(i == j) return D[i][j] = 0;
	ll& ret = D[i][j];

	bool ok = false;
	for(int k : adj[j]) {
		if(dist[i][k] < dist[i][j]) continue;
		ok = true;
		ret = max(ret, sz[i][j] * sz[k][i] + f(i, k));
	}

	for(int k : adj[i]) {
		if(dist[k][j] < dist[i][j]) continue;
		ok = true;
		ret = max(ret, sz[j][i] * sz[k][j] + f(k, j));
	}
	if(!ok) return D[i][j] = 0;
	return ret;
}

int up(int v, int u) {
	for(int i = 12; i >= 0; i--) {
		if(sp[i][v] == 0 || z[sp[i][v]] >= z[u]) continue;
		v = sp[i][v];
	}
	return v;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i < N; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for(int i = 1; i <= N; i++) init(i, i, 0);
	for(int i = 1; i <= 12; i++) for(int j = 1; j <= N; j++) sp[i][j] = sp[i - 1][sp[i - 1][j]];

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if(i == j) continue;
			if(dist[1][i] + dist[i][j] == dist[1][j]) {
				int t = up(j, i);
				sz[i][j] = N - z[t];
				sz[j][i] = z[j];
			}
			else if(dist[1][j] + dist[i][j] == dist[1][i]) {
				int t = up(i, j);
				sz[j][i] = N - z[t];
				sz[i][j] = z[i];
			}
			else {
				sz[i][j] = z[i];
				sz[j][i] = z[j];
			}
		}
	}

	for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) D[i][j] = -1;

	// for(int i = 1; i <= N; i++) {
	// 	for(int j = 1; j <= N; j++) {
	// 		printf("%d ", sz[i][j]);
	// 	}
	// 	puts("");
	// }

	ll ans = 0;
	for(int i = 1; i <= N; i++) {
		for(int j : adj[i]) ans = max(ans, sz[i][j] * sz[j][i] + f(i, j));
	}

	printf("%lld\n", ans);

	return 0;
}