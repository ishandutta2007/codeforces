#include <bits/stdc++.h>

namespace quick_io
{
	inline char nextChar()
	{
		static const int buffer_size = 2333333; 
		static char buffer[buffer_size]; 
		static const char *tail = buffer + buffer_size; 
		static char *head = buffer + buffer_size; 
		
		if (head == tail)
		{
			fread(buffer, 1, buffer_size, stdin); 
			head = buffer; 
		}
		return *head++; 
	}
	
	template <class T>
	inline void read(T &x)
	{
		static char ch; 
		while (!isdigit(ch = nextChar())); 
		x = ch - '0'; 
		while (isdigit(ch = nextChar()))
			x = x * 10 + ch - '0'; 
	}
	
	inline void read_opt(int &x)
	{
		static char ch; 
		while (ch = nextChar(), ch < 'a' || ch > 'v'); 
		x = ch - 'a'; 
	}
	
	const int buffer_size = 2333333; 
	char buffer[buffer_size]; 
	const char *tail = buffer + buffer_size; 
	char *head = buffer; 
	
	inline void putChar(const char &ch)
	{
		*head++ = ch; 
		if (head == tail)
			head = buffer, fwrite(buffer, 1, buffer_size, stdout); 
	}
	
	template <class T>
	inline void putint(T x)
	{
		static char buf[11]; 
		static char *tail = buf; 
		if (x)
		{
			for (; x; x /= 10) *++tail = x % 10 + '0'; 
			for (; tail != buf; --tail) putChar(*tail); 
		}
		else
			putChar('0'); 
	}
	
	inline void flush()
	{
		if (head != buffer)
			fwrite(buffer, 1, head - buffer, stdout); 
	}
}; 

using quick_io::read; 
using quick_io::read_opt; 
using quick_io::putChar; 
using quick_io::putint; 

template <class T>
inline bool relax(T &x, const T &y)
{
	return x < y ? x = y, true : false; 
}

typedef long long s64; 

const int MaxS = 5e6 + 5; 
const int MaxNV = 5e5 + 5; 
const int MaxNE = MaxNV << 1; 

struct halfEdge
{
	int v, code; 
	halfEdge *next; 
}adj_pool[MaxNE], *adj[MaxNV], *adj_tail = adj_pool; 

int n, dfs_clock; 
int ans[MaxNV], dis[MaxNV]; 
int sze[MaxNV], son[MaxNV], dep[MaxNV]; 
int fa[MaxNV], ldfn[MaxNV], rdfn[MaxNV], idx[MaxNV]; 

int max_dep[MaxS]; 

#define trav(u) for (int i = ldfn[u], v; v = idx[i], i <= rdfn[u]; ++i)

inline void addEdge(int u, int v, int w)
{
	adj_tail->v = v; 
	adj_tail->code = w; 
	adj_tail->next = adj[u]; 
	adj[u] = adj_tail++; 
}

inline void dfs_init(int u)
{
	sze[u] = 1; 
	idx[ldfn[u] = ++dfs_clock] = u; 
	
	for (halfEdge *e = adj[u]; e; e = e->next)
	{
		dep[e->v] = dep[u] + 1; 
		dis[e->v] = dis[u] ^ e->code; 
		
		dfs_init(e->v); 
		sze[u] += sze[e->v]; 
		if (sze[e->v] > sze[son[u]]) son[u] = e->v; 
	}
	
//	printf("%d:%d\n", u, son[u]); 
	
	rdfn[u] = dfs_clock; 
}

inline void dfs_solve(int u)
{
	for (halfEdge *e = adj[u]; e; e = e->next)
		if (e->v != son[u])
		{
			dfs_solve(e->v); 
			relax(ans[u], ans[e->v]); 
		}
	if (son[u]) dfs_solve(son[u]), relax(ans[u], ans[son[u]]); 
	
	relax(ans[u], max_dep[dis[u]] - dep[u]); 
	for (int i = 0; i < 22; ++i)
		relax(ans[u], max_dep[dis[u] ^ (1 << i)] - dep[u]); 
	relax(max_dep[dis[u]], dep[u]); 
	
	for (halfEdge *e = adj[u]; e; e = e->next)
		if (e->v != son[u])
		{
			trav(e->v)
			{
			//	printf("%d:%d %d\n", v, dep[v], dis[v]); 
				if (max_dep[dis[v]])
					relax(ans[u], max_dep[dis[v]] + dep[v] - 2 * dep[u]); 
				for (int i = 0; i < 22; ++i)
					if (max_dep[dis[v] ^ (1 << i)])
						relax(ans[u], max_dep[dis[v] ^ (1 << i)] + dep[v] - 2 * dep[u]); 
			}
			trav(e->v) relax(max_dep[dis[v]], dep[v]); 
		}
	
	if (u != son[fa[u]]) trav(u) max_dep[dis[v]] = 0; 
}

int main()
{
	read(n); 
	for (int i = 2; i <= n; ++i)
	{
		int w; 
		read(fa[i]), read_opt(w); 
		addEdge(fa[i], i, 1 << w); 
	}
	
	dfs_init(1); 
	dfs_solve(1); 
	
	for (int i = 1; i <= n; ++i)
		putint(ans[i]), putChar(' '); 
	
	quick_io::flush(); 
	return 0; 
}