#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

const int N = 3e5+5;
vector<int> T[N];
int parent[N];
ll sz[N];

int find(int v, int p) {
	sz[v] = 1;
	parent[v] = p;
	for(int u : T[v])
		if(u != p)
			sz[v] += find(u, v);
	return sz[v];
}

int main() {	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n, a, b;
	cin >> n >> a >> b;
	for(int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		T[u].push_back(v);
		T[v].push_back(u);
	}

	find(a, -1);
	int v = b;
	while(parent[v] != a)
		v = parent[v];
	
	cout << n*(n-1) - sz[b] * (n-sz[v]) << "\n";
}