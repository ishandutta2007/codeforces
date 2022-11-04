#include<cstdio>
#define ll long long
#define fo(i, x, y) for(int i = x; i <= y;i  ++)
using namespace std;

const int mo = 1e9 + 7;

const int N = 4e5 + 5;

int n, a[N], x, y;
int next[N * 2], to[N * 2], final[N], tot;
int f[N][2], bz[N], siz[N]; ll ans;

void link(int x, int y){
	next[++ tot] = final[x], to[tot] = y, final[x] = tot;
	next[++ tot] = final[y], to[tot] = x, final[y] = tot;
}

void dg(int x) {
	bz[x] = 1;
	f[x][0] = 1;
	siz[x] = 1;
	for(int i = final[x]; i; i = next[i]) {
		if(bz[to[i]]) continue;
		dg(to[i]);
		f[x][0] += f[to[i]][1];
		f[x][1] += f[to[i]][0];
		siz[x] += siz[to[i]];
	}
	bz[x] = 0;
}

void dfs(int x) {
	bz[x] = 1;
	ans = (ans + (ll) a[x] * n % mo) % mo;
	for(int i = final[x]; i; i = next[i]) {
		if(bz[to[i]]) continue;
		ans = (ans + (ll) (f[to[i]][1] - f[to[i]][0]) * (n - siz[to[i]]) % mo * a[x] % mo) % mo;
		ans = (ans + (ll) ((f[x][1] - f[to[i]][0]) - (f[x][0] - f[to[i]][1])) * siz[to[i]] % mo * a[to[i]] % mo) % mo;
		f[to[i]][0] = f[x][1];
		f[to[i]][1] = f[x][0];
		dfs(to[i]);
	}
	bz[x] = 0;
}

int main() {
//	freopen("e.in", "r", stdin);
	scanf("%d", &n);
	fo(i, 1, n) scanf("%d", &a[i]);
	fo(i, 1, n - 1) {
		scanf("%d %d", &x, &y);
		link(x, y);
	}
	int g = (n + 1) / 2;
	dg(g); dfs(g);
	ans = (ans % mo + mo) % mo;
	printf("%I64d", ans);
}