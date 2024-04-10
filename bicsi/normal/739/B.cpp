#include <bits/stdc++.h>

using namespace std;

#define int long long

const int kMaxN = 500005;
int Seek[kMaxN];
vector<pair<int, int>> G[kMaxN];

long long Dist[kMaxN];
int B[kMaxN], Val[kMaxN], E[kMaxN];


void DFS(int node) {
	static int timer = 0;

	B[node] = ++timer;
	Val[timer] = Dist[node] - Seek[node];
	for(auto vec : G[node]) {
		Dist[vec.first] = Dist[node] + vec.second;
		DFS(vec.first);
	}
	E[node] = timer;
}

int T[20][kMaxN];

void Build(int d, int b, int e) {
	if(b == e) {
		T[d][b] = Val[b];
	} else {
		int m = (b + e) / 2;
		Build(d + 1, b, m);
		Build(d + 1, m + 1, e);
		merge(T[d + 1] + b, T[d + 1] + m + 1, T[d + 1] + m + 1, T[d + 1] + e + 1, T[d] + b);
	}
}


int Query(int d, int b, int e, int l, int r, int val) {
	if(b >= l && e <= r) {
		return upper_bound(T[d] + b, T[d] + e + 1, val) - T[d] - b;
	}
	int m = (b + e) / 2;
	int ans = 0;
	if(m >= l) ans += Query(d + 1, b, m, l, r, val);
	if(m + 1 <= r) ans += Query(d + 1, m + 1, e, l, r, val);
	return ans;
}


int32_t main() {
	int n;
	scanf("%I64d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%I64d", &Seek[i]);
	}

	for(int i = 2; i <= n; ++i) {
		int p, c;
		scanf("%I64d %I64d", &p, &c);
		G[p].emplace_back(i, c);
	}
	DFS(1);

	Build(1, 1, n);

	for(int i = 1; i <= n; ++i) {
	printf("%I64d ", Query(1, 1, n, B[i] + 1, E[i], Dist[i]));
	}


	return 0;
}