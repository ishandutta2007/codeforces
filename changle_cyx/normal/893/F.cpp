#include <bits/stdc++.h>

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

inline void putChar(char ch)
{
	static const int buffer_size = 2333333; 
	static char buffer[buffer_size]; 
	static const char *tail = buffer + buffer_size; 
	static char *head = buffer; 
	
	if (ch == '\0')
		fwrite(buffer, 1, head - buffer, stdout); 
	
	*head++ = ch; 
	if (head == tail)
		fwrite(buffer, 1, buffer_size, stdout), head = buffer; 
}

template <class T>
inline void putint(T x)
{
	static char buf[15]; 
	static char *tail = buf; 
	
	if (!x) putChar('0'); 
	else
	{
		for (; x; x /= 10) *++tail = x % 10 + '0'; 
		for (; tail != buf; --tail) putChar(*tail); 
	}
}

template <class T>
inline void relax(T &x, const T &y)
{
	if (x < y) x = y; 
}

template <class T>
inline void tense(T &x, const T &y)
{
	if (x > y) x = y; 
}

const int MaxNV = 1e5 + 5; 
const int MaxNE = MaxNV << 1; 
const int MaxS = MaxNV * 40; 

const int INF = 0x7fffffff; 

struct halfEdge
{
	int v; 
	halfEdge *next; 
}adj_pool[MaxNE], *adj_tail = adj_pool, *adj[MaxNV]; 

int n, Q; 
int rt, dfs_clock, max_dep; 

int ldfn[MaxNV], rdfn[MaxNV]; 
int a[MaxNV], dep[MaxNV]; 
std::vector<int> S[MaxNV]; 

int tot, seg[MaxNV]; 
int lc[MaxS], rc[MaxS], val[MaxS]; 

inline void copy(int x, int y)
{
	lc[x] = lc[y], rc[x] = rc[y], val[x] = val[y]; 
}

inline void addEdge(int u, int v)
{
	adj_tail->v = v; 
	adj_tail->next = adj[u]; 
	adj[u] = adj_tail++; 
}

inline void dfs_init(int u, int pre)
{
	ldfn[u] = ++dfs_clock; 
	
	relax(max_dep, dep[u] = dep[pre] + 1); 
	S[dep[u]].push_back(u); 
	
	for (halfEdge *e = adj[u]; e; e = e->next)
		if (e->v != pre)
			dfs_init(e->v, u); 
	
	rdfn[u] = dfs_clock; 
}

inline void insert(int lst, int &x, int l, int r, int pos, int del)
{
	copy(x = ++tot, lst); 
	tense(val[x], del); 
	
	if (l == r) return; 
	int mid = l + r >> 1; 
	if (pos <= mid)
		insert(lc[lst], lc[x], l, mid, pos, del); 
	else
		insert(rc[lst], rc[x], mid + 1, r, pos, del); 
}

inline int query_min(int x, int l, int r, int u, int v)
{
	if (!x) return INF; 
	if (u <= l && r <= v) return val[x]; 
	
	int mid = l + r >> 1, res = INF; 
	if (u <= mid)
		tense(res, query_min(lc[x], l, mid, u, v)); 
	if (v > mid)
		tense(res, query_min(rc[x], mid + 1, r, u, v)); 
	
	return res; 
}

int main()
{
	val[0] = INF; 
	
	read(n), read(rt); 
	for (int i = 1; i <= n; ++i)
		read(a[i]); 
	for (int i = 1; i < n; ++i)
	{
		int u, v; 
		read(u), read(v);
		addEdge(u, v), addEdge(v, u); 
	}
	
	dfs_init(rt, 0); 
	
	for (int i = 1; i <= max_dep; ++i)
	{
		std::vector<int> &T = S[i]; 
		
		int lst = seg[i - 1]; 
		for (int j = 0, jm = T.size(); j < jm; ++j)
		{
			int u = T[j]; 
			insert(lst, lst, 1, n, ldfn[u], a[u]); 
		}
		seg[i] = lst; 
	}
	
	read(Q); 
	
	int last_ans = 0; 
	while (Q--)
	{
		int u, k; 
		read(u), read(k); 
		u = (u + last_ans) % n + 1; 
		k = (k + last_ans) % n; 
		
		int d = std::min(max_dep, dep[u] + k); 
		
	//	if (n != 5) std::cout << u << ' ' << k << ' ' << d << ' ' << seg[d] << std::endl; 
		
		putint(last_ans = query_min(seg[d], 1, n, ldfn[u], rdfn[u])); 
		putChar('\n'); 
	}
	
	putChar('\0'); 
	return 0; 
}