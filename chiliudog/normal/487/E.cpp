#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
#define maxn 200010
#define pii pair<int, int>
#define mp make_pair
#define fr first
#define sc second
#define oo 0x3f3f3f3f
using namespace std;
void gn(int &x)
{
	x = 0; char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
}
int n, m, q, u, v, a[maxn];
int dfn[maxn], low[maxn], dcnt, tmp[maxn], ttot, cnt;
int g[maxn], h[maxn], ei = 1;
bool used[maxn], isc[maxn];
int top;
pii sta[maxn];
struct edge{
	int t, nxt;
}e[maxn * 3];
void ae(int *g, int a, int b)
{
	e[++ ei].t = b; e[ei].nxt = g[a]; g[a] = ei;
}
void ad(int *g, int a, int b)
{
	ae(g, a, b); ae(g, b, a);
}
void dfs(int x)
{
	dfn[x] = low[x] = ++ dcnt; int son = 0, cur;
	for (int i = g[x]; i; i = e[i].nxt){
		if (used[i >> 1]) continue;
		used[i >> 1] = 1;
		if (dfn[e[i].t] > dfn[x]) continue;
		sta[++ top] = mp(x, e[i].t); cur = top;
		if (dfn[e[i].t])
			low[x] = min(low[x], dfn[e[i].t]);
		else{
			dfs(e[i].t); ++ son;
			low[x] = min(low[x], low[e[i].t]);
			if (low[e[i].t] >= dfn[x]){
				if (x == 1) isc[x] = (son > 1); else isc[x] = 1;
				++ cnt; ttot = 0;
				do{
					tmp[++ ttot] = sta[top].fr;
					tmp[++ ttot] = sta[top].sc;
				}while ((top --) > cur);
				sort(tmp + 1, tmp + ttot + 1);
				ttot = unique(tmp + 1, tmp + ttot + 1) - tmp - 1;
				for (int j = 1; j <= ttot; ++ j)
					ad(h, n + cnt, tmp[j]);
			}
		}
	}
}
int dep[maxn], pre[maxn], w[maxn], size[maxn], son[maxn], tp[maxn], pcnt, pos[maxn], b[maxn];
multiset<int> S[maxn / 2];
void build(int x)
{
	if (x <= n) w[x] = a[x]; int mi = oo;
	size[x] = 1;
	for (int i = h[x]; i; i = e[i].nxt)
		if (e[i].t != pre[x]){
			pre[e[i].t] = x;
			dep[e[i].t] = dep[x] + 1;
			build(e[i].t);
			size[x] += size[e[i].t];
			if (size[e[i].t] > size[son[x]]) son[x] = e[i].t;
			mi = min(mi, w[e[i].t]);
			if (x > n) S[x - n].insert(w[e[i].t]);
		}
	if (x > n) w[x] = mi;
}
void buildc(int x, int top)
{
	tp[x] = top; pos[x] = ++ pcnt; b[pcnt] = w[x];
	if (son[x]) buildc(son[x], top);
	for (int i = h[x]; i; i = e[i].nxt)
		if (e[i].t != pre[x] && e[i].t != son[x])
			buildc(e[i].t, e[i].t);
}
int val[maxn * 4];
#define ls (p << 1)
#define rs (p << 1) | 1
void up(int p)
{
	val[p] = min(val[ls], val[rs]);
}
void builds(int p, int l, int r)
{
	if (l == r){
		val[p] = b[l]; return;
	}int mid = (l + r) >> 1;
	builds(ls, l, mid); builds(rs, mid + 1, r);
	up(p);
}
void modify(int p, int l, int r, int pos, int v)
{
	if (l == r){
		val[p] = v; return;
	}int mid = (l + r) >> 1;
	if (pos <= mid) modify(ls, l, mid, pos, v);
	else modify(rs, mid + 1, r, pos, v);
	up(p);
}
int gets(int p, int l, int r, int s, int t)
{
	if (l == s && r == t) return val[p];
	int mid = (l + r) >> 1;
	if (t <= mid) return gets(ls, l, mid, s, t);
	if (s > mid) return gets(rs, mid + 1, r, s, t);
	return min(gets(ls, l, mid, s, mid), gets(rs, mid + 1, r, mid + 1, t));
}
int get(int x, int y)
{
	int ret = oo;
	while (tp[x] != tp[y]){
		if (dep[tp[x]] < dep[tp[y]]) swap(x, y);
		ret = min(ret, gets(1, 1, n + cnt, pos[tp[x]], pos[x]));
		x = pre[tp[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	ret = min(ret, gets(1, 1, n + cnt, pos[x], pos[y]));
	if (x > n) ret = min(ret, w[pre[x]]);
	return ret;
}
int main()
{
	gn(n); gn(m); gn(q);
	for (int i = 1; i <= n; ++ i) gn(a[i]);
	for (int i = 1; i <= m; ++ i){
		gn(u); gn(v); ad(g, u, v);
	}
	dfs(1);
	build(1); buildc(1, 1);
	builds(1, 1, n + cnt);
	char s[20];
	while (q --){
		scanf("%s", s + 1);
		gn(u); gn(v);
		if (s[1] == 'C'){
			if (pre[u] > n){
				S[pre[u] - n].erase(S[pre[u] - n].find(w[u]));
				S[pre[u] - n].insert(v);
				w[pre[u]] = *(S[pre[u] - n].begin());
				modify(1, 1, n + cnt, pos[pre[u]], w[pre[u]]);
			}
			w[u] = v; modify(1, 1, n + cnt, pos[u], v);
		}else{
			printf("%d\n", get(u, v));
		}
	}
	return 0;
}