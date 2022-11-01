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

const int MaxN = 2000 + 5; 

int n; 
int dep[MaxN]; 
vector<int> ver[MaxN]; 
vector<pair<int, int> > ans; 

int dis[MaxN][MaxN]; 
bool vis[MaxN][MaxN]; 

void ask(int x, int *d) {
	printf("? %d\n", x); 
	fflush(stdout); 

	for (int i = 1; i <= n; ++i) {
		scanf("%d", d + i); 
	}
}

void push(int u, int v) {
	if (!vis[u][v]) {
		ans.emplace_back(u, v); 
		vis[u][v] = vis[v][u] = true; 
	}
}

int main() {
	memset(dis, 255, sizeof(dis));
	
	read(n); 
	ask(1, dis[1]); 

	int maxdep = 0; 
	static int cnt[2]; 

	for (int i = 1; i <= n; ++i) {
		dep[i] = dis[1][i]; 
		ver[dep[i]].push_back(i); 
		maxdep = max(maxdep, dep[i]); 

		++cnt[dep[i] & 1]; 
	}

	if (cnt[0] - 1 <= cnt[1]) {
		for (int i = 2; i <= maxdep; i += 2)
			for (int x : ver[i]) ask(x, dis[x]); 
	} else {
		for (int i = 1; i <= maxdep; i += 2)
			for (int x : ver[i]) ask(x, dis[x]); 
	}

	
	for (int x = 1; x <= n; ++x)
		if (dis[x][1] != -1)
			for (int y = 1; y <= n; ++y)
				if (dis[x][y] == 1)
					push(x, y); 

	puts("!"); 
	for (pii p : ans)
		printf("%d %d\n", p.first, p.second); 

	return 0; 
}