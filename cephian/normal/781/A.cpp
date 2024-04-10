#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int N = 2*1e5 + 5;
vector<int> G[N];
int l[N];
int big = 1;
void label(int v, int p, int from) {
	big = max(big, l[v]);
	int lab = 0;
	for(auto u : G[v]) {
		if(u == from) continue;
		++lab;
		while(lab == l[v] || lab == p) ++lab;
		l[u] = lab;
		label(u, l[v], v);
	}
}

int main() {
	ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
	int n;
	cin >> n;
	map<int,int> deg;
	for(int i = 1; i < n; ++i) {
		int u,v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	l[1] = 1;
	label(1, 0, -1);
	cout << big << "\n";
	for(int i = 1; i <= n; ++i) {
		cout << l[i] << " ";
	}
	cout << "\n";
}