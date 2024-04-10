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
	static char buf[45], *tail = buf; 
	if (!x)
		putchar('0'); 
	else
	{
		if (x < 0)
			putchar('-'), x = ~x + 1; 
		for (; x; x /= 10) *++tail = x % 10 + '0'; 
		for (; tail != buf; --tail) putchar(*tail); 
	}
}

template <class T>
inline bool tense(T &x, const T &y)
{
	return y < x ? x = y, true : false; 
}

template <class T>
inline bool relax(T &x, const T &y)
{
	return x < y ? x = y, true : false; 
}

using std::min; 
using std::max; 
using std::pair; 
using std::cin; 
using std::cout; 
using std::vector; 
typedef long long s64; 
typedef long double ld; 
typedef std::pair<int, int> pii; 
#define mp(x, y) std::make_pair(x, y)

const int MaxN = 2e5 + 5; 

struct node
{
	int pos, dis;
	node(){}
	node(int p, int d):
		pos(p), dis(d) {}
	inline bool operator < (node rhs) const
	{
		return dis > rhs.dis; 
	}
}; 

int n, m, K; 
int src, des, pos[MaxN]; 
int dis_s[MaxN], dis_t[MaxN]; 
bool only_t[MaxN]; 

std::vector<int> adj[MaxN], tadj[MaxN]; 
std::priority_queue<node> heap; 

int ind[MaxN], oud[MaxN]; 

inline void Dijkstra(int src, int *dis)
{
	static bool vis[MaxN]; 
	memset(dis, 0x3f, (n + 1) * 4); 
	memset(vis, false, (n + 1)); 

	while (!heap.empty())
		heap.pop(); 

	heap.push(node(src, dis[src] = 0)); 
	while (!heap.empty())
	{
		int u = heap.top().pos; 
		heap.pop(); 
		if (vis[u]) continue; 

		vis[u] = true; 
		for (int v : adj[u])
			if (tense(dis[v], dis[u] + 1))
				heap.push(node(v, dis[v])); 
	}
}

int main()
{
#ifdef orzczk
	freopen("a.in", "r", stdin); 
	freopen("a.out", "w", stdout); 
#endif

	read(n), read(m); 
	for (int i = 1; i <= m; ++i)
	{
		int u, v; 
		read(u), read(v); 
		adj[v].push_back(u); 
		tadj[u].push_back(v); 
	}

	read(K); 
	for (int i = 1; i <= K; ++i)
		read(pos[i]); 
	Dijkstra(des = pos[K], dis_t); 

	for (int u = 1; u <= n; ++u)
		only_t[u] = true; 

	for (int u = 1; u <= n; ++u)
	{
		int cnt = 0; 
		for (int v : tadj[u])
		{
			if (dis_t[u] - 1 == dis_t[v])
				++cnt; 
		}

	//	std::cout << u << ' ' << dis_t[u] << ' ' << cnt << '\n'; 
		if (cnt > 1)
			only_t[u] = false; 
	}

	int ans_min = 0, ans_max = 0; 
	for (int i = 1; i < K; ++i)
	{
		int cur = pos[i], nxt = pos[i + 1]; 

	//	std::cout << cur << ' ' << dis_t[cur] << ' ' << only_t[cur] << '\n'; 
		if (dis_t[cur] - 1 != dis_t[nxt])
			++ans_min, ++ans_max; 
		else if (!only_t[cur])
			++ans_max; 
	}

	std::cout << ans_min << ' ' << ans_max << '\n'; 

	return 0; 
}