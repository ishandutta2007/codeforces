#include <bits/stdc++.h>

#define fir first
#define sec second
using namespace std;
typedef long long LL;
typedef unsigned long long u64;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int inp() {
	int x = 0, f = 1;char ch;
	for(ch = getchar(); !isdigit(ch); ch = getchar())
		if(ch == '-') f = -1;
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int MaxN = 10001234;

int n, K, a[MaxN], f[MaxN];

int main() {
	int i;
	n = inp(); K = inp();
	for(i = 1; i <= n; i++) a[i] = inp();
	sort(a + 1, a + n + 1);
	int L = 1, R = a[n];
	int ans = -1;
	
	while(L <= R) {
		int o = (L + R)/2;
		memset(f, 0, sizeof(f));
		for(i = o; i <= a[n]; i++)
			f[i] = max(f[i >> 1] + f[i + 1 >> 1], 1);
		LL chk = 0;
		for(i = 1; i <= n; i++) chk += f[a[i]];
		if(chk >= K) ans = o, L = o + 1; else R = o - 1;
	}
	
	cout << ans;
	return 0;
}