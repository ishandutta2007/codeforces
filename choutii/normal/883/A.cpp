#include <bits/stdc++.h>

#define fir first
#define sec second
using namespace std;
typedef long long LL;
typedef unsigned long long u64;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}

LL read() {
	LL x = 0, f = 1;char ch;
	for(ch = getchar(); !isdigit(ch); ch = getchar())
		if(ch == '-') f = -1;
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int MaxN = 101234;
LL n, a, m, d, t[MaxN];

int main() {
	int i;
	n = read(); m = read(); a = read(); d = read();
	for(i = 1; i <= m; i++) t[i] = read();
	
	LL g = d / a + 1; 
	LL eL, cL, ans = 0, prev = 0;
	for(i = 1; i <= m; i++) {
		eL = max(1ll, prev / a + 1);
		cL = min(t[i] / a, n);
		if(eL <= cL) {
			ans += (cL - eL) / g + 1;
			prev = (eL + (cL - eL) / g * g) * a + d;
		}
		if(prev < t[i]) prev = t[i] + d, ++ans; 
	}
	eL = max(prev / a + 1, 1ll); if(eL <= n) ans += (n - eL) / g + 1;
	cout << ans;	
	return 0;
}