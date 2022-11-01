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

const int mod = 1e9 + 7; 
inline void add(int &x, const int &y) {
	if (x += y, x >= mod) x -= mod; 
}
inline void dec(int &x, const int &y) {
	if (x -= y, x < 0) x += mod; 
}

const int MaxN = 1e6 + 5; 

int n; 
int f[MaxN]; 
char s[MaxN]; 

int pre[MaxN], pos[MaxN]; 
int nxt[MaxN][2]; 

int main() {
#ifdef orzczk
	freopen("a.in", "r", stdin); 
#endif

	scanf("%s", s + 1); 
	n = strlen(s + 1); 

	bool all0 = true; 
	for (int i = n - 1; i >= 0; --i) {
		nxt[i][0] = nxt[i + 1][0]; 
		nxt[i][1] = nxt[i + 1][1]; 
		nxt[i][s[i + 1] - '0'] = i + 1; 
	}
	for (int i = 1; i <= n; ++i) {
		pre[i] = s[i] == '0' ? pre[i - 1] + 1 : 0; 
	}

	for (int i = 1; i <= n; ++i) {
		all0 &= s[i] == '0'; 
	}

	if (all0) {
		printf("%d\n", n); 
		return 0; 
	}

	for (int i = n, sum = 0; i >= 1; --i) {
		if (s[i] == '0') {
			f[i] = pre[i] < i && pre[i] <= pre[n]; 

			if (s[i + 1] == '0') {
				add(f[i], f[i + 1]); 
			} else if (pre[i] < i && pos[pre[i] + 1]) {
				add(f[i], f[pos[pre[i] + 1]]); 
			}

			if (nxt[i][1]) {
				add(f[i], f[nxt[i][1]]); 
			}

			pos[pre[i]] = i; 
		} else {
			f[i] = 1; 
			if (nxt[i][0]) {
				add(f[i], f[nxt[i][0]]); 
			} 
			if (nxt[i][1]) {
				add(f[i], f[nxt[i][1]]); 
			}
		}

		// std::cout << s[i] << ':' << i << ' ' << pre[i] << ' ' << f[i] << '\n'; 
	}

	if (s[1] == '0')
		std::cout << (f[1] + f[nxt[0][1]]) % mod << '\n'; 
	else
		std::cout << f[1] << '\n'; 

	return 0; 
}