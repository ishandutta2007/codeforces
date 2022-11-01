#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 333333;

int n, m, q;

int father[N], visit[N], length[N];
vector<int> e[N];
int target, dist;

void dfs(int x, int from, int d) {
	visit[x] = 1;
	if (d > dist) {
		dist = d;
		target = x;
	}
	
	for(int i = 0; i < (int)e[x].size(); i++) {
		int y = e[x][i];
		if (y == from) {
			continue;
		}
		dfs(y, x, d + 1);
	}
}

int find(int x) {
	return father[x] == x ? x : father[x] = find(father[x]);
}

int main() {
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 1; i <= n; i++) {
		visit[i] = 0;
		father[i] = i;
	}
	for(int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		e[a].push_back(b);
		e[b].push_back(a);
		a = find(a), b = find(b);
		father[a] = b;
	}
	for(int i = 1; i <= n; i++) {
		if (!visit[i]) {
			dist = -1;
			dfs(i, -1, 0);
			dist = -1;
			dfs(target, -1, 0);
			length[find(i)] = dist;
		}
	}
	for(int i = 1; i <= q; i++) {
		int type;
		scanf("%d", &type);
		if (type == 1) {
			int x;
			scanf("%d", &x);
			printf("%d\n", length[find(x)]);
		} else {
			int x, y;
			scanf("%d %d", &x, &y);
			x = find(x), y = find(y);
			if (x == y) {
				continue;
			}
			length[y] = max(max(length[y], length[x]), (length[y] + 1) / 2 + (length[x] + 1) / 2 + 1);
			father[x] = y;
		}
	}
	return 0;
}