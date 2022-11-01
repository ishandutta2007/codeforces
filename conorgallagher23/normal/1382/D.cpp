#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int read() {
	char c = getchar(); int x = 0, f = 1;
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

const int N = 4005;

int n, a[N], stk[N]; bool dp[N];

int main() {
	int T = read();
	while (T--) {
		n = read();
		for (int i = 1; i <= (n << 1); i++) a[i] = read();
		a[n << 1 | 1] = (n << 1 | 1); int tp = 0;
		for (int i = 1; i <= (n << 1); i++) {
			int fir;
			for (int j = i + 1; j <= (n << 1 | 1); j++)
				if (a[j] > a[i]) { fir = j; break; }
			stk[++tp] = fir - i; i = fir - 1;
		}
		dp[0] = true; for (int i = 1; i <= (n << 1); i++) dp[i] = false;
		for (int i = 1; i <= tp; i++)
			for (int j = (n << 1); j >= stk[i]; j--) dp[j] |= dp[j - stk[i]];
		puts(dp[n] ? "YES" : "NO");
	}
	return 0;
}