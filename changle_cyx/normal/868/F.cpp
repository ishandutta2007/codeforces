#include <bits/stdc++.h>
//orzczk
//czkhuge
using std::min; 
using std::max; 
using std::cout; 
using std::cerr; 

typedef long long s64;   

template <class T>
inline void read(T &x) {
	static char ch;
	while (!  isdigit(ch = getchar()));
	x = ch -   '0' + 0;
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
}

template <class T>
inline bool tense(T &x, const T &y) {
	return x > y ? x = y, true : false; 
}

const int MaxN = 1e5 + 5; 
const int MaxK = 22; 

int n, K; 
int a[MaxN]; 
s64 f[MaxK][MaxN]; 

int pL, pR, buc[MaxN]; 
s64 sum; 

void clear() {
	pL = 1, pR = 0, sum = 0; 
	for (int i = 1; i <= n; ++i) buc[i] = 0; 
}

void modify(int x, int opt) {
	if (opt == 1) {
		sum += buc[x]++; 
	} else {
		sum -= --buc[x]; 
	}
}

void adjust(int l, int r) {
	while (pL > l) modify(a[--pL], +1); 
	while (pR < r) modify(a[++pR], +1); 
	while (pL < l) modify(a[pL++], -1); 
	while (pR > r) modify(a[pR--], -1); 
}

void solve(int l, int r, int xl, int xr, s64 *f, s64 *g) {
	int mid = (l + r) >> 1, xmid = 0; 
	
	for (int i = xr; i >= xl; --i) {
		adjust(i + 1, mid); 
		if (tense(f[mid], g[i] + sum)) xmid = i; 
	}
	if (l < r) {
		solve(l, mid - 1, xl, xmid, f, g);  
		solve(mid + 1, r, xmid, xr, f, g); 
	}
}

int main() {
#ifdef orzczk
	freopen("a.in", "r", stdin); 
#endif

	memset(f, 0x3f, sizeof(f)); 

	read(n), read(K); 
	for (int i = 1; i <= n; ++i) {
		read(a[i]); 
	}

	f[0][0] = 0; 
	for (int i = 1; i <= K; ++i) {
		clear(); 
		solve(1, n, 0, n - 1, f[i], f[i - 1]); 
	}
	cout << f[K][n] << '\n'; 
	
	return 0; 
}