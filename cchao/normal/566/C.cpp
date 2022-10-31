#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pid;
const int maxn = 200000 + 10;
#define repe(i, a, b) for(int i = a; i <= b; ++i)
int n;
vector<pid> g[maxn];
int w[maxn];
int ans;
double ansv;
bool rm[maxn] = {};

double dist[maxn], grad[maxn];

void dfs2(int root, int x, int p, double d) {
	dist[root] += d * sqrt(d) * w[x];
	grad[root] += sqrt(d) * w[x];
	for(pid t: g[x]) {
		int y = t.first;
		if(y != p) dfs2(root, y, x, d + t.second);
	}
}

int go(int x) {
	double sum = 0;
	double gg = -1;
	int ch = -1;
	for(pid t: g[x]) {
		int y = t.first;
		dist[y] = grad[y] = 0;
		dfs2(y, y, x, t.second);
		sum += dist[y];
		if(grad[y] > gg) {
			gg = grad[y];
			ch = y;
		}
	}
	if(sum < ansv) {
		ansv = sum;
		ans = x;
	}
	return ch;
}
int sz[maxn];
int dfs(int x, int p) {
	sz[x] = 1;
	for(pid t: g[x]) {
		int y = t.first;
		if(y != p && !rm[y]) sz[x] += dfs(y, x);
	}
	return sz[x];
}
int center(int x) {
	dfs(x, -1);
	int p = -1;
	int cap = sz[x] >> 1;
	for(;;) {
		bool fg = false;
		for(pid t: g[x]) {
			int y = t.first;
			if(!rm[y] && y != p && sz[y] > cap) {
				fg = true;
				p = x;
				x = y;
				break;
			}
		}
		if(!fg) return x;
	}
}
void solve(int x) {
	for(;x && !rm[x];) {
		int y = center(x);
		x = go(y);
		rm[y] = true;
	}
}

int main() {
	scanf("%d", &n);
	repe(i, 1, n) scanf("%d", &w[i]);
	repe(i, 2, n) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}
	ansv = 1e22;
	solve(1);
	printf("%d %.12f\n", ans, ansv);
	return 0;
}