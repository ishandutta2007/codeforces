#include <cstdio>
#include <vector>

using namespace std;

const int MaxN = 201234, MaxM = MaxN << 2;

int n, m, v[MaxN], c; vector<int> ans[MaxN];
struct edge {
	int to, nxt;
}e[MaxM]; int cnt, lst[MaxN];

void ins(int a, int b) {
	e[++cnt] = (edge) {b, lst[a]}; lst[a] = cnt;
}

void lnk(int a, int b) {
	ins(a, b);
	ins(b, a);
}

void dfs(int x, int fa = 0) {
	v[x] = ++c;
	for(int i = lst[x], y; y = e[i].to, i; i = e[i].nxt) 
		if(!v[y]) 
			dfs(y, x);
		else 
			if(y != fa && v[y] < v[x]) 
				ans[y].push_back(x);
	if(fa) 
		if(ans[x].size() & 1)
			ans[x].push_back(fa);
		else
			ans[fa].push_back(x);
} 

int main() {
	int i; scanf("%d %d", &n, &m);
	for(i = 1; i <= m; i++) {
		int u, v; scanf("%d%d", &u, &v); 
		lnk(u, v);
	}
	for(i = 1; i <= n; i++) if(!v[i]) dfs(i);
	
	int p = 0;
	for(i = 1; i <= n; i++) p += ans[i].size() / 2;
	printf("%d\n", p);
	for(i = 1; i <= n; i++) 
		for(int j = 0; j < ans[i].size(); j += 2)
			if(j + 1 < ans[i].size()) printf("%d %d %d\n", ans[i][j], i, ans[i][j + 1]);
	return 0;
}