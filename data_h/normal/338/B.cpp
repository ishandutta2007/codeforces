#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 110000, MAXM = MAXN * 2;
const int inf = 10000000;

struct eglist {
	int other[MAXM], succ[MAXM], last[MAXM], sum;
	void addEdge(int a, int b) {
		other[++sum] = b, succ[sum] = last[a], last[a] = sum;
		other[++sum] = a, succ[sum] = last[b], last[b] = sum;
	}
	void clear(int n) {
		for(int i = 0; i <= n; i++)
			last[i] = 0;
		sum = 0;
	}
}e;

int fa[MAXN];
pair<int, int> down1[MAXN], down2[MAXN];
int up[MAXN], ans = 0;
queue<int> q;
int visit[MAXN] = {};
int n, m, d;
	
void dfsDown(int x, int fa) {
	if (visit[x]) {
		down1[x] = make_pair(0, 0);
		down2[x] = make_pair(0, 0);
	} else {
		down1[x].first = -inf, down2[x].first = -inf;
	}
	for(int i = e.last[x]; i; i = e.succ[i]) {
		int y = e.other[i];
		if (y == fa)
			continue;
		dfsDown(y, x);
		pair<int, int> tmp = down1[y];
		tmp.first++; tmp.second = y;
		if (tmp > down1[x]) {
			down2[x] = down1[x];
			down1[x] = tmp;
		} else if (tmp > down2[x])
			down2[x] = tmp;
	}
}

void dfsUp(int x, int fa) {
	up[x] = visit[x] ? 0 : -inf;
	if (fa == 0) {
		if (down1[x].first <= d)
				ans++;
	} else {
		up[x] = max(up[x], up[fa] + 1);
		if (down1[fa].second == x)
			up[x] = max(up[x], down2[fa].first + 1);
		else
			up[x] = max(up[x], down1[fa].first + 1);
		if (max(up[x], down1[x].first) <= d)
				ans++;
	}
	for(int i = e.last[x]; i; i = e.succ[i]) {
		int y = e.other[i];
		if (y == fa)
			continue;
		dfsUp(y, x);
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &d);
	for(int i = 1; i <= m; i++) {
		int p;
		scanf("%d", &p);
		visit[p] = 1;
	}
	e.clear(n);
	for(int i = 1; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		e.addEdge(a, b);
	}
	dfsDown(1, 0);
	dfsUp(1, 0);
	printf("%d\n", ans);
	return 0;
}