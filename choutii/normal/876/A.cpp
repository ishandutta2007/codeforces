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

int n, a[3]; 
	
int main() {
	int i;
	cin >> n >> a[0] >> a[2] >> a[1];
	int t = min(a[0], min(a[1], a[2]));
	int ans;
	if(t == a[0] || t == a[2]) {
		if(n == 1) 
			ans = 0;
		else
			ans = (n - 1) * t;
	} else {
		if(n == 1) 
			ans = 0;
		else
			ans = min(a[0], a[2]) + t * (n - 2);
	}
	
	cout << ans;
	return 0;
}