#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 222222;

int l[N], r[N];
int h[2][N];
vector<int> e[N];
int n, m, a[N], be[N], val[N];
int cnt = 0;

void dfs(int x, int father, int type) {
	l[x] = ++cnt;
	val[cnt] = a[x];
	be[x] = type;
	for(int i = 0; i < (int)e[x].size(); i++) {
		int y = e[x][i];
		if (y == father)
			continue;
		dfs(y, x, 1 - type);
	}
	
	r[x] = cnt;
}

inline int lowbit(int x) {
	return x & (-x);
}

int ask(int pos, int a[]) {
	int res = 0;
	for(int i = pos; i; i -= lowbit(i))	
		res += a[i];
	return res;
} 

void insert(int pos, int v, int a[]) {
	for(int i = pos; i <= cnt; i += lowbit(i)){
		a[i] += v;
	}
}

int main() {
	
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	for(int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	
	dfs(1, 0, 0);
	for(int i = 1; i <= n; i++) {
		insert(i, val[i] - val[i - 1], h[0]);
		insert(i, val[i] - val[i - 1], h[1]);
	}
	
	for(int i = 1; i <= m; i++) {
		int t, a, b;
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d %d", &a, &b);
			insert(l[a], b, h[be[a]]);
			insert(r[a] + 1, -b, h[be[a]]);
			
			insert(l[a], -b, h[1 - be[a]]);
			insert(r[a] + 1, b, h[1 - be[a]]);
		} else {
			scanf("%d", &a);
			printf("%d\n", ask(l[a], h[be[a]]));
		}
	}
	return 0;
}