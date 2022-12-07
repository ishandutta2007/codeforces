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

const int MaxN = 123;

int n, m, K, a[MaxN][MaxN];

int main() {
	int i, j;
	n = read(); m = read(); K = read();
	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++) {
			a[i][j] = read(); a[i][j] += a[i - 1][j];
		}

	int ans1 = 0, ans2 = 0;
	for(j = 1; j <= m; j++) {
		int ans = 0, ansp = 0;
		for(i = 1; i <= n; i++) {
			int d = i + min(K, n - i + 1) - 1;
			if(a[d][j] - a[i - 1][j] > ans) {
				ans = a[d][j] - a[i - 1][j];
				ansp = a[i - 1][j];
			}
		}
		ans1 += ans; ans2 += ansp;
	}
	
	cout << ans1 << " " << ans2 << endl;
	return 0;
}