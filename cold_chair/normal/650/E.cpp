#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 5e5 + 5;

int n, x, y;

ll num(int x, int y) {
	if(x > y) swap(x, y);
	return (ll) x * n + y;
}

map<ll, int> bz;

vector<int> p[N], q[N];
#define pb push_back

int fa[N], fa2[N], d[N], d0;

void dg(int x) {
	ff(j, 0, p[x].size()) {
		int y = p[x][j];
		if(y == fa[x]) continue;
		fa[y] = x; dg(y);
	}
	d[++ d0] = x;
}

int f[N];

void dfs(int x) {
	ff(j, 0, q[x].size()) {
		int y = q[x][j];
		if(y == fa2[x]) continue;
		fa2[y] = x; dfs(y);
		if(bz[num(x, y)] == 2) f[y] = x;
	}
}


int F(int x) { return f[x] == x ? x : (f[x] = F(f[x]));}
int main() {
	scanf("%d", &n);
	fo(i, 1, n - 1) {
		scanf("%d %d", &x, &y);
		p[x].pb(y); p[y].pb(x);
		bz[num(x, y)] ++;
	}
	int ans = n - 1;
	fo(i, 1, n - 1) {
		scanf("%d %d", &x, &y);
		q[x].pb(y); q[y].pb(x);
		bz[num(x, y)] ++;
		ans -= bz[num(x, y)] == 2;
	}
	fo(i, 1, n) f[i] = i;
	dg(1); dfs(1);
	pp("%d\n", ans);
	fo(i, 1, n - 1) {
		int x = d[i];
		if(bz[num(x, fa[x])] == 2) continue;
		int y = fa2[F(x)];
		pp("%d %d %d %d\n", x, fa[x], f[x], y);
		f[f[x]] = F(y);
	}
}