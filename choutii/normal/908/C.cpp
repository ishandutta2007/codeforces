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

typedef double db;
const int MaxN = 1234;

int n, r;
int x[MaxN]; db y[MaxN];

int main() {
	int i;
	n = read(); r = read();
	for(i = 1; i <= n; i++) x[i] = read();
	for(i = 1; i <= n; i++) {
		// push i
		int p = 0; db Y = r;
		for(int j = 1; j < i; j++) {
			if(abs(x[i] - x[j]) <= 2 * r) {
				db dy = sqrt(4.0 * r * r - abs(x[i] - x[j]) * (db) (abs(x[i] - x[j])));
				cmax(Y, dy + y[j]);
			}
		}
		if(i == 1) y[i] = r;else 
		y[i] = Y;
	}
	for(i = 1; i <= n; i++) printf("%.10lf ", y[i]);
	return 0;
}