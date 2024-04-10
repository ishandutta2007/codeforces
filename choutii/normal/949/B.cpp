#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int) (x).size())
#define ALL(x) x.begin(), x.end()

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef unsigned long long u64;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int read() {
	int x = 0, f = 1;char ch;
	for (ch = getchar(); !isdigit(ch); ch = getchar())
		if (ch == '-') f = -1;
	for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

LL n; int q;

LL f(LL n, LL x) {
	if(x & 1)
		return x + 1 >> 1;
	LL cur = n + 1 >> 1;
	if(n & 1)if(x == 2)
		return cur + f(n >> 1, n >> 1);
	return cur + ((n & 1) ? f(n >> 1, (x >> 1) - 1) : f(n >> 1, x >> 1));
}

int main() {
	scanf("%lld%d\n", &n, &q);
	while(q--) {
		LL x; scanf("%lld", &x);
		printf("%lld\n", f(n, x));
	}
	return 0;
}