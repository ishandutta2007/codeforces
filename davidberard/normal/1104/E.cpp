#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int NMAX = 250250;

int N, M, K;

vector<int> edges[NMAX];
int depth[NMAX];
int par[NMAX];

vector<int> leaves;

pii maxdepth;

void dfs(int u, int p, int d) {
	maxdepth = max(maxdepth, pii(d, u));
	par[u] = p;
	depth[u] = d;
	int ch = 0;
	for(auto& v : edges[u]) {
		if(!depth[v]) {
			dfs(v, u, d+1);
			ch++;
		}
	}
	if(!ch) leaves.push_back(u);
}

int main () {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M >> K;
	for(int i=0;i<M;++i) {
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(1, 0, 1);
	if(maxdepth.first-1 > ((N+K-1)/K)) {
		vector<int> p;
		p.push_back(maxdepth.second);
		while(p.back() != 1) {
			p.push_back(par[p.back()]);
		}
		reverse(p.begin(), p.end());
		cout << "PATH" << endl;
		cout << p.size() << endl;
		for(auto& x : p) cout << x << " ";
		cout << endl;
		return 0;
	}
	
	vector<vector<int>> cycles;
	for(int i=0;i<K;++i) {
		int u = leaves[i];
		int x=0,y=0;
		for(int v : edges[u]) {
			if(depth[v] != depth[u]-1) {
				if(x == 0) x = v;
				else if(y == 0) y = v;
				else break;
			}
		}
		cycles.push_back(vector<int>());
		if(depth[y] > depth[x]) swap(x, y);
		if((depth[u]-depth[x]+1)%3 != 0) {
			cycles.back().push_back(u);
			while(cycles.back().back() != x) {
				cycles.back().push_back(par[cycles.back().back()]);
			}
		}
		else if((depth[u]-depth[y]+1)%3 != 0) {
			cycles.back().push_back(u);
			while(cycles.back().back() != y) {
				cycles.back().push_back(par[cycles.back().back()]);
			}
		} else {
			assert(depth[x] > depth[y]);
			assert((depth[x]-depth[y]+2)%3 != 0);
			cycles.back().push_back(u);
			cycles.back().push_back(x);
			while(cycles.back().back() != y) {
				cycles.back().push_back(par[cycles.back().back()]);
			}
		}
	}
	cout << "CYCLES\n";
	for(auto& v : cycles) {
		cout << v.size() << "\n";
		for(auto& x : v) cout << x << " ";
		cout << "\n";
	}
	
	return 0;
}