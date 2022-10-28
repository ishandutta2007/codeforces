#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); ++i)
 
vector<vector<int>> t;
vector<int> p, h;
 
void init(int v){
	for (int u : t[v]) if (u != p[v]){
		p[u] = v;
		h[u] = h[v] + 1;
		init(u);
	}
}
 
vector<int> get_path(int v, int u){
	vector<int> l, r;
	while (v != u){
		if (h[v] > h[u]){
			l.push_back(v);
			v = p[v];
		}
		else{
			r.push_back(u);
			u = p[u];
		}
	}
	l.push_back(v);
	while (!r.empty()){
		l.push_back(r.back());
		r.pop_back();
	}
	return l;
}
 
vector<vector<int>> g, tg;
 
void add_edge(int v, bool vx, int u, bool vy){
	// (val[v] == vx) -> (val[u] == vy)
	g[v * 2 + vx].push_back(u * 2 + vy);
	tg[u * 2 + vy].push_back(v * 2 + vx);
	g[u * 2 + !vy].push_back(v * 2 + !vx);
	tg[v * 2 + !vx].push_back(u * 2 + !vy);
}
 
vector<int> ord;
vector<char> used;
 
void ts(int v){
	used[v] = true;
	for (int u : g[v]) if (!used[u])
		ts(u);
	ord.push_back(v);
}
 
vector<int> clr;
int k;
 
void dfs(int v){
	clr[v] = k;
	for (int u : tg[v]) if (clr[u] == -1)
		dfs(u);
}
 
int main(){
	cin.tie(0);
	iostream::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	t.resize(n);
	p.resize(n);
	h.resize(n);
	p[0] = -1;
	forn(i, n - 1){
		int v, u;
		cin >> v >> u;
		--v, --u;
		t[v].push_back(u);
		t[u].push_back(v);
	}
	init(0);
	
	vector<vector<int>> paths(m);
	vector<string> s(m);
	
	vector<pair<char, char>> opts(n, make_pair(-1, -1));
	forn(i, m){
		int v, u;
		cin >> v >> u >> s[i];
		--v, --u;
		paths[i] = get_path(v, u);
		int k = s[i].size();
		assert(int(paths[i].size()) == k);
		forn(j, k) opts[paths[i][j]] = {s[i][j], s[i][k - j - 1]};
	}
	
	int nm = (n + m) * 2;
	g.resize(nm);
	tg.resize(nm);
	forn(i, m){
		int k = s[i].size();
		forn(j, k){
			int v = paths[i][j];
			char c = s[i][j], rc = s[i][k - j - 1];
			char d = opts[v].first, rd = opts[v].second;
			if (d != c) add_edge(v, false, n + i, true);
			if (d != rc) add_edge(v, false, n + i, false);
			if (rd != c) add_edge(v, true, n + i, true);
			if (rd != rc) add_edge(v, true, n + i, false);
		}
	}
	
	used.resize(nm);
	forn(i, nm) if (!used[i]) ts(i);
	clr.resize(nm, -1);
	reverse(ord.begin(), ord.end());
	for (int v : ord) if (clr[v] == -1){
		dfs(v);
		++k;
	}
	forn(i, nm) if (clr[i] == clr[i ^ 1]){
		cout << "NO\n";
		return 0;
	}
	
	cout << "YES\n";
	for (int i = 0; i < 2 * n; i += 2){
		if (opts[i / 2].first == -1)
			cout << 'a';
		else if (clr[i] > clr[i ^ 1])
			cout << opts[i / 2].first;
		else
			cout << opts[i / 2].second;
	}
	cout << "\n";
}