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
	if (opt) x = ~x + 1; 
}

template <class T>
inline void putint(T x) {
	static char buf[25], *tail = buf; 
	if (!x) putchar('0'); 
	else {
		if (x < 0) x = ~x + 1, putchar('-'); 
		for (; x; x /= 10) *++tail = x % 10 + '0'; 
		for (; tail != buf; --tail) putchar(*tail); 
	}
}

template <class T>
inline void relax(T &x, const T &y) {
	if (x < y) x = y; 
}

typedef long long s64; 

const int MaxN = 5e5 + 5; 

int n, K; 
int a[MaxN]; 
s64 ans = -(1LL << 62), cur; 
s64 s[MaxN], up[MaxN], suf[MaxN], sufSum[MaxN], sufAns[MaxN]; 

void work() {
	read(n), read(K); 
	for (int i = 1; i <= n; ++i) {
		read(a[i]); 
	}
	std::sort(a + 1, a + n + 1); 
	
	ans = 0; 
	for (int i = 1; i <= n; ++i) {
		ans += 1LL * a[i] * (i - 1); 
	}
	
	if (!K) {
		cout << ans << '\n'; 
		return; 
	}
	
	int mid = 0; 
	while (mid < n && a[mid + 1] < 0) ++mid; 
	
	s64 sum = 0, sumA = 0; 
	for (int i = mid + 1; i <= n; ++i) {
		sumA += 1LL * (i - mid - 1) * a[i]; 
		sum += a[i]; 
	}
	
	for (int i = mid, cur = 0; i >= 1; --i) {
		up[i] = (i + K <= mid ? up[i + K] : 0)+ a[i]; 
		suf[i] = suf[i + 1] + (i + K <= mid ? up[i + K] : 0); 
		sufSum[i] = sufSum[i + 1] + a[i]; 
		sufAns[i] = sufAns[i + 1] + sufSum[i + 1]; 
		
		s[i] = -(1LL << 62); 
	}
	
	s[0] = suf[1], cur = 0; 
	
	int d = 0; 
	for (int i = 1; i <= mid; ++i) {
		cur += 1LL * d * a[i]; 
//		cerr << i << ':' << suf[i] << '\n'; 
		
		if (i % (K + 1) == 0) {
			++d; 
			relax(s[d], cur + suf[i + 1] + sufSum[i + 1] * d); 
		}
		
		relax(s[d + (mid - i)], cur + sufAns[i + 1] + sufSum[i + 1] * d); 
	}
	
	for (int i = 0; i < mid; ++i) {
//		cerr << i << ' ' << s[i] << '\n'; 
		relax(ans, s[i] + 1LL * i * sum + sumA); 
	}
	
	cout << ans << '\n'; 
}

int main() {
#ifdef orzczk
	freopen("input.txt", "r", stdin); 
#endif

	int T = 1; 
//	read(T); 
	while (T--) {
		work(); 
	}
	
	return 0; 
}