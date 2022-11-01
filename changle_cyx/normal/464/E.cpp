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

template <class T>
inline void relax(T &x, const T &y)
{
	if (x < y) x = y; 
}

const int MaxNV = 1e5 + 555; 
const int MaxNE = 2e5 + 5; 
const int MaxS = MaxNV * 100; 

const int base = 2; 
const int mod1 = 1e9 + 7; 
const int mod2 = 1e9 + 9; 

#define change(x, y) lc[x] = lc[y], rc[x] = rc[y], len[x] = len[y], sze[x] = sze[y], suf[x] = suf[y], val1[x] = val1[y], val2[x] = val2[y]

struct halfEdge
{
	int v, w; 
	halfEdge *next; 
}adj_pool[MaxNE], *adj[MaxNV], *adj_tail = adj_pool; 

int n, m, src, des, lim, ans;
int p1[MaxNV], p2[MaxNV], rt[MaxNV], pre[MaxNV]; 

int tot, len[MaxS], val1[MaxS], val2[MaxS]; 
int lc[MaxS], rc[MaxS], sze[MaxS], suf[MaxS]; 

bool vis[MaxNV]; 

inline void addEdge(int u, int v, int w)
{
	adj_tail->v = v; 
	adj_tail->w = w; 
	adj_tail->next = adj[u]; 
	adj[u] = adj_tail++; 
}

inline void print(int x, int l, int r)
{
//	printf("prt %d:l = %d, r = %d, sze = %d, suf = %d\n:", x, l, r, sze[x], suf[x]); 
	if (!x || !sze[x]) return; 
	if (l == r) return (void)(ans = (ans + p1[l]) % mod1); 
	int mid = l + r >> 1; 
	print(lc[x], l, mid), print(rc[x], mid + 1, r); 
}

inline void upt(int x, int l, int r)
{
	int lenr = r - (l + r >> 1); 
	
	sze[x] = sze[lc[x]] + sze[rc[x]]; 
	suf[x] = sze[rc[x]] == lenr ? lenr + suf[lc[x]] : suf[rc[x]]; 
	
	val1[x] = (1LL * val1[lc[x]] * p1[lenr] + val1[rc[x]]) % mod1; 
	val2[x] = (1LL * val2[lc[x]] * p2[lenr] + val2[rc[x]]) % mod2; 
}

inline void insert(int lst, int &x, int l, int r, int pos)
{
	x = ++tot; 
	change(x, lst); 
	
	if (l == r)
	{
		sze[x] = suf[x] = val1[x] = val2[x] = 1; 
		return; 
	}
	
	int mid = l + r >> 1; 
	pos <= mid ? insert(lc[lst], lc[x], l, mid, pos) : insert(rc[lst], rc[x], mid + 1, r, pos); 
	upt(x, l, r); 
}

inline void del(int lst, int &x, int l, int r, int u, int v)
{
	if (u <= l && r <= v) return (void)(x = 0); 
	
	x = ++tot; 
	change(x, lst); 
	
	int mid = l + r >> 1; 
	if (u <= mid) del(lc[lst], lc[x], l, mid, u, v); 
	if (v > mid) del(rc[lst], rc[x], mid + 1, r, u, v); 
	
	upt(x, l, r); 
}

inline int query_suf(int x, int l, int r, int pos)
{
//	printf("query:%d %d %d %d %d\n", x, l, r, pos, suf[lc[x]]); 
	if (!x || !sze[x]) return std::max(l, pos); 
	int mid = l + r >> 1; 
	if (pos > mid || suf[lc[x]] >= mid - pos + 1)
		return query_suf(rc[x], mid + 1, r, std::max(pos, mid + 1)); 
	else
		return query_suf(lc[x], l, mid, pos); 
}

inline bool cmp(int x, int y, int l, int r)
{
	if (l == r) return sze[x] > sze[y]; 
	int mid = l + r >> 1; 
	if (val1[rc[x]] == val1[rc[y]] && val2[rc[x]] == val2[rc[y]])
		return cmp(lc[x], lc[y], l, mid); 
	else
		return cmp(rc[x], rc[y], mid + 1, r); 
}

struct node
{
	int pos, u; 
	node(){}
	node(int a, int b):
		pos(a), u(b) {}
	inline bool operator < (const node &rhs) const
	{
		return cmp(u, rhs.u, 0, lim); 
	}
}; 

std::priority_queue<node> heap; 

inline void dfs(int u, int dep)
{
	if (u == src)
	{
		printf("%d\n%d ", dep, u); 
		return; 
	}
	dfs(pre[u], dep + 1); 
	printf("%d ", u); 
}

int main()
{
//	freopen("tt.in", "r", stdin); 
	
	read(n), read(m); 
	for (int i = 1; i <= m; ++i)
	{
		int u, v, w; 
		read(u), read(v), read(w); 
		addEdge(u, v, w); 
		addEdge(v, u, w); 
		relax(lim, w); 
	}
	lim += 200; 
	read(src), read(des); 
	
	p1[0] = p2[0] = 1; 
	for (int i = 1; i <= lim; ++i)
		p1[i] = 2LL * p1[i - 1] % mod1, p2[i] = 2LL * p2[i - 1] % mod2; 
	
	rt[src] = tot = 1, len[1] = lim + 1; 
	heap.push(node(src, 1)); 
	while (!heap.empty())
	{
		node now = heap.top(); 
		heap.pop(); 
		
		int u = now.pos; 
		if (now.u != rt[u]) continue; 
		
	//	ans = 0; 
	//	printf("u:::%d-----\n", u); 
	//	print(rt[u], 0, lim); 
	//	printf("ans:%d\n", ans); 
		
		vis[u] = true; 
		if (u == des)
		{
			print(rt[des], 0, lim); 
			printf("%d\n", ans); 
			dfs(des, 1); 
			return 0; 
		}
		
		for (halfEdge *e = adj[u]; e; e = e->next)
			if (!vis[e->v])
			{
				int nxt; 
			//	printf("(%d %d : %d %d\n", u, e->v, e->w, query_suf(rt[u], 0, lim, e->w)); 
				int pos = query_suf(rt[u], 0, lim, e->w); 
				insert(rt[u], nxt, 0, lim, query_suf(rt[u], 0, lim, e->w)); 
				if (e->w < pos)
					del(nxt, nxt, 0, lim, e->w, pos - 1); 
				if (!rt[e->v] || cmp(rt[e->v], nxt, 0, lim))
					heap.push(node(e->v, rt[e->v] = nxt)), pre[e->v] = u; 
			}
	}
	puts("-1"); 
	
	return 0; 
}