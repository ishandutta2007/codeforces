#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int deg[N] = {}, n;

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for(int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		++deg[u], ++deg[v];
	}
	for(int i = 1; i <= n; ++i) {
		if(deg[i] == 2) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
}