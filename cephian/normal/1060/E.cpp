#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

const int N = 2e5+5;
vector<int> T[N];
int n;
int sze[N];
int szo[N];
ll sdre[N];
ll sdro[N];

void ssz(int v, int p) {
	sze[v] = 1;
	szo[v] = 0;
	for(int u : T[v]) {
		if(u == p)
			continue;
		ssz(u, v);
		szo[v] += sze[u];
		sze[v] += szo[u];
	}
}

void ssdr(int v, int p) {
	sdre[v] = 0;
	sdro[v] = 0;
	for(int u : T[v]) {
		if(u == p)
			continue;
		ssdr(u, v);
		sdre[v] += sdro[u] + (szo[u]);
		sdro[v] += sdre[u] + (sze[u]);
	}
}


ll dfs(int u, int p, ll se, ll so, int ne, int no) {
	ll ans = 0;
	ans += se/2;
	ans += (so-no)/2 + no;
	ne += 1;
	for(int v : T[u]) {
		if(v == p) continue;
		ans += dfs(v, u, so + no, se + ne, no, ne);
		se += sdro[v] + szo[v];
		so += sdre[v] + sze[v];
		ne += szo[v];
		no += sze[v];
	}
	return ans;
}

int main() {
	fio;
	cin >> n;
	for(int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		T[u].push_back(v);
		T[v].push_back(u);
	}
	ssz(1, 0);
	ssdr(1, 0);
	cout << dfs(1, 0, 0, 0, 0, 0) << "\n";
}