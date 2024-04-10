#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n;
int a[N][N];
int b[N * N];
int vis[N * N * 3];
vector<pair<int, int>> adj[N*N][3];

int get(int x, int y, int t) {
	return x * n * n * 3 + y * 3 + t;
}

void get(int v, int &x, int &y, int &t) {
	t = v % 3;
	v /= 3;
	y = v % (n * n);
	x = v / (n * n);
}

const int M = N * N * 2;

int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

int d[N * N * 3];

bool valid(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

int dijkstra(int f) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (int i = 0; i < n*n*n*n*3; i++) d[i] = 1e9;
	pq.emplace(0, f);
	d[f] = 0;
	memset(vis, 0, sizeof vis);
	while (!pq.empty()) {
		auto tp = pq.top();
		pq.pop();
		int u = tp.second;
		if (vis[u]) continue;
		vis[u] = 1;
		int x, y, t;
		get(u, x, y, t);
		for (auto tt : adj[x][t]) {
			int nx = tt.first, ny = tt.second;
			int px = nx * n + ny;
			int py = y;
			if (y < n*n-1 && px == b[y+1]) ++py;
			int pu = get(px, py, t);
			if (!vis[pu] && d[pu] > d[u] + M) {
				d[pu] = d[u] + M;
				pq.emplace(d[pu], pu);
			}
		}
		for (int k = 0; k < 3; k++) {
			if (k == t) continue;
			int pu = get(x, y, k);
			if (!vis[pu] && d[pu] > d[u] + M + 1) {
				d[pu] = d[u] + M + 1;
				pq.emplace(d[pu], pu);
			}
		}
	}
	int ans = 1e9;
	for (int i = 0; i < 3; i++) ans = min(ans, d[get(b[n*n-1], n*n-1, i)]);
	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x; scanf("%d", &x);
			--x;
			a[i][j] = x;
			b[x] = i * n + j;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int u = i * n + j;
			for (int k = 0; k < 8; k++) {
				int nx = i + dx[k], ny = j + dy[k];
				if (valid(nx, ny)) adj[u][0].emplace_back(nx, ny);
			}
			for (int k = -n; k <= n; k++) {
				if (k == 0) continue;
				int nx = i + k, ny = j;
				if (valid(nx, ny)) adj[u][1].emplace_back(nx, ny);
			}
			for (int k = -n; k <= n; k++) {
				if (k == 0) continue;
				int nx = i, ny = j + k;
				if (valid(nx, ny)) adj[u][1].emplace_back(nx, ny);
			}
			for (int k = -n; k <= n; k++) {
				if (k == 0) continue;
				int nx = i + k, ny = j + k;
				if (valid(nx, ny)) adj[u][2].emplace_back(nx, ny);
			}
			for (int k = -n; k <= n; k++) {
				if (k == 0) continue;
				int nx = i + k, ny = j - k;
				if (valid(nx, ny)) adj[u][2].emplace_back(nx, ny);
			}
		}
	}
	int ans = 1e9;
	for (int i = 0; i < 3; i++) {
		ans = min(ans, dijkstra(get(b[0], 0, i)));
	}
	printf("%d %d\n", ans/M, ans%M);
}