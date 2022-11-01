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

const int MaxN = 1000 + 5; 

void work() {
	int n; 
	int top = 0; 
	static int req[MaxN], lst[MaxN], a[MaxN]; 

	read(n); 	
	for (int i = 1; i <= n; ++i) {
		read(req[i]); 
	}

	for (int i = 1; i <= n; ++i) {
		int x = req[i]; 

		if (x == 1) {
			a[++top] = x; 
			
		} else {
			while (a[top] + 1 != x) {
				--top; 
			}
			++a[top]; 
		}
		
		for (int j = 1; j < top; ++j)
			printf("%d.", a[j]); 
		printf("%d\n", a[top]); 
	}
}

int main() {
#ifdef orzczk
	freopen("/mnt/c/cyx/project/a.in", "r", stdin); 
//	freopen("/mnt/c/cyx/project/a.out", "w", stdout);  
#endif

	int T; 
	read(T); 

	while (T--) work(); 

	return 0; 
}