#include <bits/stdc++.h>

using namespace std;
using piii = tuple <int, int, int>;

struct dinic{
	struct edge{
		int v, c, i;
		edge(int v, int c, int i) : v(v), c(c), i(i) {}
	};
	static const int inf = 2e9;
	vector <edge> G[20202];
	queue <int> Q;
	int L[20202], I[20202];
	int n = 0;

	void init()
	{
		int i;
		for(i = 0; i < n; i ++){
			G[i].clear();
		}
		n = 0;
	}

	void add(int u, int v, int c)
	{
		u += 2; v += 2; if(c < 0) c = inf;
		n = max({n, u + 1, v + 1});
		G[u].emplace_back(v, c, G[v].size());
		G[v].emplace_back(u, 0, G[u].size() - 1);

	}

	bool bfs()
	{
		fill(L, L + n, 0);
		L[0] = 1; Q.push(0);

		for(; !Q.empty(); ){
			int u = Q.front(); Q.pop();
			for(auto &[v, c, _]: G[u]){
				if(c && !L[v]){
					L[v] = L[u] + 1;
					Q.push(v);
				}
			}
		}

		return !!L[1];
	}

	int flow(int u, int c)
	{
		if(u == 1) return c;
		for(int &i = I[u]; i < G[u].size(); i ++){
			auto &[v, d, j] = G[u][i];
			if(d && L[u] + 1 == L[v]){
				int f = flow(v, min(c, d));
				if(f){
					d -= f; G[v][j].c += f;
					return f;
				}
			}
		}
		return 0;
	}

	int maxflow()
	{
		int s;
		for(s = 0; bfs(); ){
			fill(I, I + n, 0);
			for(int f = 1; f; s += f){
				f = flow(0, inf);
			}
		}
		return s;
	}
} D;

vector <piii> E;
int n, m;

bool check(int k)
{
	int i;
	D.init();
	for(i = 0; i <= k; i ++){
		auto [c, u, v] = E[i];
		D.add(u, n + v, -1);
	}
	for(i = 1; i <= n; i ++){
		D.add(-2, i, 1);
		D.add(n + i, -1, 1);
	}
	return D.maxflow() == n;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int i, u, v, c, s, e, t;

	cin >> n >> m;

	for(i = 0; i < m; i ++){
		cin >> u >> v >> c;
		E.emplace_back(c, u, v);
	}

	sort(E.begin(), E.end());

	for(s = 0, e = m - 1; s <= e; ){
		t = s + e >> 1;
		if(check(t)) e = t - 1;
		else s = t + 1;
	}

	if(s == m) cout << "-1\n";
	else{
		auto [c, u, v] = E[s];
		cout << c << "\n";
	}

	return 0;
}