#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define int long long
const int INF = 1e9 + 7;
const int MAXN = 5000*1000;

int S, T;

struct edge {
	int to, id, flow, capacity;
	edge(int _to = 0, int _id = 0, int _flow = 0, int _capacity = 0) {
		to = _to;
		id = _id;
		flow = _flow;
		capacity = _capacity;
	}
};

int n;

vector <vector <int> > graph;
vector <edge> edgelist;

int dist[MAXN], start[MAXN];

void add_edge(int v, int u, int capacity, int id) {
	graph[v].push_back(edgelist.size());
	edgelist.push_back(edge(u, id, 0, capacity));

	graph[u].push_back(edgelist.size());
	edgelist.push_back(edge(v, -1, 0, 0));
}
 
bool bfs(int v) {
	queue <int> Q;
	fill(dist, dist + n, -1);
	dist[v] = 0;
	Q.push(v);
	while (!Q.empty()) {
		v = Q.front(); Q.pop();
		for (auto id : graph[v]) {
			if (dist[edgelist[id].to] == -1 && (edgelist[id].capacity - edgelist[id].flow) > 0) {
				Q.push(edgelist[id].to);
				dist[edgelist[id].to] = dist[v] + 1;
			}
		}
	}
	return dist[T] != -1;
}

long long flow = 0;

int dfs(int v, int cmin) {
	if (v == T) {
		return cmin;
	}
	for (; start[v] < (int)graph[v].size(); start[v]++) {
		int id = graph[v][start[v]];
		if (dist[v] + 1 == dist[edgelist[id].to] && (edgelist[id].capacity - edgelist[id].flow) > 0) {
			int tmp = dfs(edgelist[id].to, min(cmin, edgelist[id].capacity - edgelist[id].flow));
			if (tmp) {
				edgelist[id].flow += tmp;
				edgelist[id ^ 1].flow -= tmp;
				return tmp;
			}
		}
	}
	return 0;
}

int dfs(int v) {
	int tmp = dfs(v, INF);
	flow += tmp;
	return tmp;
}

vector <edge> ans;

void ans_dfs(int v) {
	dist[v] = 1;
	for (auto id : graph[v]) {
		if (dist[edgelist[id].to] == 0) {
			if (edgelist[id].capacity - edgelist[id].flow == 0) {
				ans.push_back(edgelist[id]);
			} else {
				ans_dfs(edgelist[id].to);
			}
		}
	}
}

int m, num;
int l[MAXN], r[MAXN];

int dinic(int k) {
	graph.clear();
	n = 2 + m + num;
	graph.resize(n);
	edgelist.clear();
	// return 0;
	for (int i = 0; i < num; i++) {
		add_edge(m + 1 + i, m + num + 1, k, -1);
	}

	for (int i = 0; i < m; i++) {
		add_edge(i + 1, m + 1 + l[i], 1, 0);
		add_edge(i + 1, m + 1 + r[i], 1, 0);
		add_edge(0, i + 1, 1, 0);
	}

	S = 0; T = n - 1;


	int ans = 0;
	while (bfs(S)) {
		fill(start, start + n, 0);
		while (true) {
			int tmp = dfs(S);
			ans += tmp;
			if (tmp == 0) break;
		}
	}
	return ans;
}

signed main() {
	cin >> num >> m;
	for (int i = 0; i < m; i++) {
		cin >> l[i] >> r[i];
		l[i]--;
		r[i]--;
	}
	// return 0;
	int left = -1, right = num;
	while (left + 1 < right) {
		int me = (left + right) / 2;
		// cout << me << endl;
		if (m == dinic(me)) {
			right = me;
		} else {
			left = me;
		}
	}
	dinic(right);

	cout << right << endl;
	for (int i = 1; i <= m; i++) {
		if (edgelist[graph[i][0]].flow == 1) {
			cout << l[i - 1] + 1 << " " << r[i - 1] + 1;
		} else {
			cout << r[i - 1] + 1 << " " << l[i - 1] + 1;
		}
		cout << "\n";
	}
}