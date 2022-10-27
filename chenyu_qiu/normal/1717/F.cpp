#include <bits/stdc++.h>
using namespace std;

namespace flow {
	const int inf = INT_MAX;
	const int NN = 40005, MM = 222222;
	int n, m, s, t, d[NN], qu[NN];
	int cnt = 1, head[NN], cur[NN], to[MM], nxt[MM], val[MM];
	inline void addedge(int u, int v, int w) {
		to[++cnt] = v;
		val[cnt] = w;
		nxt[cnt] = head[u];
		head[u] = cnt;
	}
	inline void add(int u, int v, int w) {
		addedge(u, v, w);
		addedge(v, u, 0); 
	}
	inline bool bfs() {
		int l = 1, r = 0;
		for(int i = 0; i <= n; ++i) cur[i] = head[i], d[i] = 0;
		qu[++r] = s, d[s] = 1;
		while(l <= r) {
			int u = qu[l++];
			for(int i = head[u]; i; i = nxt[i]) {
				int v = to[i], w = val[i];
				if(d[v] || !w) continue;
				d[v] = d[u] + 1;
				qu[++r] = v;
			}
		} 
		return d[t];
	}
	int dfs(int u, int flow) {
		if(u == t) return flow;
		int rest = flow;
		for(int &i = cur[u]; i; i = nxt[i]) {
			int v = to[i], w = val[i];
			if(d[v] != d[u] + 1 || !w) continue;
			int k = dfs(v, min(flow, w));
			if(!k) d[v] = 0;
			rest -= k;
			val[i] -= k, val[i ^ 1] += k; 
			if(!rest) break;
		}
		return flow - rest;
	}
	inline int dinic() {
		int res = 0;
		while(bfs()) res += dfs(s, inf); 
		return res;
	}
	int find(int u) {
		for (int i = head[u]; i; i = nxt[i]) {
			if (!val[i] && to[i]) {
				return to[i];
			}
		}
		return 0;
	}
}

const int N = 10005;
int n, m, s[N], a[N], d[N], u[N], v[N];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; ++i) {
		cin >> u[i] >> v[i];
		++d[u[i]];
		++d[v[i]];	
	}

	int cnt = 0;
	flow::n = flow::t = n + m + 1;
    for (int i = 1; i <= m; ++i) {
		flow::add(flow::s, i, 1);
		if (s[u[i]] && s[v[i]]) {
			flow::add(i, u[i] + m, 1);
			flow::add(i, v[i] + m, 1);
			++cnt;
		}
	}

	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		if (s[i]) {
			int x = a[i] + d[i];
			if (x % 2 || x < 0) {
				cout << "NO\n";
				return 0;
			}
			a[i] = x / 2;
			flow::add(i + m, flow::t, a[i]);
			sum += a[i];
		}
	}

	int res = flow::dinic();
	if (res != cnt) {
		cout << "NO\n";
		return 0;
	}

	for (int i = 1; i <= m; ++i) {
		if (!(s[u[i]] && s[v[i]])) {
			if (s[u[i]]) {
				flow::add(i, u[i] + m, 1);
			}
			if (s[v[i]]) {
				flow::add(i, v[i] + m, 1);
			}
		}
	}

	res += flow::dinic();
	if (res != sum) {
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";
	for (int i = 1; i <= m; ++i) {
		int x = flow::find(i);
		if (x > 0) {
			x -= m;
		}

		if (s[u[i]] && s[v[i]]) {
			if (x == u[i]) {
				swap(u[i], v[i]);
			}
			cout << u[i] << " " << v[i] << "\n";
		} else if (s[u[i]] && !s[v[i]]) {
			if (x) {
				swap(u[i], v[i]);
			}
			cout << u[i] << " " << v[i] << "\n";
		} else if (!s[u[i]] && s[v[i]]) {
			if (!x) {
				swap(u[i], v[i]);
			}
			cout << u[i] << " " << v[i] << "\n";
		} else {
			cout << u[i] << " " << v[i] << "\n";
		}
	}

	return 0;
}