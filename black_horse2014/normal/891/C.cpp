#include <bits/stdc++.h>
using namespace std;

const int N = 550000;

vector<int> edge[N];
vector<pair<int, int> > B, query[N];
int f[N], vis[N], T, x[N], y[N], w[N], a[N];

int get(int u) {
	if (u == f[u]) return u;
	else {
		if (vis[u] != T) {
			vis[u] = T;
			B.push_back(make_pair(u, f[u]));
		}
		return f[u] = get(f[u]);
	}
}

int main() {
#ifndef ONLINE_JUDGE	
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> x[i] >> y[i] >> w[i];
		edge[w[i]].push_back(i);
	}
	int q; cin >> q;
	for (int i = 1; i <= q; i++) {
		int k; cin >> k; 
		for (int j = 1; j <= k; j++) {
			int x; cin >> x;
			query[w[x]].push_back(make_pair(i, x));
		}
	}
	for (int i = 1; i <= q; i++) a[i] = 1;
	for (int i = 1; i <= n; i++) f[i] = i;
	T++;
	bool ok = true;
	int runs = 0;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < query[i].size(); j++) {
			int e = query[i][j].second;
			get(x[e]), get(y[e]);
		}
		B.clear();
		T++;
		for (int j = 0; j < query[i].size(); j++) {
			int qid = query[i][j].first, eid = query[i][j].second;
			int u = x[eid], v = y[eid];
			int fu = get(u), fv = get(v);
			if (fu == fv) ok = false;
			else {
				if (vis[fu] != T) {
					vis[fu] = T;
					B.push_back(make_pair(fu, f[fu]));
				}
				f[fu] = fv;
			}
			if (j + 1 == query[i].size() || query[i][j].first != query[i][j + 1].first) {
				a[qid] &= ok;
				T++;
				ok = true;
				for (auto e : B) f[e.first] = e.second;
				runs += B.size();
				B.clear();
			}
		}
		for (int e : edge[i]) {
			int u = x[e], v = y[e];
			int fu = get(u), fv = get(v);
			if (fu == fv) continue;
			f[fu] = fv;
		}
	}
	for (int i = 1; i <= q; i++) printf("%s\n", a[i] ? "YES" : "NO");
	return 0;
}