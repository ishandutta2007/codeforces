#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> adj[505050];
bool vst[505050];
int p[505050];
int mx, mxv;

vector<int> vs[505050];
vector<pair<int, int> > ans;

void dfs(int v, int d) {
	vs[d].push_back(v);

	if(mx < d) { mx = d; mxv = v; }
	vst[v] = true;
	for(int i : adj[v]) {
		if(vst[i]) continue;
		p[i] = v;
		dfs(i, d + 1);
	}
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		for(int i = 1; i <= mx; i++) vs[i].clear();

		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) adj[i].clear();
		for(int i = 1; i <= M; i++) {
			int a, b; scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		for(int i = 1; i <= N; i++) vst[i] = false;

		mx = 0;
		dfs(1, 1);

		if(mx >= (N + 1) / 2) {
			puts("PATH");
			printf("%d\n", mx);
			while(1) {
				printf("%d ", mxv);
				if(mxv == 1) break;
				mxv = p[mxv];
			}
			puts("");

			continue;
		}

		ans.clear();
		puts("PAIRING");
		for(int i = 2; i <= mx; i++) {
			for(int j = 0; j < vs[i].size(); j += 2) {
				if(j + 1 >= vs[i].size()) break;
				ans.emplace_back(vs[i][j], vs[i][j + 1]);
			}
		}
		printf("%d\n", ans.size());
		for(auto i : ans) printf("%d %d\n", i.first, i.second);
	}

	return 0;
}