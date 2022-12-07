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

double dist(double x, double y) {
	return sqrt(x * x + y * y);
}

double r, d; int n;
int main() {
	int i;
	cin >> r >> d >> n;
	int L = (r - d), R = r;
	int ans = 0;
	for(i = 0; i < n; i++) {
		double x, y, o;
		cin >> x >> y >> o;
		double d = dist(x, y);
		if(d >= o + L && d <= R - o) 
			++ans; 
	}
	cout << ans;
	return 0;
}