#include <bits/stdc++.h>

#define fir first
#define sec second
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long LL;
typedef unsigned long long u64;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int read() {
	int x = 0, f = 1;char ch;
	for(ch = getchar(); !isdigit(ch); ch = getchar())
		if(ch == '-') f = -1;
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int MaxN = 101234;

int n, q, P, a[MaxN];

int phi(int n) {
	int ans = n;
	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0) {
			ans = ans / i * (i - 1);
			while(n % i == 0)
				n /= i;
		}
	}
	return n != 1 ? ans / n * (n - 1): ans;
}

vector<int> ps;

int exp(int a, int n, int P) {
	int res = 1;
	for(; n; n >>= 1) {
		if(n & 1)
			res = min((LL) res * a % P + P, (LL) res * a);
		a = min((LL) a * a % P + P, (LL) a * a);
	}	
	return res;
}

int query(int l, int r, int pn) {
	if(l > r) return 1;
	if(pn == ps.size() - 1) return min(a[r], 2);
	return exp(a[l], query(l + 1, r, pn + 1), ps[pn]);
}

int main() {
	int i;
	n = read(); P = read();
	for(i = 1; i <= n; i++) a[i] = read();
	while(P > 1)
		ps.PB(P), P = phi(P); ps.PB(1);
	q = read();
	while(q--) {
		int l = read(), r = read();
		printf("%d\n", query(l, r, 0) % ps[0]);	
	}	
	return 0;
}