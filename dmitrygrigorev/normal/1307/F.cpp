#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<vector<int> > data;
vector<bool> special;

vector<int> dist;
vector<int> repr;

void add_edge(int u, int v) {
	data[u].push_back(v);
	data[v].push_back(u);
}

struct Vertex {
	int f; int r; 
};

vector<Vertex> snm;

int get(int v) {
	if (snm[v].f != v) snm[v].f = get(snm[v].f);
	return snm[v].f;
}

void unite(int u, int v) {
	if (snm[u].r > snm[v].r) swap(u, v);

	snm[u].f = v;
	if (snm[u].r == snm[v].r) snm[v].r++;

}

int n, k;
const int INF = 1e9;

void bfs() {

	for (int i = 0; i < 2*n - 1; ++i) {
		if (special[i]) {
			dist[i] = 0;
			repr[i] = i;
		}
		else {
			dist[i] = INF;
			repr[i] = -1;
		} 
	}

	queue<int> q;

	for (int i = 0; i < 2 * n - 1; ++i) {
		if (dist[i] == INF) continue;
		q.push(i);
	}

	while (q.size()) {

		int W = q.front();
		q.pop();

		for (int i = 0; i < data[W].size(); ++i) {
			int to = data[W][i];
			if (dist[W] + 1 < dist[to]) {
				dist[to] = dist[W] + 1;
				if (dist[to] <= k) {
					repr[to] = repr[W];
				}
				q.push(to);
			}
			else if (dist[W] + 1 == dist[to]) {
				if (dist[to] <= k) {
					int A = get(repr[to]), B = get(repr[W]);
					if (A==B) continue;
					unite(A, B);
				}
			}
		}

	}


}

const int N = 400007, LG = 20;
int timer = 0;

int binup[N][LG];
vector<int> h, tin, tout;

void dfs(int vertex, int last, int d) {

	tin[vertex] = timer++;

	h[vertex] = d;
	if (last != -1) {
		binup[vertex][0] = last;
		int W = last;
		int lvl = 0;

		while (binup[W][lvl] != -1) {
			binup[vertex][lvl+1] = binup[W][lvl];
			W = binup[W][lvl];
			lvl++;
		}
	}

	for (int i = 0; i < data[vertex].size(); ++i) {
		int to = data[vertex][i];
		if (to==last) continue;
		dfs(to, vertex, d+1);
	}

	tout[vertex] = timer++;

}

bool father(int u, int v) {
	if (tin[u] <= tin[v] && tout[u] >= tout[v]) return true;
	return false;
}

int lca(int u, int v) {

	if (father(u, v)) return u;
	if (father(v, u)) return v;

	for (int i = 19; i >= 0; i--) {
		int cand = binup[v][i];
		if (cand == -1) continue;

		if (father(cand, u)) {
			continue;
		}
		v = cand;
	}

	return binup[v][0];

}

int get_dist(int x, int y) {
	int l = lca(x, y);

	return abs(h[l] - h[x]) + abs(h[l] - h[y]);

}

int go(int x, int y) {
	for (int i = 0; i < 20; ++i) {
		if ((1<<i)&y) {
			x = binup[x][i];
		}
	}

	return x;

}

int main(){
#ifdef LOCAL
	freopen("I_input.txt", "r", stdin);
	//freopen("I_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a;
	cin >> n >> k >> a;

	data.assign(2*n-1, {});

	for (int i = 0; i < n - 1; ++i) {
		int c, d;
		cin >> c >> d;
		c--, d--;
		add_edge(c, i+n);
		add_edge(d, i+n);
	}

	for (int i = 0; i < 2*n-1; ++i) snm.push_back({i, 1});

	special.assign(2*n-1, false);

	for (int i = 0; i < a; ++i) {
		int x;
		cin >> x;
		x--;
		special[x] = true;
	}

	dist.assign(2*n-1, -1);
	repr.assign(2*n-1, -1);
	tin.assign(2*n - 1, -1);
	tout.assign(2 * n - 1, -1);

	bfs();

	for (int i = 0; i < N; ++i) for (int j = 0; j < LG; ++j) binup[i][j] = -1;
	h.assign(2*n - 1, -1);

	dfs(0, -1, 0);

	int q;
	cin >> q;

	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		int len = get_dist(a, b);
		if (len <= 2*k) {
			cout << "YES\n";
			continue;
		}

		int A, B;
		int l = lca(a, b);
		if (h[l] + k <= h[a]) {
			A = go(a, k);
		}
		else A = go(b, len-k);

		if (h[l] + k <= h[b]) {
			B = go(b, k);
		}
		else B = go(a, len-k);

		if (repr[A] == -1 || repr[B] == -1) {
			cout << "NO\n";
		}
		else {
			A = get(repr[A]);
			B = get(repr[B]);
			if (A==B) {
				cout << "YES\n";
			}
			else cout << "NO\n";
		}

	}



}