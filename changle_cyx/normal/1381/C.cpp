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

typedef long long s64; 
typedef long double ld; 
typedef std::vector<int> vi; 
typedef std::pair<int, int> pii; 
#define mp(x, y) std::make_pair(x, y)

const int MaxN = 1e5 + 5; 

int n, m, X, Y; 
int a[MaxN], ans[MaxN]; 

int mis; 
std::vector<int> pos[MaxN]; 

struct cmpSize {
	inline bool operator () (int a, int b) {
		return pos[a].size() < pos[b].size(); 
	}
}; 

std::priority_queue<int, std::vector<int>, cmpSize> heap; 

inline bool check() {
	int x = 0 ;
	for (int i = 1; i <= n; ++i)
		x += a[i] == ans[i]; 
	return x == X; 
}

inline bool cmp(int x, int y) {
	return (a[x] == ans[x]) > (a[y] == ans[y]); 
}

void work() {
	while (!heap.empty()) heap.pop(); 

	read(n), read(X), read(Y); 
	m = n + 1; 

	for (int i = 1; i <= m; ++i)
		pos[i].clear(); 
	for (int i = 1; i <= n; ++i) {
		read(a[i]); 
		pos[a[i]].push_back(i); 
	}

	for (int i = 1; i <= m; ++i)
		if (pos[i].empty()) {
			mis = i; 
		} else {
			heap.push(i); 
		}
	
	int rem = n; 
	for (int i = 1; i <= X; ++i) {
		int c = heap.top(); 
		heap.pop(), --rem; 

		// std::cerr << "match : " << c << ' ' << pos[c].back() << '\n'; 

		ans[pos[c].back()] = c; 
		pos[c].pop_back(), heap.push(c); 
	}

	std::deque<int> S; 
	std::vector<int> V; 
	while (!heap.empty()) {
		int c = heap.top(); 
		heap.pop(); 

		for (int i = 0; i < (int)pos[c].size(); ++i) {
			V.push_back(pos[c][i]); 
			S.push_back(pos[c][i]); 
		}
	}
	
	for (int i = 0; i < rem; ++i) {
		int p = V[i], q; 
		if (a[S.back()] == a[V[i]])
			q = S.front(), S.pop_front(); 
		else
			q = S.back(), S.pop_back(); 
		
		ans[p] = a[q]; 
	}

	std::sort(V.begin(), V.end(), cmp); 
	for (int i = 0; i < n - Y; ++i) {
		ans[V[i]] = mis; 
	}

	if (!check()) {
		puts("NO"); 
		return; 
	}

	puts("YES"); 
	for (int i = 1; i <= n; ++i) {
		printf("%d%c", ans[i], " \n"[i == n]); 
	}
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