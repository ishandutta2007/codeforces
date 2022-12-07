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

int n, K, x, a[233];
int main() {
	int i, ans = 0;
	cin >> n >> K >> x;
	
	for(i = 1; i <= n; i++) {
		cin >> a[i];
		if(i > n - K) ans += x; else ans += a[i];
	}
	cout << ans;
	return 0;
}