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

void work() {
	int R, C; 
	char s[100][100]; 

	int opt[2]; 
	memset(opt, 255, sizeof(opt)); 

	read(R), read(C); 

	bool flg = false; 
	for (int i = 1; i <= R; ++i) {
		scanf("%s", s[i] + 1); 

		for (int j = 1; j <= C; ++j)
			if (s[i][j] != '.') {
				int o = s[i][j] == 'R' ? 1 : 0; 

				if (opt[o] != -1 && (i + j) % 2 != opt[o]) {
					flg = true; 
				}

				opt[o] = (i + j) % 2; 
			}
	}

	if (flg || (~opt[0]) && (~opt[1]) && (opt[0] == opt[1]))
		puts("NO");
	else {
		puts("YES"); 

		if (opt[0] == -1 && opt[1] == -1) {
			opt[0] = 0, opt[1] = 1; 
		} else {
			if (opt[1] == -1) opt[1] = opt[0] ^ 1; 
			if (opt[0] == -1) opt[0] = opt[1] ^ 1; 
		}

		for (int i = 1; i <= R; ++i) {
			for (int j = 1; j <= C; ++j)
				printf("%c", (i + j) % 2 == opt[0] ? 'W' : 'R'); 
			putchar('\n'); 
		}
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