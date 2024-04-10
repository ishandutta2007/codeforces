#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int id[10][10];
int edg[50][50];
int N, M, K, X;

int chk[50];

vector<pii> adj[202020];
vector<int> rev[202020];
int out[202020];
int ans = 0;
vector<int> v;

void f(int i) {
	if(i > K) {
		ans++;
		// for(int j : v) printf("%d ", j); puts("");
		return;
	}
	for(int j = 1; j <= i; j++) {
		int t = id[i][j];
		if(chk[t] > 0) continue;
		v.push_back(t);
		for(int k = t + 1; k <= X; k++) chk[k] += edg[t][k];
		f(i + 1);
		v.pop_back();
		for(int k = t + 1; k <= X; k++) chk[k] -= edg[t][k];
	}
}

int main() {
	int tmp = 1;
	for(int i = 1; i <= 9; i++) {
		for(int j = 1; j <= i; j++) {
			id[i][j] = tmp;
			tmp++;
		}
	}

	scanf("%d%d%d", &N, &M, &K);
	X = K * (K + 1) / 2;
	for(int i = 1; i <= M; i++) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		adj[a].emplace_back(c, b);
	}

	for(int i = 1; i <= N; i++) {
		out[i] = adj[i].size();
		sort(adj[i].begin(), adj[i].end());
	}

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= out[i]; j++) {
			int x = adj[i][j - 1].second;
			rev[x].push_back(id[out[i]][j]);
			// printf("%d %d\n", x, id[out[i]][j]);
		}
	}

	for(int i = 1; i <= N; i++) {
		sort(rev[i].begin(), rev[i].end());

		for(int j = 1; j < rev[i].size(); j++) {
			if(rev[i][j] == rev[i][j - 1]) {
				// printf("%d ban\n", rev[i][j]);
				chk[rev[i][j]] = 1010101010;
			}
		}
		rev[i].erase(unique(rev[i].begin(), rev[i].end()), rev[i].end());
	}

	for(int i = 1; i <= N; i++) {
		for(int j = 0; j < rev[i].size(); j++) {
			for(int k = j + 1; k < rev[i].size(); k++) {
				edg[rev[i][j]][rev[i][k]] = 1;
			}
		}
	}

	// for(int i = 1; i <= X; i++) {
	// 	for(int j = 1; j <= X; j++) {
	// 		printf("%d ", edg[i][j]);
	// 	}
	// 	puts("");
	// }

	f(1);
	printf("%d\n", ans);

	return 0;
}