#include <bits/stdc++.h>

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

const int MaxN = 1e5 + 5; 

int n, m, a[MaxN]; 
vi idx[MaxN]; 

void work() {
	std::map<int, int> vis; 

	read(n), m = 0; 
	for (int i = 1; i <= n; ++i) {
		read(a[i]); 

		if (vis.find(a[i]) == vis.end()) {
			idx[m + 1].clear(); 
			vis[a[i]] = ++m; 
		}

		idx[vis[a[i]]].push_back(i); 
	}

	s64 sum = 0; 

	for (int v = 1; v <= m; ++v) {
		int c = idx[v].size(); 
		s64 pre = 0; 

		for (int i = 0; i < c; ++i) {
			sum += 1LL * (n + 1) * idx[v][i] * (c - i - 1); 
			sum -= 1LL * idx[v][i] * pre; 
			pre += idx[v][i]; 
		}
	}

	printf("%lld\n", sum); 
}

int main() {
#ifdef orzczk
	freopen("a.in", "r", stdin); 
#endif

	int T; 
	read(T); 
	while (T--) work(); 

	return 0; 
}