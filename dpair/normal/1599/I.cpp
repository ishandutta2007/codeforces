#include <bits/stdc++.h>
using namespace std;

template<class T> void read(T &x)
{
	x = 0; int f = 0;
	char c = getchar();
	while (c < '0' || c > '9') f |= (c == '-'), c = getchar();
	while (c >='0' && c <='9') x = (x << 1) + (x << 3) + (c^48), c = getchar();
	if (f) x = -x;
}
template<class T> bool umax(T &x , T y) {return y>x ? x=y, 1: 0; }
template<class T> bool umin(T &x , T y) {return y<x ? x=y, 1: 0; }
typedef long long ll;

const int N = 1e6+5, inf = 1e9;
int n,m,q,vis[N],flag=0, minr[N],db;

#define Get(x) (ch[fa[x]][1] == x)
#define isRoot(x) (ch[fa[x]][0] != x && ch[fa[x]][1] != x)
#define ls ch[x][0]
#define rs ch[x][1]

struct edge { int u,v,eg; }e[N];
int ch[N][2], fa[N], mx[N], val[N], tag[N], tim[N], mi[N], add_tag[N];

/* mx mi  */
void Pushup(int x)
{
	// siz[x] = siz[ls] + siz[rs] + val[x];
	if (x > n) mx[x] = val[x];
	else mx[x] = 0;
	mi[x] = x;
	// val[0] = 0;
	if (ls && tim[mi[ls]] < tim[mi[x]]) mi[x] = mi[ls];
	if (rs && tim[mi[rs]] < tim[mi[x]]) mi[x] = mi[rs];
	if (ls) umax(mx[x],mx[ls]);
	if (rs) umax(mx[x],mx[rs]);
}

void Pushdown(int x)
{
	if (tag[x]) 
	{
		swap(ch[ls][0], ch[ls][1]);
		swap(ch[rs][0], ch[rs][1]);
		tag[ls] ^= 1; tag[rs] ^= 1;
		tag[x] = 0;
	}
	if (ls) add_tag[ls] += add_tag[x]; 
	if (rs) add_tag[rs] += add_tag[x];
	if (ls) val[ls] += add_tag[x];
	if (rs) val[rs] += add_tag[x];
	if (ls) mx[ls] += add_tag[x];
	if (rs) mx[rs] += add_tag[x];
	add_tag[x] = 0;
}

void Rotate(int x)
{
	int y = fa[x], z = fa[y], k = Get(x);
	if (!isRoot(y)) ch[z][Get(y)] = x;
	fa[ch[x][!k]] = y; ch[y][k] = ch[x][!k];
	ch[x][!k] = y; fa[x] = z; fa[y] = x;
	Pushup(y); Pushup(x);
}
void Update(int x)
{
	// if (db) cout << x << " " << add_tag[x] << " " << mx[x] << " !!!\n";
	if (!isRoot(x)) Update(fa[x]);
	Pushdown(x);
}
void Splay(int x)
{
	Update(x);
	for (int pa = 0; pa = fa[x], !isRoot(x); Rotate(x))
		if (!isRoot(pa)) Rotate(Get(pa) == Get(x) ? pa : x);
}
int Access(int x)
{
	int R;
	for (R = 0; x; R = x, x = fa[x])
	{
		Splay(x);
		rs = R;
		Pushup(x);
	}
	return R;
}
void Makeroot(int x)
{
	int tp = Access(x);
	tag[tp] ^= 1;
	swap(ch[tp][0], ch[tp][1]);
	Splay(x);
}
int Find(int x)
{
	Access(x); Splay(x);
	while (ls) Pushdown(x), x = ls;
	Splay(x);
	return x;
}

bool Link(int x, int y)
{
	Makeroot(x);
	if (Find(y) == x) return 0;
	fa[x] = y;
	return 1;
}

bool Cut(int x, int y)
{
	Makeroot(x);
	if (Find(y)==x && !ch[y][0] && fa[y] == x)
	{
		ch[x][1] = fa[y] = 0;
		Pushup(x); Splay(x);
		return 1;
	}
	return 0;
}

int curt = 0;
bool try_add(int i)
{
	int u = e[i].u, v = e[i].v, md = e[i].eg;
	Makeroot(u);
	if (Find(v) == u)
	{
		Makeroot(u); Access(v); Splay(v);

		if (mx[v] >= 1) return 0;
		val[v]++; add_tag[v]++; mx[v]++; Splay(u);

		int j = mi[v] - n;
 		Cut(e[j].u,e[j].eg);
		Cut(e[j].v,e[j].eg);
		val[md] = 1;
	}
	Link(u,md);
	Link(v,md);
	return 1;
}
void dfs(int x)
{
	if (ls) cout << x << " -> " << ls << "\n", dfs(ls);
	if (rs) cout << x << " -> " << rs << "\n", dfs(rs);
}

void delet(int i)
{
	int u = e[i].u, v = e[i].v, md = e[i].eg;
	Makeroot(u); Access(v); Splay(v);
	val[v]--; add_tag[v]--; mx[v]--; Splay(u);
	val[md] = 0;
	int t1 = Cut(u, md); 
	int t2 = Cut(v, md);
}

int main()
{
	read(n); read(m);
	memset(tim,0x3f,sizeof(tim));
	memset(val,0,sizeof(val));
	memset(mx,0,sizeof(mx));
	/* val[i]i */
	/* >n */

	for (int i = 1; i <= m; ++i)
	{
		read(e[i].u);
		read(e[i].v);
		e[i].eg = n+i;
		tim[n+i] = i;
	}

	/* lstlst = -1 */
	ll ans = 0;
	int cannot = 0;
	for (int i = 1, j = 0; i <= m; ++i)
	{
		while (j < m && try_add(j+1)) ++j;
		ans += j - i + 1; delet(i);
	}
	cout << ans << endl;
	return 0;
}
/* 

*/