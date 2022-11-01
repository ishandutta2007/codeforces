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

using namespace std;

typedef long long s64; 
typedef long double ld; 
typedef vector<int> vi; 
typedef pair<int, int> pii; 
#define mp(x, y) std::make_pair(x, y)

const int MaxN = 200000 + 5; 
const int MaxS = 1 << 15 | 5; 

int n, m, p;
s64 val[MaxN]; 
pair<int, s64> ans; 

s64 readBit() {
	s64 res = 0; 
	char ch;
	
	for (int i = 0; i < m; ++i) {
		while (ch = getchar(), !isdigit(ch)); 
		res |= (s64)(ch == '1') << i; 
	}

	return res; 
}

void printBit(s64 x) {
	for (int i = 0; i < m; ++i)
		putchar('0' + (x >> i & 1)); 
}

void randWork(s64 sta) {
	if (!sta) return; 

	static int pos[MaxN]; 
	static int f[MaxS], nP; 
	static s64 exactSta[MaxS]; 
	nP = 0; 
	for (int i = 0; i < m; ++i)
		if (sta >> i & 1) {
			pos[nP++] = i; 
		}
	
	int all = (1 << nP) - 1; 

	fill(f, f + all + 1, 0); 
	fill(exactSta, exactSta + all + 1, 0); 

	for (int i = 1; i <= n; ++i) {
		int s = 0; 
		for (int j = 0; j < nP; ++j)
			if (val[i] >> pos[j] & 1) {
				s |= 1 << j; 
			}
		
		++f[s]; 
	}

	for (int i = 0; i < nP; ++i)
		for (int s = 0; s <= all; ++s)
			if (s >> i & 1) {
				exactSta[s] |= 1LL << pos[i]; 
				f[s ^ (1 << i)] += f[s]; 
			}
	
	for (int s = 0; s <= all; ++s) {
		if (f[s] >= (n + 1) / 2) {
			relax(ans, mp(__builtin_popcountll(s), exactSta[s])); 
		}
	}
}

inline int randInt() {
	return RAND_MAX > 32768 ? rand() : rand() << 15 | rand(); 
}

int main() {
	read(n), read(m), read(p); 
	for (int i = 1; i <= n; ++i) {
		val[i] = readBit(); 
	}

	srand(time(0)); 
	for (int tim = 1; tim <= 100; ++tim)
		randWork(val[randInt() % n + 1]); 

	printBit(ans.second); 

	return 0; 
}