#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> pp;

const int NINF = -1000000000;

int adj[1010][1010];
int deg[1010];
bool vst[1010];
int N;
vector<pp> ans;

bool calc(int u, int p, int v, int w) {
	if(u == v) return true;
	bool fd = false;

	for(int i = 1; i <= N; i++) {
		if(i == p || adj[u][i] == NINF || vst[i]) continue;
		fd |= calc(i, u, v, w);
		if(fd) {
			adj[u][i] -= w;
			adj[i][u] -= w;
			break;
		}
	}
	return fd;
}

int find_leaf(int x, int p) {
	if(deg[x] == 1) return x;
	for(int i = 1; i <= N; i++) {
		if(i == p || adj[x][i] == NINF || vst[i]) continue;
		return find_leaf(i, x);
	}
}

void dfs(int lf, int x, int p, int w) {
	if(deg[x] > 3) {
		deg[x]--;
		int l = find_leaf(x, p);
		ans.push_back({{lf, l}, w});
		calc(lf, -1, l, w);
	}
	else if(deg[x] == 3) {
		deg[x]--;
		int v1 = -1, v2 = -1;
		int l1 = -1, l2 = -1;
		int p1, p2;
		for(int i = 1; i <= N; i++) {
			if(i == p || adj[x][i] == NINF || vst[i]) continue;
			if(v1 == -1) v1 = i;
			else v2 = i;
		}
		l1 = find_leaf(v1, x); p1 = adj[x][v1];
		l2 = find_leaf(v2, x); p2 = adj[x][v2];
		//printf("%d %d %d %d %d %d\n", lf, x, l1, l2, p1, p2);
		ans.push_back({{lf, l1}, (w + p1 - p2) / 2});
		ans.push_back({{lf, l2}, (w - p1 + p2) / 2});
		calc(lf, -1, l1, (w + p1 - p2) / 2);
		calc(lf, -1, l2, (w - p1 + p2) / 2);

		if((w + p1 - p2) % 4) {
			ans.push_back({{l1, l2}, 1});
			calc(l1, -1, l2, 1);
		}
	}
	else if(deg[x] == 1 && lf != x) {
		ans.push_back({{lf, x}, w});
		return;
	}
	else {
		for(int i = 1; i <= N; i++) {
			if(i == p || adj[x][i] == NINF || vst[i]) continue;
			dfs(lf, i, x, w);
		}
		vst[x] = true;
	}
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) adj[i][j] = NINF;
	for(int i = 1; i < N; i++) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		adj[a][b] = adj[b][a] = c;
		deg[a]++; deg[b]++;
	}
	for(int i = 1; i <= N; i++) {
		if(deg[i] == 2) { puts("NO"); return 0; }
	}

	while(1) {
		bool ok = false;
		for(int i = 1; i <= N; i++) {
			if(deg[i] == 1 && !vst[i]) {
				int w = 0;
				for(int j = 1; j <= N; j++) if(adj[i][j] != NINF) w = adj[i][j];
				dfs(i, i, -1, w); ok = true; break;
			}
		}
		if(!ok) break;
	}
	puts("YES");
	printf("%d\n", ans.size());
	for(auto i : ans) printf("%d %d %d\n", i.first.first, i.first.second, i.second);

	return 0;
}