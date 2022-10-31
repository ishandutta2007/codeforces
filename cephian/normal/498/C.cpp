#include <bits/stdc++.h>
//
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

template <class X>
struct dinic {
	struct edge {
		int u, v;
		X cap, flow;
		edge() {}
		edge(int u, int v, X cap): u(u), v(v), cap(cap), flow(0) {}
	};

	int N;
	vector<edge> E;
	vector<vector<int>> g;
	vector<int> d, pt;

	dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}

	void add_edge(int u, int v, X cap) {
		if (u == v) return;
		g[u].emplace_back(E.size());
		E.emplace_back(edge(u, v, cap));
		g[v].emplace_back(E.size());
		E.emplace_back(edge(v, u, 0));
	}

	bool bfs(int S, int T) {
		fill(d.begin(), d.end(), N + 1);
		int qf=0,qb=1;
		d[S] = 0;
		pt[0] = S;
		while(qf!=qb) {
			int u = pt[qf++];
			if(u == T) break;
			for(int k: g[u]) {
				edge &e = E[k];
				if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
					d[e.v] = d[e.u] + 1;
					pt[qb++] = e.v;
				}
			}
		}
		return d[T] != N + 1;
	}

	X dfs(int u, int T, X flow = -1) {
		if(u == T || !flow) return flow;
		for(int &i = pt[u]; i < (int)g[u].size(); ++i) {
			edge &e = E[g[u][i]];
			edge &oe = E[g[u][i]^1];
			if(d[e.v] == d[e.u] + 1) {
				X amt = e.cap - e.flow;
				if(flow != -1 && amt > flow) amt = flow;
				if(X pushed = dfs(e.v, T, amt)) {
					e.flow += pushed;
					oe.flow -= pushed;
					return pushed;
				}
			}
		}
		return 0;
	}

	X flow(int S, int T) {
		X tot = 0;
		while(bfs(S, T)) {
			// if using fp arithmetic, limit this to N passes explicitly
			fill(pt.begin(), pt.end(), 0);
			while(X flow = dfs(S, T))
				tot += flow;
		}
		return tot;
	}
};
map<int,int> factor(int n) {
	map<int,int> ans;
	for(int i = 2; i*i <= n; ++i) {
		int pw = 0;
		while(n%i == 0) {
			++pw;
			n /=i;
		}
		if(pw)
			ans[i] = pw;
	}
	if(n != 1)
		ans[n] = 1;
	return ans;
}

vector<map<int,int>> A, B;
vector<int> before_a, before_b;


int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n, m;
	cin >> n >> m;
	int flow_left = 0,  flow_right = 0;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if(i%2 == 0) {
			A.push_back(factor(a));
			flow_left += A.back().size();
		} else {
			B.push_back(factor(a));
			flow_right += B.back().size();
		}
	}

	dinic<ll> d(2 + flow_left + flow_right);
	before_a.push_back(0);
	for(int i = 0; i < (int)A.size(); ++i) {
		before_a.push_back(before_a.back());
		for(auto& x : A[i]) {
			d.add_edge(0, ++before_a.back(), x.second);
		}
	}

	before_b.push_back(flow_left);
	for(int i = 0; i < (int)B.size(); ++i) {
		before_b.push_back(before_b.back());
		for(auto& x : B[i]) {
			d.add_edge(++before_b.back(), 1 + flow_left + flow_right, x.second);
		}
	}

	for(int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		if(b%2 == 0)
			swap(a, b);
		a /= 2;
		b /= 2;
		int a_loc = 1;
		for(auto x : A[a]) {
			int b_loc = 1;
			for(auto y : B[b]) {
				if(x.first == y.first) {
					d.add_edge(before_a[a]+a_loc, before_b[b]+b_loc, min(x.second, y.second));
				}
				++b_loc;
			}
			++a_loc;
		}
	}
	cout << d.flow(0, 1+flow_left+flow_right) << "\n";
}