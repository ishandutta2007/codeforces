#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N, M, K;
int D[202020];
int E[202020];

queue<int> q;
bool vst[202020];

vector<int> adj[202020];
vector<int> vn;

bool ok[202020];

vector<pair<int, int > > ei[202020];

pii mx[202020];
pii mx2[202020];

void bfs(int s) {
	for(int i = 1; i <= N; i++) { vst[i] = false; D[i] = 987654321; }
	while(q.size()) q.pop();

	q.push(s); D[s] = 0; vst[s] = true;
	while(q.size()) {
		int v = q.front(); q.pop();
		for(int i : adj[v]) {
			if(vst[i]) continue;
			vst[i] = true; D[i] = D[v] + 1;
			q.push(i);
		}
	}
}

int main() {
	scanf("%d%d%d", &N, &M, &K);

	for(int i = 1; i <= K; i++) {
		int x; scanf("%d", &x);
		vn.push_back(x);
		ok[x] = true;
	}

	for(int i = 1; i <= M; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	bfs(N);
	for(int i = 1; i <= N; i++) E[i] = D[i];
	bfs(1);

	for(int i : vn) {
		ei[D[i]].push_back({E[i], i});
	}
	mx[N + 1] = mx2[N + 1] = {-987654321, -987654321};
	for(int i = N; i >= 0; i--) {
		mx[i] = mx[i + 1];
		mx2[i] = mx2[i + 1];

		for(pii j : ei[i]) {
			if(j > mx[i]) {
				mx2[i] = mx[i]; mx[i] = j;
			}
			else mx2[i] = max(mx2[i], j);
		}
	}

	int l = 1, r = D[N] - 1;

	// for(int i = 0; i <= N; i++) {
	// 	printf("{%d %d}\n", mx[i].first, mx[i].second);
	// }

	while(l <= r) {
		int m = l + r >> 1;

		bool ok = false;

		for(int i : vn) {
			int d = max(0, m - E[i]);

			int mxe = mx[d].first;
			if(mx[d].second == i) mxe = mx2[d].first;

			// printf("%d %d %d %d\n", m, i, d, mxe);
			if(mxe + D[i] >= m) { ok = true; break; }
		}
		if(ok) l = m + 1;
		else r = m - 1;
	}
	printf("%d\n", r + 1);

	return 0;
}