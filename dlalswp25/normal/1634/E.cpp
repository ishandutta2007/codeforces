#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int M, N;
vector<int> A[202020];
vector<int> ans[202020];
map<int, int> mp;
bool chk[202020];
pii X[202020];
pii Y[202020];

vector<int> adj[202020];

void chkX(int i) {
	ans[X[i].first][X[i].second] = 1;
}
void chkY(int i) {
	ans[Y[i].first][Y[i].second] = 1;
}

void dfs(int v) {
	for(int i : adj[v]) {
		if(chk[i]) continue;
		chk[i] = true;
		if(v == X[i].first) {
			chkY(i);
			dfs(Y[i].first);
		}
		else {
			chkX(i);
			dfs(X[i].first);
		}
	}
}

int main() {
	scanf("%d", &M);
	int id = 0;
	int tot = 0;
	for(int i = 1; i <= M; i++) {
		int N; scanf("%d", &N);
		A[i].resize(N + 1);
		ans[i].resize(N + 1);
		for(int j = 1; j <= N; j++) {
			int a; scanf("%d", &a);
			if(!mp[a]) {
				mp[a] = ++id; a = mp[a];
				X[a] = {i, j};
			}
			else {
				int t = mp[a]; mp[a] = 0; a = t;
				Y[a] = {i, j};
			}
			A[i][j] = a;
		}
		tot += N;
	}

	if(id != tot / 2) { puts("NO"); return 0; }

	puts("YES");
	for(int i = 1; i <= id; i++) {
		if(X[i].first == Y[i].first) {
			chkY(i);
			continue;
		}
		adj[X[i].first].push_back(i);
		adj[Y[i].first].push_back(i);
	}
	for(int i = 1; i <= id; i++) dfs(i);
	for(int i = 1; i <= M; i++) {
		for(int j = 1; j < ans[i].size(); j++) {
			if(!ans[i][j]) printf("L");
			else printf("R");
		}
		puts("");
	}
	return 0;
}