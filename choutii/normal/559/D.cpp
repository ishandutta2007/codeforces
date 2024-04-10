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

// E(inside) = E(edge)

const int MaxN = 101234;
int n, x[MaxN], y[MaxN]; double p[MaxN];

int main() {
	n = read();
	for (int i = 0; i < n; i++)
		x[i] = read(), y[i] = read();
	p[0] = 1;
	for (int i = 1; i <= n; i++)
		p[i] = 2 * p[i - 1];
	double ans = 0.0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= 60 && j <= n; j++) {
			int k = (i + j) % n;
			LL s = (LL) x[i] * y[k] - (LL) x[k] * y[i];
			LL b = __gcd(abs(x[k] - x[i]), abs(y[k] - y[i]));
			if(n < 60)
				ans += (s - b) * (p[n - j - 1] - 1) / (p[n] - 1 - n - (LL) n * (n - 1) / 2);
			else
				ans += (s - b) / p[j + 1];
		}
	}
	printf("%.5lf", ans / 2 + 1);
	return 0;
}