#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 1e5+5;

map<int, vector<int>> adj[N];
vector<int> ccs[N];
int num_cc = 0;

map<int, int> uf;
void uf_init() {
	uf = map<int, int>();
}

int uf_id(int u) {
	if(!uf.count(u)) return u;
	return uf[u] = uf_id(uf[u]);
}

inline void uf_merge(int u, int v) {
	u = uf_id(u), v = uf_id(v);
	if(u == v) return;
	uf[u] = v;
}

map<pair<int,int>, int> ans;

const int MAGIC = 300;

int query(int u, int v) {
	if(v < u) swap(u, v);
	pii p(u, v);
	if(ans.count(p))
		return ans[p];
	int a = 0;
	int A = max((int)ccs[u].size(), 1);
	int B = max((int)ccs[v].size(), 1);
	if(B < A) swap(A, B);
	if(A * log(B) > A + B) {
		int i = 0, j = 0;
		while(i < ccs[u].size() && j < ccs[v].size()) {
			if(ccs[u][i] == ccs[v][j]) {
				++a, ++i, ++j;
			} else if(ccs[u][i] < ccs[v][j]) {
				++i;
			} else ++j;
		}
	} else {
		if(ccs[v].size() < ccs[u].size())
			swap(u, v);
		for(int x : ccs[u]) {
			int lo = 0, hi = int(ccs[v].size())-1;
			while(lo <= hi) {
				int md = (lo+hi)/2;
				if(ccs[v][md] < x)
					lo = md+1;
				else if(ccs[v][md] > x)
					hi = md-1;
				else if(ccs[v][md] == x) {
					++a;
					break;
				}
			}
		}
	}
	return ans[p] = a;
}


int main() {
	fio;
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[c][a].push_back(b);
		adj[c][b].push_back(a);
	}

	for(int i = 1; i <= m; ++i) {
		uf_init();
		for(const auto& x : adj[i]) {
			int u = x.first;
			for(int v : x.second) {
				uf_merge(u, v);
			}
		}
		map<int, int> id_cc;
		for(const auto& x : adj[i]) {
			int u = x.first;
			int id = uf_id(u);
			if(!id_cc.count(id)) {
				id_cc[id] = ++num_cc;
			}
			ccs[u].push_back(id_cc[id]);
		}
	}
	
	for(int i = 1; i <= n; ++i) {
		sort(ccs[i].begin(), ccs[i].end());
	}

	int q;
	cin >> q;
	while(q--) {
		int u, v;
		cin >> u >> v;
		cout << query(u, v) << endl;
	}
}