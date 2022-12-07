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

const int MaxN = 201234;

int n, m, f[MaxN], g[MaxN], h[MaxN], a[MaxN];

int main() {
	m = read(); n = read();
	for (int i = 1; i <= m; i++) {
		int l = read(), r = read();
		a[r + 1]--; a[l]++;
	}
	for (int i = 1; i <= n; i++)
		a[i] += a[i - 1];
	int u = 0;
	#define prev afsad
	for (int i = 1; i <= n; i++) {
		int prev = upper_bound(h  + 1, h + u + 1, a[i]) - h;
		f[i] = prev; h[prev] = a[i]; cmax(u, prev);
	}
	u = 0;
	for (int i = n; i; i--) {
		int prev = upper_bound(h  + 1, h + u + 1, a[i]) - h;
		g[i] = prev; h[prev] = a[i]; cmax(u, prev);
	}
	int ans = 0;
	for (int i =1 ; i <= n; i++)
		cmax(ans, f[i] + g[i] - 1);
	cout << ans << endl;
	return 0;
}