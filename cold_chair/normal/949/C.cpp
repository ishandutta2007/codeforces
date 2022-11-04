#include<cstdio>
#include<cstring>
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;

const int N = 1e6 + 5;

int n, m, h, u[N], x, y;
int final[N], to[N], next[N], tot;


void link(int x, int y) {
	next[++ tot] = final[x], to[tot] = y, final[x] = tot;
}

struct node {
	int final[N], to[N], next[N], tot;
	void link(int x, int y) {
		next[++ tot] = final[x], to[tot] = y, final[x] = tot;
	}
} e;

void lin(int x, int y) {
	int xx = x > n ? x - n : x + n, yy = y > n ? y - n : y + n;
	link(y, xx); link(x, yy);
}

int bd[N], d[N], dfn[N], low[N], ff[N], td;

void dg(int x) {
    bd[x] = 1; d[++ d[0]] = x;
    dfn[x] = low[x] = ++ td;
    for(int i = final[x]; i; i = next[i])  {
        int y = to[i];
        if(!dfn[y]) dg(y), low[x] = min(low[x], low[y]); else
        if(bd[y]) low[x] = min(low[x], dfn[y]);
    }
    if(low[x] == dfn[x]) {
        for(; d[d[0]] != x; d[0] --)
            ff[d[d[0]]] = x, bd[d[d[0]]] = 0;
        d[0] --; ff[x] = x; bd[x] = 0;
    }
}

int bz[N], siz[N];

void dfs(int x) {
//	printf("%d %d\n", x, siz[x]);
	bz[x] = 1; siz[x] = 0;
	for(int i = e.final[x]; i; i = e.next[i]) {
		int y = e.to[i];
		siz[x] += (y > n);
		for(int j = final[y]; j; j = next[j]) {
			int z = ff[to[j]]; if(z == x) continue;
			if(!bz[z]) dfs(z);
			siz[x] += siz[z];
		}
	}
}

void dd(int x) {
	bz[x]  = 1;
	if(x > n) printf("%d\n", x - n);
	for(int i = final[x]; i; i = next[i]) {
		int y = to[i]; if(bz[y]) continue;
		dd(y);
	}
}

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%d %d %d", &n, &m, &h);
	fo(i, 1, n) scanf("%d", &u[i]);
	fo(i, 1, m) {
		scanf("%d %d", &x, &y);
		if(u[x] == u[y])
			lin(x, y), lin(x + n, y + n);
		if((u[x] + 1) % h == u[y])
			lin(x + n, y);
		if(u[x] == (u[y] + 1) % h)
			lin(x, y + n);
	}
	fo(i, 1, 2 * n) if(!dfn[i])
		dg(i);
	fo(i, 1, 2 * n) e.link(ff[i], i);
	fo(i, 1, 2 * n) if(ff[i] == i && !bz[i])
		dfs(i);
	int mx = 1e9, p;
	fo(i, 1, 2 * n) if(ff[i] == i) {
		if(siz[i] > 0 && siz[i] < mx)
			mx = siz[i], p = i;
	}
	memset(bz, 0, sizeof bz);
	printf("%d\n", siz[p]);
	dd(p);
}