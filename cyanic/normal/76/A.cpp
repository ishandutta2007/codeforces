#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
using namespace std;

const int maxn = 209, maxm = 50009;
struct edge { 
	int u, v, a, b; 
	bool operator < (const edge &e0) const {
		return a < e0.a || a == e0.a && b < e0.b;
	}
} e[maxm];
struct Edge { 
	int u, v, w; 
	bool operator < (const Edge &e0) const {
		return w < e0.w;
	}
} E[maxm];
int pa[maxn], n, m, cnt, cur, tmp, G, S, x, y, mx;
long long ans = 1e48;

int getpa(int x) {
	if (pa[x] == x) return x;
	return pa[x] = getpa(pa[x]);
}

int main() {
	scanf("%d%d%d%d", &n, &m, &G, &S);
	rep (i, 1, m) scanf("%d%d%d%d", &e[i].u, &e[i].v, &e[i].a, &e[i].b);
	sort(e+1, e+m+1);
	rep (i, 1, m) {
		E[cur = ++cnt].u = e[i].u;
		E[cur].v = e[i].v; E[cur].w = e[i].b;
		while (cur >= 2 && E[cur] < E[cur-1])
			swap(E[cur--], E[cur-1]);
		tmp = n;
		rep (j, 1, n) pa[j] = j;
		rep (j, 1, cnt) {
			// printf("%d %d %d\n", i, E[j].u, E[j].v);
			x = getpa(E[j].u); y = getpa(E[j].v);
			if (x == y) {
				swap(E[cur = j], E[cnt--]);
				while (cur <= cnt-1 && E[cur+1] < E[cur])
					swap(E[cur++], E[cur+1]);
				j--;
				continue;
			}
			pa[x] = y; mx = E[j].w; tmp--;
		}
		if (tmp == 1) ans = min(ans, 1LL * e[i].a * G + 1LL * mx * S);
	}
	if (ans >= 4e18) puts("-1");
	else printf("%lld\n", ans);
	return 0;
}