#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline int read() {
	char c = getchar(); int x = 0, f = 1;
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

const int N = 1000005, P1 = 1e9 + 7, P2 = 998244353, P3 = 999998639;

int a[N];

inline void upd(int &x, int y, int mod) {
	x = (x + y >= mod) ? x + y - mod : x + y;
}
inline int fpow(int a, int b, int mod) {
	ll ret = 1;
	for (; b; b >>= 1, a = (ll)a * a % mod)
		if (b & 1) ret = (ll)ret * a % mod;
	return ret;
}

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int T = read();
	while (T--) {
		int n = read(), p = read();
		for (int i = 1; i <= n; i++) a[i] = read();
		sort(a + 1, a + n + 1, cmp);
		int ans = 0, wt1 = 0, wt2 = 0;
		for (int i = 1; i <= n; i++)
			if (ans == 0 && wt1 == 0 && wt2 == 0)
				upd(ans, fpow(p, a[i], P1), P1), upd(wt1, fpow(p, a[i], P2), P2), upd(wt2, fpow(p, a[i], P3), P3);
			else
				upd(ans, P1 - fpow(p, a[i], P1), P1), upd(wt1, P2 - fpow(p, a[i], P2), P2), upd(wt2, P3 - fpow(p, a[i], P3), P3);
		printf("%d\n", ans);
	}
	return 0;
}