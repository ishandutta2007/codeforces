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

int n, m, x; 
int h[MaxN]; 

struct node {
	int x, h; 
	inline bool operator < (const node &rhs) const {
		return h > rhs.h; 
	}
}; 

void work() {
	read(n), read(m), read(x); 
	for (int i = 1; i <= n; ++i) {
		read(h[i]); 
	}

	// static int p[MaxN]; 
	// for (int i = 1; i <= n; ++i) p[i] = i; 

	// std::sort(p + 1, p + n + 1, [&](int x, int y) {
	// 	return h[x] < h[y]; 
	// }); 

	static int ans[MaxN]; 
	std::priority_queue<node> heap; 

	for (int i = 1; i <= m; ++i) heap.push((node){i, 0}); 

	for (int i = 1; i <= n; ++i) {
		node t = heap.top(); 
		heap.pop(); 

		ans[i] = t.x; 
		heap.push((node){t.x, t.h + h[i]});  
	}

	puts("YES"); 
	for (int i = 1; i <= n; ++i)
		printf("%d%c", ans[i], " \n"[i == n]); 
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