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

int q, n;

void solve() {
	if(n < 4) {
		puts("-1");
		return;
	}
	if(n % 4 == 0) {
		printf("%d\n", n / 4);
		return;
	}
	if(n % 4 == 1) {
		if(n < 9) {
			puts("-1");
			return;
		}
		printf("%d\n", (n - 9) / 4 + 1);
	}
	if(n % 4 == 2) {
		if(n < 6) {
			puts("-1");
			return;
		}
		printf("%d\n", (n - 6) / 4 + 1);
	}
	
	if(n % 4 == 3) {
		if(n < 15) {
			puts("-1"); return;
		}
		printf("%d\n", (n - 15) / 4 + 2);
		return;
	}
}
int main() {
	int i;
	q = read();
	while(q--) {
		n = read();
		solve();
	}
	return 0;
}