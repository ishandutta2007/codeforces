#include <bits/stdc++.h>

using namespace std; 

template <class T>
inline void read(T &x) {
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
inline void putint(T x) {
	static char buf[45], *tail = buf; 
	if (!x)
		putchar('0'); 
	else {
		if (x < 0)
			putchar('-'), x = ~x + 1; 
		for (; x; x /= 10) *++tail = x % 10 + '0'; 
		for (; tail != buf; --tail) putchar(*tail); 
	}
}

template <class T>
inline bool tense(T &x, const T &y) {
	return y < x ? x = y, true : false; 
}

template <class T>
inline bool relax(T &x, const T &y) {
	return x < y ? x = y, true : false; 
}

template <class T>
inline T getAbs(const T &x) {
	return x < 0 ? -x : x; 
}

using std::cerr; 
using std::cout; 
typedef long long s64; 
typedef long double ld; 
typedef std::vector<int> vi; 
typedef std::pair<int, int> pii; 
#define mp(x, y) std::make_pair(x, y)

const int MaxN = 400000 + 5; 
const int mod = 1000000007; 

int n, a[MaxN], b[MaxN]; 
int ia[MaxN], ib[MaxN]; 

vector<int> adj[MaxN << 1]; 

void work() {
	read(n); 
	for (int i = 1; i <= n; ++i) {
		read(a[i]); 
		ia[a[i]] = i; 
	}
	for (int i = 1; i <= n; ++i) {
		read(b[i]); 
		ib[b[i]] = i; 
	}

	for (int i = 1; i <= n; ++i)
		adj[i].clear(); 
	
	for (int i = 1; i <= n; ++i) {
		adj[ia[i]].push_back(ib[i]); 
		adj[ib[i]].push_back(ia[i]); 

		// cerr << ia[i] << ' ' << ib[i] << '\n'; //
	}

	static bool vis[MaxN]; 
	fill(vis + 1, vis + n + 1, false); 

	auto bfs = [&](int src) {
		static int que[MaxN], qr; 
		vis[que[qr = 1] = src] = true; 

		for (int i = 1; i <= qr; ++i) {
			int u = que[i]; 
			for (int v : adj[u])
				if (!vis[v]) {
					vis[que[++qr] = v] = true; 	 
				}
		}
	}; 

	int res = 1; 
	for (int i = 1; i <= n; ++i)
		if (!vis[i]) {
			bfs(i); 
			res = 2LL * res % mod; 
		}
	
	printf("%d\n", res); 
}

int main() {
#ifdef orzczk
	freopen("a.in", "r", stdin); 
//	freopen("a.out", "w", stdout);  
#endif

	int T; 
	read(T); 
	while (T--) work(); 

	return 0; 
}