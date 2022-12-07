#include <bits/stdc++.h>

#define fir first
#define sec second
#define MP make_pair
#define PB push_back

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

int n;
int main() {
	int i;
	n = read();
	int g = -1, r = -1, b = -1;
	int gr = 0, gb = 0;
	LL ans = 0;
	for(i = 1; i <= n; i++) {
		int p = read(); char c; scanf("%c", &c);
		if(c == 'R') {
			if(~r) ans += p - r, cmax(gr, p - r);
			r = p;
		} 
		if(c == 'B') {
			if(~b) ans += p - b, cmax(gb, p - b);
			b = p;
		}
		if(c == 'G') {
			if(~r) ans += p - r, cmax(gr, p - r);
			if(~b) ans += p - b, cmax(gb, p - b);
			if(~g) cmin(ans, ans - gr - gb + p - g);
			r = b = g = p; gr = gb = 0;
		}
	}
	cout << ans << endl;
	return 0;
}