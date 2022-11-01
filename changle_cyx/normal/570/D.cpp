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
	
	inline void read_string(char *s)
	{
		static char ch; 
		while (ch = nextChar(), ch < 'a' || ch > 'z'); 
		*s++ = ch; 
		while (ch = nextChar(), ch >= 'a' && ch <= 'z')
			*s++ = ch; 
	}
}; 

using quick_io::read; 
using quick_io::read_string; 

const int MaxS = 1e7 + 5; 
const int MaxNV = 5e5 + 5; 
const int MaxNE = MaxNV << 2; 

struct halfEdge
{
	int v; 
	halfEdge *next; 
}adj_pool[MaxNE], *adj[MaxNV], *adj_tail = adj_pool; 

int n, Q, dfs_clock; 
int dep[MaxNV], fa[MaxNV], ldfn[MaxNV], rdfn[MaxNV]; 

char ch[MaxNV]; 
int tot, rt[MaxNV], lc[MaxS], rc[MaxS], sum[MaxS]; 

inline bool check(int x) {return !x || (x & -x) == x;}
inline bool cmp(const int &a, const int &b) {return dep[a] < dep[b];}
inline void change(int x, int y) {lc[x] = lc[y], rc[x] = rc[y], sum[x] = sum[y];}

inline void addEdge(int u, int v)
{
	adj_tail->v = v; 
	adj_tail->next = adj[u]; 
	adj[u] = adj_tail++; 
}

inline void dfs_init(int u)
{
	ldfn[u] = ++dfs_clock; 
	for (halfEdge *e = adj[u]; e; e = e->next)
	{
		dep[e->v] = dep[u] + 1; 
		dfs_init(e->v); 
	}
	rdfn[u] = dfs_clock; 
}

inline void insert(int lst, int &x, int l, int r, int pos, int opt)
{
	change(x = ++tot, lst); 
	sum[x] ^= opt; 
	if (l == r) return; 
	
	int mid = l + r >> 1; 
	pos <= mid ? insert(lc[lst], lc[x], l, mid, pos, opt) : insert(rc[lst], rc[x], mid + 1, r, pos, opt); 
}

inline int query(int x, int l, int r, int u, int v)
{
	if (!x) return 0; 
	if (u <= l && r <= v) return sum[x]; 
	int mid = l + r >> 1, res = 0; 
	if (u <= mid)
		res ^= query(lc[x], l, mid, u, v); 
	if (v > mid)
		res ^= query(rc[x], mid + 1, r, u, v); 
	return res; 
}

int main()
{
	read(n), read(Q); 
	for (int i = 2; i <= n; ++i)
	{
		read(fa[i]); 
		addEdge(fa[i], i); 
	}
	
	read_string(ch + 1); 
	dfs_init(dep[1] = 1); 
	
	for (int i = 1; i <= n; ++i)
		insert(rt[dep[i]], rt[dep[i]], 1, n, ldfn[i], 1 << ch[i] - 'a'); 
	
	for (int i = 1; i <= Q; ++i)
	{
		int u, h; 
		read(u), read(h); 
	//	printf("::%d\n", query(rt[h], 1, n, ldfn[u], rdfn[u]));
		puts(check(query(rt[h], 1, n, ldfn[u], rdfn[u])) ? "Yes" : "No"); 
	}
	
	return 0; 
}