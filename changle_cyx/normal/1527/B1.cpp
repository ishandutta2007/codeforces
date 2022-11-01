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

int n; 
int f[MaxN][MaxN][2][2]; //min : first - second

char s[MaxN]; 

void work() {
	read(n); 
	scanf("%s", s + 1); 

	int cnt0 = 0, cnt1 = 0; 
	for (int i = 1; i <= (n >> 1); ++i) {
		cnt0 += s[i] == '0' && s[n - i + 1] == '0'; 
		cnt1 += s[i] != s[n - i + 1]; 
	}
	
	int res = f[cnt0][cnt1][(n & 1) && s[(n + 1) >> 1] == '0'][0]; 

	// cerr << cnt0 << ' ' << cnt1 << ' ' << ((n & 1) && s[(n + 1) >> 1] == '0') << ':' << res << '\n'; 

	puts(res ? (res > 0 ? "BOB" : "ALICE") : "DRAW"); 
}

int main() {
#ifdef orzczk
	freopen("a.in", "r", stdin); 
#endif

	memset(f, 0x3f, sizeof(f)); 

	int m = 1000;
	
	f[0][0][0][0] = f[0][0][0][1] = 0; 
	
	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j <= m; ++j)
			for (int opt = 0; opt <= 1; ++opt) 
				for (int ban = 1; ban >= 0; --ban) {
					if (i + j + opt == 0) continue; 

					if (!ban && j) {
						tense(f[i][j][opt][ban], -f[i][j][opt][ban ^ 1]); 
					}
					
					if (i)
						tense(f[i][j][opt][ban], -f[i - 1][j + 1][opt][0] + 1); 
					if (j)
						tense(f[i][j][opt][ban], -f[i][j - 1][opt][0] + 1); 
					if (opt)
						tense(f[i][j][opt][ban], -f[i][j][opt - 1][0] + 1); 
					
					// if (i <= 2 && j <= 2)
						// cerr << i << ' ' << j << ' ' << opt << ' ' << ban << ':' << f[i][j][opt][ban] << '\n'; 	
				}
	}

	int T; 
	read(T); 
	while (T--) work(); 

	return 0; 
}