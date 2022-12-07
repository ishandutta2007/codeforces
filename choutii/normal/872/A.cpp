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

int n, m, a[20], b[20], A[20], B[20];
int main() {
	int i;
	cin >> n >> m;
	for(i = 1; i <= n; i++) {
		cin >> a[i];
		A[a[i]] = 1;
	}
	for(i = 1; i <= m; i++) {
		cin >> b[i];
		B[b[i]] = 1;
	}
	for(i = 0; i < 10; i++) {
		if(A[i] && B[i]) return printf("%d", i), 0;
	}
	
	int x = 0, y = 0;
	for(i = 0; i < 10; i++) if(A[i]) {x = i; break;}
	for(i = 0; i < 10; i++) if(B[i]) {y = i; break;}
	cout<<min(x,y)<<max(x,y);
	return 0;
}