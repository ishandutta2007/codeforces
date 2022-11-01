#include "bits/stdc++.h"

#define ALL(v) (v).begin(), (v).end()

const int N = 100000;

int x[N], y[N];
int r, b;
int n, m;

const int V = N * 2 + 4;
const int E = (N * 7 + 1) * 2;

struct Graph {
	int to[E], next[E], head[V], cap[E], edge_count;
	void clear(int V) {
		for (int i = 0; i < V; i++) head[i] = -1;
		edge_count = 0;
	}
	void add_edge_(int a, int b, int c) {
		to[edge_count] = b;
		next[edge_count] = head[a];
		cap[edge_count] = c;
		head[a] = edge_count++;
	}
	void add_edge(int a, int b, int c) {
		add_edge_(a, b, c);
		add_edge_(b, a, 0);
	}
	void add_LR_edge(int ss, int tt, int a, int b, int low, int high) {
		add_edge(ss, b, low);
		add_edge(a, tt, low);
		add_edge(a, b, high - low);
	}
}g;

int first[V], level[V];

std::vector<int> rename(int x[], int n) {
	std::vector<int> values(x, x + n);
	std::sort(ALL(values));
	values.erase(std::unique(ALL(values)), values.end());
	for (int i = 0; i < n; i++) {
		x[i] = std::lower_bound(ALL(values), x[i]) - values.begin();
	}
	return values;
}

int find(const std::vector<int> &vec, int v) {
	auto iterator = std::lower_bound(ALL(vec), v);
	return (iterator == vec.end() || *iterator != v) ?
		-1 : iterator - vec.begin();
}

bool bfs(int s, int t) {
	std::fill(level, level + t + 1, -1);
	level[t] = 0;
	std::queue<int> queue;
	queue.push(t);
	while (!queue.empty() && !~level[s]) {
		int u = queue.front();
		queue.pop();
		for (int it = g.head[u]; ~it; it = g.next[it]) {
			int v = g.to[it];
			if (g.cap[it ^ 1] && level[v] == -1) {
				queue.push(v);
				level[v] = level[u] + 1;
			}
		}
	}
	return ~level[s];
}

int dfs(int u, int t, int limit) {
	if (u == t) {
		return limit;
	}
	int delta = 0;
	for (int &it = first[u]; ~it; it = g.next[it]) {
		int v = g.to[it];
		if (level[v] + 1 == level[u] && g.cap[it]) {
			int flow = dfs(v, t, std::min(limit - delta, g.cap[it]));
			g.cap[it] -= flow;
			g.cap[it ^ 1] += flow;
			if ((delta += flow) == limit) {
				return delta;
			}
		}
	}
	level[u] = -1;
	return delta;
}

int max_flow(int s, int t) {
	int result = 0;
	while (bfs(s, t)) {
		for (int i = 0; i <= t; i++) first[i] = g.head[i];
		result += dfs(s, t, n);
	}
	return result;
}

int main() {
	scanf("%d %d", &n, &m);
	scanf("%d %d", &r, &b);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", x + i, y + i);
	}
	auto xs = std::move(rename(x, n));
	auto ys = std::move(rename(y, n));
	int nx = xs.size(), ny = ys.size();
	std::vector<int> cnt_x(nx, 0), cnt_y(ny, 0);
	for (int i = 0; i < n; i++) {
		cnt_x[x[i]]++;
		cnt_y[y[i]]++;
	}
	std::vector<int> limit_x = cnt_x, limit_y = cnt_y;
	for (int i = 0; i < m; i++) {
		int t, l, d;
		scanf("%d %d %d", &t, &l, &d);
		l = find(t == 1 ? xs : ys, l);
		if (~l) {
			auto &ref = (t == 1 ? limit_x : limit_y)[l];
			ref = std::min(ref, d);
		}
	}
	int s = nx + ny;
	int t = s + 1;
	int ss = t + 1;
	int tt = ss + 1;
	int tot = tt + 1;
	g.clear(tot);
	bool valid = true;
	g.add_edge(t, s, n);
	for (int i = 0; i < n; i++) {
		g.add_edge(x[i], nx + y[i], 1);
	}
	for (int i = 0; i < nx; i++) {
		int low = cnt_x[i] - limit_x[i] + 1 >> 1;
		int high = cnt_x[i] + limit_x[i] >> 1;
		valid &= low <= high;
		g.add_LR_edge(ss, tt, s, i, low, high);
	}
	for (int i = 0; i < ny; i++) {
		int low = cnt_y[i] - limit_y[i] + 1 >> 1;
		int high = cnt_y[i] + limit_y[i] >> 1;
		valid &= low <= high;
		g.add_LR_edge(ss, tt, nx + i, t, low, high);
	}
	if (valid) {
		max_flow(ss, tt);
		for (int it = g.head[ss]; ~it; it = g.next[it]) {
			valid &= !g.cap[it];
		}
	}
	if (valid) {
		int result = g.cap[1];
		g.cap[1] = g.cap[0] = 0;
		result += max_flow(s, t);
		int minv = r, maxv = b;
		char minc = 'r', maxc = 'b';
		if (r > b) {
			std::swap(minv, maxv);
			std::swap(minc, maxc);
		}
		std::cout << 1LL * result * minv + 1LL * (n - result) * maxv << std::endl;
		for (int i = 0; i < n; i++) {
			putchar(g.cap[i + 1 << 1] ? maxc : minc);
		}
		puts("");
	} else {
		puts("-1");
	}
	return 0;
}