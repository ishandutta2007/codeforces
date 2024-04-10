#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, ll> pii;

ll X[3030];
int N, M;

pii D[3030][3030];
pii tmp[3030];
vector<int> adj[3030];
int sz[3030];
ll sum[3030];

pii operator+ (const pii& a, const pii& b) {
	return {a.first + b.first, a.second + b.second};
}

void init(int v, int p) {
	for(int i : adj[v]) {
		if(i == p) continue;
		init(i, v);
		sz[v] += sz[i];
		sum[v] += sum[i];
	}
	sz[v]++;
	sum[v] += X[v];
}

void dfs(int v, int p) {
	int s = 0;

	bool ok = false;

	for(int i : adj[v]) {
		if(i == p) continue;
		dfs(i, v);

		if(!ok) {
			ok = true;
			for(int j = 0; j <= sz[i]; j++) D[v][j] = D[i][j];
			s += sz[i];
			// printf("v=%d, s=%d\n", v, s);
			// for(int j = 0; j <= s; j++) printf("(%d, %lld) ", D[v][j].first, D[v][j].second); puts("");
			continue;
		}

		for(int j = 0; j <= s + sz[i]; j++) tmp[j] = {-1010101010, 0};

		for(int j = 0; j <= s; j++) {
			for(int k = 0; k <= sz[i]; k++) { 
				tmp[j + k] = max(tmp[j + k], D[v][j] + D[i][k]);
			}
		}

		for(int j = 0; j <= s + sz[i]; j++) D[v][j] = tmp[j];
		s += sz[i];

		// printf("v=%d, s=%d\n", v, s);
		// for(int j = 0; j <= s; j++) printf("(%d, %lld) ", D[v][j].first, D[v][j].second); puts("");
	}

	D[v][0] = {0, sum[v] - X[v]};
	for(int j = s; j >= 0; j--) {
		D[v][j].second += X[v];

		if(v != 1) {
			if(D[v][j].second > 0) {
				D[v][j + 1] = max(D[v][j + 1], {D[v][j].first + 1, 0});
			}
			else {
				D[v][j + 1] = max(D[v][j + 1], {D[v][j].first, 0});
			}
		}
	}
	D[v][0] = {0, sum[v]};
}

int main() {
	int T; scanf("%d", &T);

	while(T--) {

		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) for(int j = 0; j <= N; j++) D[i][j] = {-1010101010, 0};

		for(int i = 1; i <= N; i++) scanf("%lld", &X[i]);
		for(int i = 1; i <= N; i++) {
			ll x; scanf("%lld", &x);
			X[i] = x - X[i];
		}

		for(int i = 1; i < N; i++) {
			int a, b; scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		init(1, 0);
		dfs(1, 0);
		// for(int i = 1; i <= N; i++) {
		// 	for(int j = 0; j <= N; j++) {
		// 		printf("(%d, %lld) ", D[i][j].first, D[i][j].second);
		// 	}
		// 	puts("");
		// }

		printf("%d\n", D[1][M - 1].first + (D[1][M - 1].second > 0));

		for(int i = 1; i <= N; i++) {
			adj[i].clear(); sum[i] = sz[i] = 0;
		}
	}
	return 0;
}