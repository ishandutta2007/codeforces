#include <bits/stdc++.h>

using namespace std;

vector<int> P[101010];
vector<int> adj[1010101];
int N;

int D[1010101];
int par[1010101];

queue<int> q;
vector<int> tmp;
int ans;

void bfs(int s) {
	D[s] = 1;
	q.push(s);

	while(q.size()) {
		int x = q.front(); q.pop();
		tmp.push_back(x);
		for(int i : adj[x]) {
			if(par[x] == i) continue;
			if(D[i]) ans = min(ans, D[i] + D[x] - 1);
			else {
				D[i] = D[x] + 1;
				par[i] = x;
				q.push(i);
			}
		}
	}

	for(int i : tmp) D[i] = par[i] = 0;
	tmp.clear();
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		int a; scanf("%d", &a);
		for(int j = 2; j * j <= a; j++) {
			int c = 0;
			while(a % j == 0) {
				c++; a /= j;
			}
			if(c & 1) P[i].push_back(j);
		}

		if(a > 1) P[i].push_back(a);

		if(P[i].size() == 0) { puts("1"); return 0; }
		if(P[i].size() == 1) P[i].push_back(1);
		tmp.push_back(P[i][0] * P[i][1]);
	}

	sort(tmp.begin(), tmp.end());
	for(int i = 1; i < N; i++) if(tmp[i] == tmp[i - 1]) { puts("2"); return 0; }

	for(int i = 1; i <= N; i++) {
		adj[P[i][0]].push_back(P[i][1]);
		adj[P[i][1]].push_back(P[i][0]);
	}

	tmp.clear();

	ans = N + 1;
	for(int i = 1; i <= 1000; i++) {
		if(adj[i].size()) bfs(i);
	}

	if(ans > N) puts("-1");
	else printf("%d\n", ans);

	return 0;
}