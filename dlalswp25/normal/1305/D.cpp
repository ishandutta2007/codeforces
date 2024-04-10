#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> adj[1010];

int query(int u, int v) {
	printf("? %d %d\n", u, v);
	fflush(stdout);
	int w; scanf("%d", &w);
	return w;
}

int ans = -1;
bool chk[1010];

void f(int v, int c, bool ok) {
	// printf("%d %d %d\n",v, c, ok);
	if(chk[v]) { ans = v; return; }
	chk[v] = true;
	vector<int> tmp;
	for(int i : adj[v]) {
		if(i == c && ok) continue;
		tmp.push_back(i);
	}

	int sz = tmp.size();
	for(int i = 0; i + 1 < sz; i += 2) {
		int w = query(tmp[i], tmp[i + 1]);
		if(w == v) continue;
		else { f(w, v, true); return; }
	}

	if(sz == 1) {
		if(adj[v].size() == 1) {
			ans = query(v, c);
			return;
		}
	}

	if(sz & 1) { f(tmp.back(), v, false); return; }
	ans = v; return;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i < N; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	if(N == 2) {
		int x = query(1, 2);
		printf("! %d\n", x);
		fflush(stdout);
		return 0;
	}

	for(int i = 1; i <= N; i++) {
		if(adj[i].size() > 1) {
			f(i, 0, false);
			break;
		}
	}

	printf("! %d\n", ans);
	fflush(stdout);

	return 0;
}