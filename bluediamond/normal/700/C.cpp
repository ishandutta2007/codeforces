#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <cassert> 
#include <algorithm> 
#include <set> 
#include <iomanip> 
#include <queue> 
#include <deque> 
#include <unordered_set> 
#include <unordered_map> 
#include <functional> 
#include <cmath> 
#include <map> 
#include <random> 
#include <chrono> 
#include <cstdio> 
#include <bitset> 
#include <numeric> 

bool home = true;
using namespace std;

typedef long long ll;

const int N = 1000 + 7;
const int M = 30000 + 7;
const int INF = (int)2e9 + 7;

mt19937 rng((long long)(new char));

struct Edge {
	int a, b, c, is_valid;
};

int n;
int m;
int s;
int t;
vector<int> g[N];
Edge edges[M];
int par_edge[N];

vector<int> find_path() {
	// o(n + m)

	for (int i = 1; i <= n; i++) par_edge[i] = -1;
	par_edge[s] = 0;
	queue<int> q;
	q.push(s);

	while (!q.empty()) {
		int a = q.front();
		q.pop();
		for (auto& i : g[a]) {
			if (!edges[i].is_valid) continue;
			int b = edges[i].a + edges[i].b - a;
			if (par_edge[b] == -1) {
				par_edge[b] = i;
				q.push(b);
			}
		}
	}

	vector<int> path;
	if (par_edge[t] == -1) return path;

	int vertex = t;
	while (vertex != s) {
		int i = par_edge[vertex];
		path.push_back(i);
		vertex = edges[i].a + edges[i].b - vertex;
	}
	reverse(path.begin(), path.end());
	shuffle(path.begin(), path.end(), rng);
	return path;
}

int dep[N], mindep[N];
vector<int> used_edges[N];
vector<int> normal_edges[N];
vector<int> bridges[N];

void dfs(int a, int p = -1) {
	mindep[a] = dep[a];
	for (auto& i : g[a]) {
		if (!edges[i].is_valid) continue;
		int b = edges[i].a + edges[i].b - a;
		if (dep[b] == -1) {
			dep[b] = 1 + dep[a];
			dfs(b, i);
			mindep[a] = min(mindep[a], mindep[b]);
			used_edges[a].push_back(i);
		}
		else {
			if (i != p) {
				mindep[a] = min(mindep[a], dep[b]);
			}
		}
	}
}

bool bad;
bool vis[N];
int m_best[N];

void explore(int a, int best, int best_id) {

	m_best[a] = best_id;
	vis[a] = 1;
	for (auto& i : normal_edges[a]) {
		if (!edges[i].is_valid) continue;
		int b = edges[i].a + edges[i].b - a;
		if (!vis[b]) explore(b, best, best_id);
	}
	for (auto& i : bridges[a]) {
		if (!edges[i].is_valid) continue;
		int b = edges[i].a + edges[i].b - a;
		if (!vis[b]) {
			int n_best = best;
			int n_best_id = best_id;
			if (edges[i].c < n_best) {
				n_best = edges[i].c;
				n_best_id = i;
			}
			explore(b, n_best, n_best_id);
		}
	}
}

void two_way() {
	// o(n + m)
	bad = 0;
	for (int i = 1; i <= n; i++) {
		dep[i] = -1;
		used_edges[i].clear();
		normal_edges[i].clear();
		bridges[i].clear();
	}
	dep[s] = 0;
	dfs(s);
	for (int a = 1; a <= n; a++) {
		for (auto& i : used_edges[a]) {
			int b = edges[i].a + edges[i].b - a;
			if (dep[a] < mindep[b]) {
				// bridge
				bridges[a].push_back(i);
			}
			else {
				// not bridge
				normal_edges[a].push_back(i);
			}
		}
	}
	assert(dep[t] != -1);
	{
		// o(n + m)

		for (int i = 1; i <= n; i++) par_edge[i] = -1;
		par_edge[s] = 0;
		queue<int> q;
		q.push(s);

		while (!q.empty()) {
			int a = q.front();
			q.pop();
			for (auto& i : normal_edges[a]) {
				if (!edges[i].is_valid) continue;
				int b = edges[i].a + edges[i].b - a;
				if (par_edge[b] == -1) {
					par_edge[b] = i;
					q.push(b);
				}
			}
		}
		if (par_edge[t] != -1) {
			bad = 1;
			return;
		}
	}
	for (int i = 1; i <= n; i++) vis[i] = 0, m_best[i] = -1;
	explore(s, INF, -1);
}

signed main() {
#ifdef ONLINE_JUDGE
	home = 0;
#endif

	if (home) {
		FILE* stream;
		freopen_s(&stream, "iron_man.txt", "r", stdin);
	}
	else {
		ios::sync_with_stdio(0); cin.tie(0);
	}


	cin >> n >> m >> s >> t;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges[i] = { a, b, c, 1 };
		g[a].push_back(i);
		g[b].push_back(i);
	}

	vector<int> path = find_path();
	if (path.empty()) {
		cout << "0\n";
		cout << "0\n";
		return 0;
	}

	int best = INF;
	vector<int> guys;

	for (auto& i : path) {
		if (edges[i].c >= best) continue;
		edges[i].is_valid = 0;
		vector<int> new_path = find_path();
		if (new_path.empty()) {
			assert(edges[i].c < best);
			best = edges[i].c;
			guys = { i };
		}
		else {
			// if s-t are connected two way, break
			two_way();
			if (bad) continue;
			int j = m_best[t];
			if (edges[i].c + edges[j].c < best) {
				best = edges[i].c + edges[j].c;
				guys = { i, j };
			}
		}
		edges[i].is_valid = 1;
	}
	if (best == INF) {
		cout << "-1\n";
		return 0;
	}
	cout << best << "\n";
	cout << (int)guys.size() << "\n";
	for (auto& i : guys) {
		cout << i << " ";
	}
	cout << "\n";
}