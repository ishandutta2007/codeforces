#include <bits/stdc++.h>

template <class T>
inline void read(T &x)
{
	static char ch; 
	static bool opt; 
	while (!isdigit(ch = getchar()) && ch != '-'); 
	x = (opt = ch == '-') ? 0 : ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
	if (opt)
		x = ~x + 1; 
}

template <class T>
inline void putint(T x)
{
	static char buf[25], *tail = buf; 

	if (x < 0)
	{
		x = ~x + 1; 
		putchar('-'); 
	}

	if (!x)
		putchar('0'); 
	else
	{
		for (; x; x /= 10) *++tail = x % 10 + '0'; 
		for (; tail != buf; --tail) putchar(*tail); 
	}
}

template <class T>
inline void tense(T &x, const T &y)
{
	if (x > y)
		x = y; 
}

template <class T>
inline void relax(T &x, const T &y)
{
	if (x < y)
		x = y; 
}

const int MaxN = 4e5 + 5; 
const int MaxNV = MaxN << 2; 
const int MaxNE = 5e6 + 5; 

int n, m1, m2, M; 
int opt[MaxN]; 

int ect, to[MaxNE], nxt[MaxNE], adj[MaxNV]; 

int dfs_clock, dfn[MaxNV], low[MaxNV]; 
int top, stk[MaxNV], col[MaxNV], totcol; 

int lef[MaxN], rit[MaxN]; 

#define trav(u) for (int e = adj[u], v; v = to[e], e; e = nxt[e])

inline int get_pos(int a, int o)
{
	if (o <= 1)
		return a + o * n; 
	else
		return a + (n << 1) + (o - 2) * M; 
}

inline void addEdge(int u, int v)
{
	nxt[++ect] = adj[u]; 
	adj[u] = ect; 
	to[ect] = v; 
}

inline void Tarjan(int u)
{
	dfn[u] = low[u] = ++dfs_clock; 
	stk[++top] = u; 
	
	trav(u)
		if (!dfn[v])
			Tarjan(v), tense(low[u], low[v]); 
		else if (!col[v])
			tense(low[u], dfn[v]); 

	if (dfn[u] == low[u])
	{
		++totcol; 

		int v; 
		do
		{
			v = stk[top--]; 
			col[v] = totcol; 
		}while (v != u); 
	}
}

int main()
{
#ifdef orzczk
	freopen("input.txt", "r", stdin); 
#endif

	read(m1), read(n), read(M), read(m2); 

	for (int i = 1; i < M; ++i)
	{
		addEdge(get_pos(i, 3), get_pos(i + 1, 3)); 
		addEdge(get_pos(i + 1, 2), get_pos(i, 2)); 
	}

	for (int i = 1; i <= m1; ++i)
	{
		int x, y; 
		read(x), read(y); 
		addEdge(get_pos(x, 0), get_pos(y, 1)); 
		addEdge(get_pos(y, 0), get_pos(x, 1)); 
	}

	for (int i = 1; i <= n; ++i)
	{	
		read(lef[i]), read(rit[i]); 

		addEdge(get_pos(i, 1), get_pos(rit[i], 3)); 
		addEdge(get_pos(rit[i], 2), get_pos(i, 0)); 

		if (lef[i] > 1)
		{
			addEdge(get_pos(i, 1), get_pos(lef[i] - 1, 2)); 
			addEdge(get_pos(lef[i] - 1, 3), get_pos(i, 0)); 
		}
	}

	for (int i = 1; i <= m2; ++i)
	{
		int x, y; 
		read(x), read(y); 
		addEdge(get_pos(x, 1), get_pos(y, 0)); 
		addEdge(get_pos(y, 1), get_pos(x, 0)); 
	}
	 
	for (int i = 1; i <= (n << 1) + (M << 1); ++i)
		if (!dfn[i])
			Tarjan(i); 

	int final_lef = 1, final_rit = M, tot = 0; 
	for (int i = 1; i <= n; ++i)
	{
		if (col[get_pos(i, 0)] == col[get_pos(i, 1)])
			return puts("-1"), 0; 

		opt[i] = col[get_pos(i, 0)] > col[get_pos(i, 1)]; 
		if (opt[i])
		{
			++tot; 
			tense(final_rit, rit[i]); 
			relax(final_lef, lef[i]); 
		}
	}

	if (final_rit < final_lef)
		return puts("-1"), 0; 

	printf("%d %d\n", tot, final_lef); 
	for (int i = 1; i <= n; ++i)
		if (opt[i])
			putint(i), putchar(' '); 

	puts(""); 

	return 0; 
}