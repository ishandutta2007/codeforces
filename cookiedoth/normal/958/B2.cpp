/*
   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="
*/

#include <bits/stdc++.h>
#define ll long long
#define null NULL

using namespace std;

const ll MOD = 1e9 + 7;

const int mx = 3e5;
int n, d[mx], ch[mx], h[mx], root, ans[mx];
set<pair<int, int> > s;
vector<int> g[mx];

void dfs(int v, int pv, int cur_h) {
	h[v] = cur_h;
	if (g[v].size() == 1 && pv != -1) {
		d[v] = 0;
		ch[v] = -1;
		return;
	}
	int best = -1;
	for (auto v1 : g[v]) {
		if (v1 != pv) {
			dfs(v1, v, cur_h + 1);
			if (best == -1 || d[v1] > d[best])
				best = v1;
		}
	}
	d[v] = d[best] + 1;
	ch[v] = best;
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if (n == 2) {
		cout << 1 << " " << 2 << endl;
	}
	for (int i = 0; i < n; ++i) {
		if (g[i].size() > 1) {
			root = i;
			break;
		}
	}
	dfs(root, -1, 0);
	root = 0;
	for (int i = 1; i < n; ++i) {
		if (h[i] > h[root])
			root = i;
	}
	dfs(root, -1, 0);
	for (int i = 0; i < n; ++i) {
		s.insert({d[i], i});
	}
	ans[1] = 1;
	int cur = 0;
	for (int i = 2; i <= n; ++i) {
		if (s.empty()) {
			ans[i] = n;
			continue;
		}
		auto it = s.end();
		it--;
		int v = it->second;
		cur += (d[v] + 1);
		while (v != -1) {
			s.erase({d[v], v});
			v = ch[v];
		}
		ans[i] = cur;
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;
}