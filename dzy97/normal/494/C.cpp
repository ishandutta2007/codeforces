#include <bits/stdc++.h>
using namespace std;

#define N 100010
#define M 5010

typedef long double db;
double _;
int n, m, a[N], lg[N], st[20][N], s[N], top;
int sz[N];
 
vector <int> g[M];
db f[M][M];

struct node{
	int l, r, mx;
	db p;
}q[M];

bool cmp(const node &a, const node &b){
	if(a.l == b.l) return a.r > b.r;
	return a.l < b.l;
}

bool judge(const node &a, const node &b){
	return a.r < b.l || b.r < a.l;
}

int ask(int x, int y){
	int k = lg[y - x + 1];
	return max(st[k][x], st[k][y - (1 << k) + 1]);
}

void dfs(int u){
	sz[u] = 1;
	for(int i = 0;i < g[u].size();i ++){
		dfs(g[u][i]);
		sz[u] += sz[g[u][i]];
	}
	for(int i = 1;i <= sz[u];i ++){
		db x = q[u].p;
		for(int j = 0;j < g[u].size();j ++){
			int v = g[u][j];
			x *= f[v][min(sz[v], q[u].mx - q[v].mx + i - 1)];
		}
		f[u][i] += x;
	}
	for(int i = 0;i <= sz[u];i ++){
		db x = 1 - q[u].p;
		for(int j = 0;j < g[u].size();j ++){
			int v = g[u][j];
			x *= f[v][min(sz[v], q[u].mx - q[v].mx + i)];
		}
		f[u][i] += x;
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i ++) scanf("%d", &a[i]), st[0][i] = a[i];
	for(int i = 2;i <= n;i ++) if(i & (i - 1)) lg[i] = lg[i - 1]; else lg[i] = lg[i - 1] + 1;
	for(int i = 1;i <= 16;i ++)
		for(int j = 1;j + (1 << i) - 1 <= n;j ++)
			st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
	for(int i = 1;i <= m;i ++){
		scanf("%d%d%lf", &q[i].l, &q[i].r, &_);
		q[i].p = (db)_;
		q[i].mx = ask(q[i].l, q[i].r);
	}
	q[++ m] = (node){1, n, ask(1, n), 0};
	sort(q + 1, q + m + 1, cmp);
	s[top = 1] = 1;
	for(int i = 2;i <= m;i ++){
		while(top >= 1 && judge(q[s[top]], q[i])) top --;
		g[s[top]].push_back(i);
		s[++ top] = i;
	}
	dfs(1);
	db ans = q[1].mx * f[1][0];
	for(int i = 1;i <= m;i ++) ans += (f[1][i] - f[1][i - 1]) * (q[1].mx + i);
	printf("%.12lf\n", (double)ans);	
	return 0;
}