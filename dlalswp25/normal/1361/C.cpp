#include <bits/stdc++.h>

using namespace std;

int A[505050];
int B[505050];

int indeg[1050505];
multiset<pair<int, int> > adj[1050505];
vector<int> path;
int N;

vector<int> ans;

vector<int> chk[1050505];

void dfs(int v) {
	while(adj[v].size()) {
		int w = adj[v].begin() -> first;
		int id = adj[v].begin() -> second;

		adj[w].erase(adj[w].find({v, id}));
		adj[v].erase(adj[v].begin());
		dfs(w);

		path.push_back(id);
	}
}

void solve(int b) {
	int x = 1 << b;
	for(int i = 2; i <= N; i++) {
		int a = A[i] % x, b = B[i] % x;
		adj[a].insert({b, i});
		adj[b].insert({a, i});
	}

	dfs(B[1] % x);

	reverse(path.begin(), path.end());

	ans.push_back(1);
	ans.push_back(2);

	int bef = B[1] % x;

	for(int i : path) {
		int a = 2 * i - 1, b = 2 * i;
		if(A[i] % x == bef) {
			ans.push_back(a);
			ans.push_back(b);
			bef = B[i] % x;
		}
		else {
			ans.push_back(b);
			ans.push_back(a);
			bef = A[i] % x;
		}
	}
}

bool vst[1050505];

void dfs2(int v) {
	vst[v] = true;
	for(int i : chk[v]) if(!vst[i]) dfs2(i);
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d%d", &A[i], &B[i]);
	}

	for(int i = 20; i >= 0; i--) {
		int x = 1 << i;
		for(int j = 1; j <= N; j++) {
			indeg[A[j] % x]++;
			indeg[B[j] % x]++;

			int a = A[j] % x, b = B[j] % x;
			chk[a].push_back(b);
			chk[b].push_back(a);
		}

		for(int j = 0; j < x; j++) {
			if(indeg[j]) {
				dfs2(j);
				break;
			}
		}

		bool ok = true;
		for(int j = 0; j < x; j++) {
			if(indeg[j] & 1) ok = false;
			if(indeg[j] && !vst[j]) ok = false;
		}

		if(ok) {
			printf("%d\n", i);
			solve(i);
			break;
		}

		for(int j = 0; j < x; j++) {
			indeg[j] = vst[j] = 0;
			chk[j].clear();
		}
	}

	for(int i : ans) printf("%d ", i); puts("");

	return 0;
}