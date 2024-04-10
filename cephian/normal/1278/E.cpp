#include <bits/stdc++.h>
#include <ext/rope>
using namespace __gnu_cxx;
using namespace std;
typedef long long ll;

const int N = 5e5+5;
vector<int> T[N];
int sz[N];
int l[N] = {}, r[N] = {};

int dfs(int u, int p = -1) {
	sz[u] = 1;
	for(int v : T[u]) {
		if(p == v) continue;
		sz[u] += dfs(v, u);
	}
	return sz[u];
}
// coming in having started self, prev ended
void solve(int u, int p, deque<int>& ans) {
	//cout << " at " << u << " from " << p << endl;
	if(T[u].size() == 1 && p != -1) {
		ans.push_back(u);
		return;
	}
	int lg = -1;
	int lgv = -1;
	for(int v : T[u]) {
		if(v == p) continue;
		if(sz[v] > lg) {
			lg = sz[v];
			lgv = v;
		}
	}

	solve(lgv, u, ans);
	ans.push_front(u);
	ans.push_front(lgv);
	for(int v : T[u]) {
		if(v == p || v == lgv) continue;
		deque<int> ret;
		solve(v, u, ret);
		for(int x : ret)
			ans.push_back(x);
		ans.push_front(v);
	}
}


int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	if(n == 1) {
		cout << "1 2\n";
		return 0;
	}
	for(int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		T[u].push_back(v);
		T[v].push_back(u);
	}
	dfs(1, -1);
	deque<int> ans;
	solve(1, -1, ans);
	ans.push_front(1);
	int ctr = 1;
	for(int x : ans) {
		if(l[x] == 0)
			l[x] = ctr;
		else r[x] = ctr;
		++ctr;
	}
	for(int i = 1; i <= n; ++i)
		cout << l[i] << ' ' << r[i] << '\n';
}