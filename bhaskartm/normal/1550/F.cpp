#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int INF = 1e9;

struct edge2{
	int u, w;
};

vector<vector<edge2>> g;

struct edge3{
	int v, u, w;
};

bool operator <(const edge3 &a, const edge3 &b){
	if (a.w != b.w)
		return a.w < b.w;
	if (min(a.v, a.u) != min(b.v, b.u))
		return min(a.v, a.u) < min(b.v, b.u);
	return max(a.v, a.u) < max(b.v, b.u);
}

vector<vector<int>> comps;
vector<int> p;

bool unite(int a, int b){
	a = p[a], b = p[b];
	if (a == b) return false;
	if (comps[a].size() < comps[b].size()) swap(a, b);
	for (int v : comps[b]){
		p[v] = a;
		comps[a].push_back(v);
	}
	comps[b].clear();
	return true;
}

vector<int> mn;

void dfs(int v, int p, int d){
	mn[v] = d;
	for (auto e : g[v]) if (e.u != p)
		dfs(e.u, v, max(d, e.w));
}

int main() {
	int n, q, s, d;
	scanf("%d%d%d%d", &n, &q, &s, &d);
	--s;
	vector<int> a(n);
	forn(i, n) scanf("%d", &a[i]);
	vector<int> idx(a[n - 1] + 1);
	forn(i, n) idx[a[i]] = i;
	comps.resize(n);
	p.resize(n);
	forn(i, n) comps[i] = vector<int>(1, i), p[i] = i;
	g.resize(n);
	set<int> pos(a.begin(), a.end());
	int cnt = n;
	while (cnt > 1){
		vector<edge3> es;
		for (const vector<int> &comp : comps) if (!comp.empty()){
			for (int i : comp)
				pos.erase(a[i]);
			edge3 mn = {-1, -1, INF};
			for (int i : comp){
				for (int dx : {-d, d}){
					auto it = pos.lower_bound(a[i] + dx);
					if (it != pos.end())
						mn = min(mn, {i, idx[*it], abs(abs(a[i] - *it) - d)});
					if (it != pos.begin()){
						--it;
						mn = min(mn, {i, idx[*it], abs(abs(a[i] - *it) - d)});
					}
				}
			}
			for (int i : comp)
				pos.insert(a[i]);
			assert(mn.v != -1);
			es.push_back(mn);
		}
		for (auto e : es){
			if (unite(e.v, e.u)){
				--cnt;
				g[e.v].push_back({e.u, e.w});
				g[e.u].push_back({e.v, e.w});
			}
		}
	}
	mn.resize(n);
	dfs(s, -1, 0);
	forn(_, q){
		int i, k;
		scanf("%d%d", &i, &k);
		--i;
		puts(mn[i] <= k ? "Yes" : "No");
	}
	return 0;
}