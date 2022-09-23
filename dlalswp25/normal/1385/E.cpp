#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int indeg[202020];
vector<int> adj[202020];
vector<pii> ed;
int N, M;

int ord[202020];
queue<int> q;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ed.clear();
		while(q.size()) q.pop();

		scanf("%d%d", &N, &M);

		for(int i = 1; i <= N; i++) {
			indeg[i] = 0;
			adj[i].clear();
		}

		for(int i = 1; i <= M; i++) {
			int t, x, y; scanf("%d%d%d", &t, &x, &y);
			if(t == 0) ed.emplace_back(x, y);
			else {
				adj[x].push_back(y);
				indeg[y]++;
			}
		}

		for(int i = 1; i <= N; i++) if(!indeg[i]) q.push(i);

		int id = 0;
		while(q.size()) {
			int x = q.front(); q.pop();
			ord[x] = ++id;
			for(int i : adj[x]) {
				indeg[i]--;
				if(!indeg[i]) q.push(i);
			}
		}

		if(id < N) { puts("NO"); continue; }

		puts("YES");

		for(pii i : ed) {
			int x = i.first, y = i.second;
			if(ord[x] < ord[y]) adj[x].push_back(y);
			else adj[y].push_back(x);
		}

		for(int i = 1; i <= N; i++) for(int j : adj[i]) printf("%d %d\n", i, j);
	}
	return 0;
}