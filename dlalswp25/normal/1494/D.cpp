#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
int A[505][505];
int B[1010];
int par[1010];
vector<pair<int, pii> > v;
int id;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			scanf("%d", &A[i][j]);
			if(i == j) B[i] = A[i][j];
			if(i < j) v.emplace_back(A[i][j], pii(i, j));
		}
	}

	id = N;

	sort(v.begin(), v.end());
	for(auto& i : v) {
		int x, u, v;
		x = i.first;
		tie(u, v) = i.second;
		while(par[u]) u = par[u];
		while(par[v]) v = par[v];
		if(u == v) continue;
		if(B[u] == x) {
			par[v] = u;
			continue;
		}
		if(B[v] == x) {
			par[u] = v;
			continue;
		}
		int t = ++id;
		par[u] = par[v] = t;
		B[t] = x;
	}

	printf("%d\n", id);
	for(int i = 1; i <= id; i++) printf("%d ", B[i]); puts("");
	printf("%d\n", id);
	for(int i = 1; i < id; i++) printf("%d %d\n", i, par[i]);

	return 0;
}