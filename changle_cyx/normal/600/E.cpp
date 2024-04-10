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
using quick_io::putChar; 
using quick_io::putint; 

template <class T>
inline bool relax(T &x, const T &y)
{
	return x < y ? x = y, true : false; 
}

typedef long long s64; 
const int MaxNV = 1e5 + 5; 
const int MaxNE = MaxNV << 1; 

struct halfEdge
{
	int v; 
	halfEdge *next; 
}adj_pool[MaxNE], *adj[MaxNV], *adj_tail = adj_pool; 

s64 ans[MaxNV]; 
int max_sze[MaxNV]; 

int cnt[MaxNV], fa[MaxNV]; 
int n, dfs_clock, c[MaxNV]; 
int sze[MaxNV], son[MaxNV]; 
int ldfn[MaxNV], rdfn[MaxNV], idx[MaxNV]; 

inline void addEdge(int u, int v)
{
	adj_tail->v = v; 
	adj_tail->next = adj[u]; 
	adj[u] = adj_tail++; 
}

inline void clear(int u)
{
	int l = ldfn[u], r = rdfn[u]; 
	for (int i = l; i <= r; ++i)
		--cnt[c[idx[i]]]; 
}

inline void dfs_init(int u) 
{
	sze[u] = 1; 
	idx[ldfn[u] = ++dfs_clock] = u; 
	for (halfEdge *e = adj[u]; e; e = e->next)
		if (e->v != fa[u])
		{
			fa[e->v] = u; 
			dfs_init(e->v); 
			
			sze[u] += sze[e->v]; 
			if (sze[e->v] > sze[son[u]])
				son[u] = e->v; 
		}
	rdfn[u] = dfs_clock; 
}

inline void dfs_solve(int u)
{
	for (halfEdge *e = adj[u]; e; e = e->next)
		if (e->v != fa[u] && e->v != son[u])
			dfs_solve(e->v); 
	
	if (son[u])
		dfs_solve(son[u]), max_sze[u] = max_sze[son[u]], ans[u] = ans[son[u]]; 
	if (relax(max_sze[u], ++cnt[c[u]]))
		ans[u] = c[u]; 
	else if (max_sze[u] == cnt[c[u]])
		ans[u] += c[u]; 
	
	for (halfEdge *e = adj[u]; e; e = e->next)
		if (e->v != fa[u] && e->v != son[u])
		{
			int l = ldfn[e->v], r = rdfn[e->v]; 
			for (int i = l; i <= r; ++i)
				if (relax(max_sze[u], ++cnt[c[idx[i]]]))
					ans[u] = c[idx[i]]; 
				else if (max_sze[u] == cnt[c[idx[i]]])
					ans[u] += c[idx[i]]; 
		}
	if (u != son[fa[u]]) clear(u); 
}

int main()
{
	read(n); 
	for (int i = 1; i <= n; ++i)
		read(c[i]); 
	for (int i = 1; i < n; ++i)
	{
		int u, v; 
		read(u), read(v); 
		addEdge(u, v), addEdge(v, u); 
	}
	
	dfs_init(1), dfs_solve(1); 
	
	for (int i = 1; i <= n; ++i)
		putint(ans[i]), putChar(' ');
	
	quick_io::flush(); 
	return 0; 
}