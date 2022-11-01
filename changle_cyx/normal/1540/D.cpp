#include <bits/stdc++.h>

using namespace std; 

#define range(x) x.begin(), x.end()

template <class T>
inline void read(T &x) {
	static char ch; 
	while (!isdigit(ch = getchar())); 
	x = ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
}

template <class T>
inline void putint(T x) {
	static char buf[25], *tail = buf; 
	if (!x) putchar('0'); 
	else {
		for (; x; x /= 10) *++tail = x % 10 + '0'; 
		for (; tail != buf; --tail) putchar(*tail); 
	}
}

const int S = 512; 
const int MaxN = 100000 + 5; 
const int MaxB = MaxN / S + 5; 

int n; 
int a[MaxN]; 

int nB; 
int bel[MaxN], bl[MaxN], br[MaxN]; 

int leaf[MaxN]; 
vector<int> f[MaxB][S << 2 | 3]; 

#define lcc x << 1, l, mid
#define rcc x << 1 | 1, mid + 1, r

vector<int> merge(const vector<int> &a, vector<int> b) {
	int sa = a.size(), sb = b.size(); 
	vector<int> res(sa + sb); 

	for (int i = 0, j = 0; i < sb; ++i) {
		while (j < sa && a[j] + j < b[i]) ++j; 
		b[i] -= j;  
	}

	return merge(range(a), range(b), res.begin()), res; 
}

void build(int b, int x, int l, int r) {
	if (l == r) return (void)(leaf[l] = x, f[b][x] = {a[l]}); 
	int mid = (l + r) >> 1; 
	build(b, lcc), build(b, rcc); 
	f[b][x] = merge(f[b][x << 1], f[b][x << 1 | 1]); 
}

void modify(int b, int x, int p) {
	f[b][x] = {a[p]}; 
	for (x >>= 1; x; x >>= 1)
		f[b][x] = merge(f[b][x << 1], f[b][x << 1 | 1]); 
}
//orzczk
int main() {
	read(n); 
	for (int i = 1; i <= n; ++i) {
		read(a[i]); 
		a[i] = i - a[i]; 

		if ((i - 1) % S == 0) {
			bl[++nB] = i; 
			br[nB] = min(i + S - 1, n); 
		}
		bel[i] = nB; 
	}
	
	for (int i = 1; i <= nB; ++i) build(i, 1, bl[i], br[i]); 

	int Q; 
	read(Q); 
	while (Q--) {
		int opt, x, y; 
		read(opt), read(x); 

		if (opt == 1) {
			read(y), a[x] = x - y; 
			modify(bel[x], leaf[x], x); 
		} else {
			int res = a[x]; 
			++x; 
			if (x <= n) {
				for (int i = x; i <= br[bel[x]]; ++i)
					if (res >= a[i]) ++res; 
				for (int i = bel[x] + 1; i <= nB; ++i)
					res = res + (upper_bound(range(f[i][1]), res) - f[i][1].begin()); 
			}
			putint(res), putchar('\n'); 
		}
	}	

	return 0; 
}