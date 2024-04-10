#include <bits/stdc++.h>

using namespace std;

int N, K;
int p[303030];
vector<int> adj[303030];

int id;
int nxt[303030];
int rt[303030];
int C[303030];
int ord[303030];
bool chk[303030];
int R;

vector<int> gph[303030];
int indeg[303030];
queue<int> q;
vector<int> ans;

void add_edge(int u, int v) {
	indeg[v]++;
	gph[u].push_back(v);
}

void top_sort() {
	for(int i = 1; i <= id; i++) if(!indeg[i]) q.push(i);
	while(q.size()) {
		int v = q.front(); q.pop();
		ans.push_back(v);
		for(int i : gph[v]) {
			indeg[i]--;
			if(!indeg[i]) q.push(i);
		}
	}
}

int main() {
	scanf("%d%d", &N, &K);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &p[i]);
		if(!p[i]) R = i;
	}

	for(int i = 1; i <= K; i++) {
		int x, y; scanf("%d%d", &x, &y);
		nxt[x] = y;
		chk[y] = true;
	}

	for(int i = 1; i <= N; i++) {
		if(chk[i]) continue;
		id++;
		rt[id] = i;
		int x = i;
		int tmp = 0;
		while(1) {
			C[x] = id;
			ord[x] = ++tmp;
			x = nxt[x];
			if(!x || C[x]) break;
		}
	}

	for(int i = 1; i <= N; i++) if(!C[i]) { puts("0"); return 0; }

	for(int i = 1; i <= N; i++) {
		if(i == R) continue;
		if(C[i] != C[p[i]]) add_edge(C[p[i]], C[i]);
		else if(ord[p[i]] > ord[i]) { puts("0"); return 0; }
	}

	top_sort();
	if(ans.size() != id) { puts("0"); return 0; }
	for(int i : ans) {
		int x = rt[i];
		while(1) {
			printf("%d ", x);
			x = nxt[x];
			if(!x || x == rt[i]) break;
		}
	}
	puts("");

	return 0;
}