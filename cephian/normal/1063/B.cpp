#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string grid[2005];

vector<int> G[2005*2005];
int n, m;

template <class T> //weight type
struct ijk {
	typedef pair<T,int> edge;
	typedef vector<vector<edge>> graph;
	typedef priority_queue<edge,vector<edge>,greater<edge>> pq;
	static const T INF = numeric_limits<T>::max();
	graph G;
	vector<T> d; //distances are stored here

	void init(int n) {
		G = graph(n);
		d = vector<T>(n);
	}

	ijk(int n) {
		init(n);
	}

	void add_edge(int i, int j, T w) {
		G[i].emplace_back(w,j);
	}

	int dist(int s, int t = -1) {
		pq Q;
		fill(d.begin(),d.end(),INF);
		d[s] = 0, Q.emplace(0,s);
		while(Q.size()) {
			edge p = Q.top();
			Q.pop();
			if(p.second == t) break;
			if(p.first != d[p.second]) continue;
			for(const edge &e : G[p.second]) {
				T w = p.first + e.first;
				int v = e.second;
				if(d[v] > w)
					Q.emplace(d[v] = w, v);
			}
		}
		return (~t)?d[t]:0;
	}
};

bool ok(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m && grid[i][j] == '.';
}

int code(int i, int j) {
	return i + j*n;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int r, c;
	ll x, y;
	cin >> n >> m >> r >> c >> x >> y;
	--r, --c;
	for(int i = 0; i < n; ++i)
		cin >> grid[i];

	vector<int> dx = {0, 1, 0, -1};
	vector<int> dy = {1, 0, -1, 0};
	ijk<int> D(n * m);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(ok(i, j)) {
				for(int k = 0; k < 4; ++k) {
					if(ok(i+dx[k], j+dy[k])) {
						int u = code(i, j);
						int v = code(i+dx[k], j+dy[k]);
						D.add_edge(u, v, dx[k] == 0);
						D.add_edge(v, u, dx[k] == 0);
					}
				}
			}
		}
	}
	D.dist(code(r, c));
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(ok(i, j)) {
				int d = D.d[code(i, j)];
				if(d == 0x7fffffff) continue;
				ll cx, cy;
				int diff = abs(j-c);
				if(j >= c) {
					cy = (d-diff)/2 + diff;
					cx = (d-diff)/2;
				} else {
					cx = (d-diff)/2 + diff;
					cy = (d-diff)/2;
				}
				if(cx <= x && cy <= y) ++ans;
			}
		}
	}
	cout << ans << "\n";
}