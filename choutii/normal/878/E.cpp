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

const int P = 1000000007;
const int MaxN = 101234, MaxL = 18;

int fix(int x) {
	return (x % P + P) % P;
}

int n, q, a[MaxN], f[MaxN][MaxL], g[MaxN][MaxL];
int binv[MaxN], bin[MaxN], s[MaxN];

int query(int l, int r) {
	int ans = 0;
	for(int i = MaxL - 1; ~i; i--)
		if(f[r][i] >= l)
			(ans += g[r][i]) %= P, r = f[r][i];
	return (ans + (LL) (s[r] - s[l - 1] + P) * binv[l - 1] % P) % P;
}

int main() {
	int i, j;
	n = read(); q = read();
	for(i = 1; i <= n; i++) a[i] = read();
	bin[0] = binv[0] = 1;
	for(i = 1; i <= n; i++) {
		bin[i] = 2 * bin[i - 1] % P;
		binv[i] = (LL) binv[i - 1] * (P + 1 >> 1) % P;
		s[i] = ((LL) bin[i] * (a[i] + P) + s[i - 1])% P;
	}
	for(i = 1; i <= n; i++) {
		LL c = 0;
		for(j = i; j; j--) {
			c = 2 * (c + a[j]);
			if(c <= 0) {
				f[i][0] = j - 1; 
				g[i][0] = (c % P + P) % P;
				break;
			}
			if(c > 2e9) {
				f[i][0] = -1;
				break;
			}
		}
	}
	
	for(j = 1; j < MaxL; j++)
		for(i = 1; i <= n; i++)
			if(! ~f[i][j - 1])
				f[i][j] = -1;
			else
				f[i][j] = f[f[i][j - 1]][j - 1], 
				g[i][j] = (g[i][j - 1] + g[f[i][j - 1]][j - 1]) % P; 
	while(q--) {
		int l = read(), r = read();
		printf("%d\n", fix(a[l] + query(l + 1, r)));
	}
	return 0;
}