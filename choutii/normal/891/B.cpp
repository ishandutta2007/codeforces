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

const int MaxN = 25;
pair<int, int> a[MaxN]; int n, b[MaxN];

int main() {
	int i;
	n = read();
	for(i = 1; i <= n; i++) a[i] = make_pair(read(), i);
	sort(a + 1, a + n + 1);
	for(i = 1; i <= n; i++) b[a[i % n + 1].sec] = a[i].fir;
	for(i = 1; i <= n; i++) printf("%d ", b[i]);
	return 0;
}