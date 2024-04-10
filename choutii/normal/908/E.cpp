#include <bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define FO(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)

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

const int MaxN = 1234, P = 1e9 + 7;
int m, n; LL b[MaxN], c[MaxN][MaxN], f[MaxN]; map<LL, LL> g;
int main() {
	int i, j;
	m = read(); n = read();
	while(n--)
		for(j = 1; j <= m; j++) {
			LL x; scanf("%1lld", &x); b[j] |= (x << n);
		}
	for(i = 1; i <= m; i++) ++g[b[i]];
	c[0][0] = 1;
	for(i = 1; i <= m; i++) {
		c[i][0] = 1;
		for(j = 1; j <= i; j++)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % P;
	}
	
	f[0] = f[1] = 1;
	for(i = 2; i <= m; i++)
		for(j = 0; j < i; j++)
			f[i] = (f[i] + (LL) f[j] * c[i - 1][j]) % P;
	int ans = 1;
	for(map<LL, LL> :: iterator it = g.begin(); it != g.end(); it++)
		ans = (LL) ans * f[it -> second] % P;
	cout << ans << endl;
	return 0;
}