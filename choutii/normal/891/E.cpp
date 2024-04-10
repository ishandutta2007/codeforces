#include <bits/stdc++.h>

#define fir first
#define sec second
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

const int MaxN = 5005, P = 1000000007;
int n, K, a[MaxN], f[MaxN], g[MaxN];

int exp(int a, int n) {
	int res = 1;
	for(; n; n >>= 1) {
		if(n & 1) 
			res = (LL) res * a % P;
		a = (LL) a * a % P;
	}
	return res;
}

int main() {
	int i, j, s = 1;
	n = read(); K = read();
	for(i = 1; i <= n; i++) a[i] = read();
	f[0] = 1;
	for(i = 1; i <= n; i++)
		for(j = i; j; j--)
			f[j] = (LL) (f[j] + (LL) f[j - 1] * a[i]) % P;
	g[0] = 1;
	for(i = 1; i <= n; i++)
		g[i] = (LL) g[i - 1] * (K - i + 1) % P;
	for(i = 1; i <= n; i++)
		g[i] = (LL) g[i] * exp(exp(n, P - 2), i) % P;
	int ans = 0, sgn = 1;
	for(i = 1; i <= n; i++, sgn *= -1)
		ans = (ans + (LL)sgn * g[i] * f[n - i] % P) % P;
	cout << (ans + P) % P << endl;
	return 0;
}