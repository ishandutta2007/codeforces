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

const int MaxN = 201234;
int n, a[MaxN], L[MaxN], R[MaxN]; map<int, int> m;
int lp[MaxN], rp[MaxN];

int main() {
	int i, l, r;
	n = read();
	for(i = 1; i <= n; i++) a[i] = read();
	
	LL ans = (LL) n * (n + 1) / 2;
	
	for(i = 1; i <= n; i++) {
		L[i] = 1; 
		for(int p = 0; p < 31; p++) 
			if(a[i] >> p & 1)
				lp[p] = i;
			else
				cmax(L[i], lp[p] + 1);
	}	
	
	for(i = 0; i < 31; i++) rp[i] = n + 1;
	for(i = n; i; i--) {
		R[i] = n;
		for(int p = 0; p < 31; p++) 
			if(a[i] >> p & 1)
				rp[p] = i;
			else
				cmin(R[i], rp[p] - 1);
	}
	
	for(i = 1; i <= n; i++) m[a[i]] = n + 1;
	for(i = n; i; i--) {
		ans -= (LL) (i - L[i] + 1) * (min(R[i], m[a[i]] - 1) - i + 1);	
		m[a[i]] = i;
	}
	cout << ans;
	return 0;
}