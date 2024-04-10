#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
using namespace std;

const int maxn = 200009;
vector<int> e[maxn];
int n, u, v, _root, root, o, tot, d[maxn], q[maxn];

int bfs(int s) {
	int l = 0, r = 0, u;
	memset(d, -1, sizeof d);
	d[s] = 0; q[r++] = s;
	while (l < r) {
		u = q[l++];
		rep (j, 0, e[u].size()-1)
			if (d[e[u][j]] == -1) {
				d[e[u][j]] = d[u] + 1;
				q[r++] = e[u][j];
			}
	}
	return u;
}

int getMid(int u, int fa, int v) {
	if (u == v) { d[u] = 0; return tot / 2 == 0; }
	int res;
	rep (i, 0, e[u].size()-1)
		if (e[u][i] != fa) {
			res = getMid(e[u][i], u, v);
			if (res == -1) continue;
			if (res) return res;
			d[u] = d[e[u][i]] + 1;
		}
	if (d[u] == tot / 2) return u;
	return d[u] == -1 ? -1 : 0;
}

int dfs(int u, int fa) {
	int tmp; set<int> s;
	rep (i, 0, e[u].size()-1)
		if (e[u][i] != fa) {
			tmp = dfs(e[u][i], u);
			if (tmp == -1) return -1;
			s.insert(tmp);
		}
	if (fa && s.size() >= 2 || !fa && s.size() >= 3) return -1;
	if (fa) return s.empty() ? 1 : *s.begin() + 1;
	int ans; 
	if (s.empty()) ans = 0; 
	else if (s.size() == 1) ans = *s.begin();
	else ans = *s.begin() + *(--s.end());
	while (!(ans&1)) ans >>= 1;
	return ans;
}

int main() {
	scanf("%d", &n);
	rep (i, 1, n-1) {
		scanf("%d%d", &u, &v);
		e[u].push_back(v); 
		e[v].push_back(u);
	}
	_root = bfs(1); root = bfs(_root); tot = d[root];
	memset(d, -1, sizeof d);
	o = getMid(_root, 0, root); 
	printf("%d\n", dfs(o, 0));
	return 0;
}