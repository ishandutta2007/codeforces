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

const int MaxN = 101234;

int n, x[MaxN], a, b;

bool chk(int z) {
	int lb = x[n] - z, rb = x[n] + z, i;
	for(i = n - 1; i; i--) {
		int l = x[i] - z, r = x[i] + z;
		if(x[i] < lb || x[i] > rb) {
			cmax(lb, l); cmin(rb, r);
			if(lb > rb) return 0;
		}else 
			lb = l, rb = r;
	}
	return (lb <= a && a <= rb) || (lb <= b && b <= rb);
} 

int main() {
	int i;
	n = inp(); a = inp(); b = inp();
	for(i = 1; i <= n; i++) x[i] = inp();
	int l = max(b - a, a - b), r = 1e9, mid, ans = -1;
	while(l <= r) {
		int mid = l + r >> 1;
		if(chk(mid))
			ans = mid, r = mid - 1;
		else 
			l = mid + 1;
	}
	
	cout << ans << endl;
	return 0;
}