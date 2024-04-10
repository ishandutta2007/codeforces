#include<cstdio>
#include<algorithm>
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define fd(i, x, y) for(int i = x; i >= y; i --)
using namespace std;

const int N = 2e6 + 5;

int n, x, y;
int f[N][2], bz[N], d[N];
int next[N], to[N], final[N], tot;

struct node {
	int next[N], to[N], final[N], tot;
	void link(int x, int y) {
		next[++ tot] = final[x], to[tot] = y, final[x] = tot;
	}
} e, e2;

void link(int x, int y) {
	next[++ tot] = final[x], to[tot] = y, final[x] = tot;
}

int val(int x) {
	if(f[x][0] && f[x][1]) return 1;
	if(f[x][1]) return 0;
	if(f[x][0]) return 2;
}

int cmp(int x, int y) {
	return val(x) < val(y);
}

void dg(int x) {
	bz[x] = 1;
	for(int i = final[x]; i; i = next[i]) {
		int y = to[i]; if(bz[y]) continue;
		dg(y);
		if(!f[y][0] && !f[y][1]) return;
	}
	d[0] = 0;
	for(int i = final[x]; i; i = next[i]) {
		int y = to[i]; if(bz[y]) continue;
		d[++ d[0]] = y;
	}
	bz[x] = 0;
	if(d[0] == 0) {f[x][0] = 1; return;}
	sort(d + 1, d + d[0] + 1, cmp);
	fo(i, 1, d[0] + 1) {
		int y = d[i];
		if((i <= d[0] && val(y) == 0) || i > 1 && val(d[i - 1]) == 2) continue;
		f[x][(d[0] - i + 1) % 2] = 1;
	}
}

void dfs(int x, int fa) {
	bz[x] = 1; d[0] = 0;
	for(int i = final[x]; i; i = next[i]) {
		int y = to[i]; if(bz[y]) continue;
		d[++ d[0]] = y;
	}
	if(d[0] == 0) {printf("%d\n", x); return;}
	sort(d + 1, d + d[0] + 1, cmp);
	fo(i, 1, d[0] + 1) {
		int y = d[i];
		if((i <= d[0] && val(y) == 0) || i > 1 && val(d[i - 1]) == 2) continue;
		if((d[0] - i + 1) % 2 == fa) {
			fd(j, d[0], i) e.link(x, d[j]);
			fd(j, i - 1, 1) e2.link(x, d[j]);
			break;
		}
	}
	for(int i = e2.final[x]; i; i = e2.next[i])
		dfs(e2.to[i], 1);
	printf("%d\n", x);
	for(int i = e.final[x]; i; i = e.next[i])
		dfs(e.to[i], 0);
	bz[x] = 0;
}

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d", &n);
	fo(i, 1, n) {
		scanf("%d", &x); if(x == 0) continue;
		link(i, x); link(x, i);
	}
	dg(1);
//	fo(i, 1, n) printf("%d %d\n", f[i][0], f[i][1]);
	if(!f[1][0]) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	dfs(1, 0);
}