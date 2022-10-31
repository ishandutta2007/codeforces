#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<vector<int>> R;

//UNTESTED
struct top_sort {
	vector<int> order; //stores the topological sort
	vector<short> seen;
	void init(int n) { G.resize(n); R.resize(n); seen.resize(n); }
	top_sort(int n) { init(n); }
	
	//add a new edge
	inline void add_edge(int u, int v) { 
		G[u].push_back(v);
		R[v].push_back(u);
	}

	bool visit(int u) {
		if(seen[u] == 2) return true;
		if(seen[u] == 1) return false;
		for(int v : G[u])
			if(!visit(v))
				return false;
		seen[u] = 2;
		order.push_back(u);
		return true;
	}
	//topologically sort
	bool sort() {
		for(int i = 0; i < (int)G.size(); ++i)
			if(!visit(i))
				return false;
		reverse(order.begin(),order.end());
		return true;
	}
};

const int N = 3e5+5;
int in_stat[N] = {};
int out_stat[N] = {};
int n, m;

void calc_stat(int* stat, const vector<int>& list, const vector<vector<int>>& G) {
	vector<int> deg(n);
	vector<int> unique_parent(n, 0);
	vector<int> parent(n);
	set<int> zeroes;
	for(int u : list) {
		zeroes.insert(u);
		for(int out : G[u]) {
			if(deg[out] == 0) {
				++unique_parent[u];
				parent[out] = u;
				zeroes.erase(out);
			} else if(deg[out] == 1) {
				--unique_parent[parent[out]];
			}
			++deg[out];
		}
		if(zeroes.size() == 1) {
			stat[u] = 0;
		} else if(zeroes.size() == 2) {
			auto it = zeroes.begin();
			if(*it == u) ++it;
			int v = *it;
			if(!unique_parent[v])
				stat[u] = 1;
			else
				stat[u] = 2;
		} else {
			stat[u] = 2;
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	top_sort ts(n);

	for(int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		ts.add_edge(--u, --v);
	}

	ts.sort();
	auto& top_order = ts.order;

	calc_stat(in_stat, top_order, R);
	reverse(top_order.begin(), top_order.end());
	calc_stat(out_stat, top_order, G);

	int ans = 0;
	for(int u = 0; u < n; ++u) {
		if(out_stat[u] + in_stat[u] < 2) {
			++ans;
		}
	}
	cout << ans << "\n";
}