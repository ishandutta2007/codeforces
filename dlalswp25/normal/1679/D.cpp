#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int INF = 1000000000;

int N, M;
ll K;

int A[202020];
vector<int> adj[202020];
int U[202020];
int V[202020];
int D[202020];
int indeg[202020];

bool solve(int x) {
	for(int i = 1; i <= N; i++) {
		adj[i].clear();
		indeg[i] = 0;
	}
	for(int i = 1; i <= M; i++) {
		if(A[U[i]] <= x && A[V[i]] <= x) {
			adj[U[i]].push_back(V[i]);
			indeg[V[i]]++;
		}
	}

	queue<int> q;
	for(int i = 1; i <= N; i++) {
		if(A[i] > x) continue;
		if(!indeg[i]) q.push(i);
	}
	vector<int> v;
	while(q.size()) {
		int x = q.front(); q.pop();
		v.push_back(x);
		for(int i : adj[x]) {
			indeg[i]--;
			if(!indeg[i]) q.push(i);
		}
	}
	for(int i = 1; i <= N; i++) if(indeg[i]) return true;
	if(!v.size()) return false;

	reverse(v.begin(), v.end());
	int mx = 0;
	for(int i : v) {
		int t = 0;
		for(int j : adj[i]) t = max(t, D[j]);
		D[i] = t + 1;
		mx = max(mx, D[i]);
	}
	return mx >= K;
}

int main() {
	scanf("%d%d%lld", &N, &M, &K);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for(int i = 1; i <= M; i++) scanf("%d%d", &U[i], &V[i]);
	int l = 1, r = INF;
	while(l <= r) {
		int m = l + r >> 1;
		if(solve(m)) r = m - 1;
		else l = m + 1;
	}
	printf("%d\n", l > INF ? -1 : l);
	return 0;
}