#include<bits/stdc++.h>
using namespace std;
const int MAXN = 262144;
const int P = 998244353;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
namespace NTT {
	const int MAXN = 262144;
	const int P = 998244353;
	const int G = 3;
	int power(int x, int y) {
		if (y == 0) return 1;
		int tmp = power(x, y / 2);
		if (y % 2 == 0) return 1ll * tmp * tmp % P;
		else return 1ll * tmp * tmp % P * x % P;
	}
	int N, Log, home[MAXN];
	int forward[25], bckward[25], inv[25];
	void NTTinit() {
		for (int i = 0; i < N; i++) {
			int ans = 0, tmp = i;
			for (int j = 1; j <= Log; j++) {
				ans <<= 1;
				ans += tmp & 1;
				tmp >>= 1;
			}
			home[i] = ans;
		}
	}
	void preinit() {
		forward[0] = bckward[0] = inv[0] = 1;
		for (int len = 2, lg = 1; len <= MAXN; len <<= 1, lg++) {
			forward[lg] = power(G, (P - 1) / len);
			bckward[lg] = power(G, P - 1 - (P - 1) / len);
			inv[lg] = power(len, P - 2);
		}
	}
	void NTT(int *a, int mode) {
		for (int i = 0; i < N; i++)
			if (home[i] < i) swap(a[i], a[home[i]]);
		for (int len = 2, lg = 1; len <= N; len <<= 1, lg++) {
			int delta;
			if (mode == 1) delta = forward[lg];
			else delta = bckward[lg];
			for (int i = 0; i < N; i += len) {
				int now = 1;
				for (int j = i, k = i + len / 2; k < i + len; j++, k++) {
					int tmp = a[j];
					int tnp = 1ll * a[k] * now % P;
					a[j] = (tmp + tnp) % P;
					a[k] = (tmp - tnp + P) % P;
					now = 1ll * now * delta % P;
				}
			}
		}
		if (mode == -1) {
			for (int i = 0; i < N; i++)
				a[i] = 1ll * a[i] * inv[Log] % P;
		}
	}
	void times(int *a, int *b, int *c, int sa, int sb) {
		N = 1, Log = 0;
		while (N <= sa + sb) {
			N <<= 1;
			Log++;
		}
		for (int i = sa + 1; i < N; i++)
			a[i] = 0;
		for (int i = sb + 1; i < N; i++)
			b[i] = 0;
		NTTinit();
		NTT(a, 1);
		NTT(b, 1);
		for (int i = 0; i < N; i++)
			c[i] = 1ll * a[i] * b[i] % P;
		NTT(c, -1);
	}
}
int n, ans, fib[MAXN];
int trans[MAXN][2], dp[MAXN][2];
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
void solve(int l, int r) {
	if (l == r) return;
	int mid = (l + r) / 2;
	solve(l, mid);
	static int a[MAXN], b[MAXN], c[MAXN];
	for (int i = l; i <= mid; i++)
		a[i - l] = dp[i][0];
	for (int i = l; i <= r; i++)
		if ((i - l) % 2 == 0) b[i - l] = trans[i - l][0];
		else b[i - l] = 0;
	NTT :: times(a, b, c, mid - l, r - l);
	for (int i = mid + 1; i <= r; i++)
		update(dp[i][1], c[i - l]);
	
	for (int i = l; i <= mid; i++)
		a[i - l] = dp[i][0];
	for (int i = l; i <= r; i++)
		if ((i - l) % 2 == 1) b[i - l] = trans[i - l][0];
		else b[i - l] = 0;
	NTT :: times(a, b, c, mid - l, r - l);
	for (int i = mid + 1; i <= r; i++)
		update(dp[i][0], c[i - l]);
	
	for (int i = l; i <= mid; i++)
		a[i - l] = dp[i][1];
	for (int i = l; i <= r; i++)
		if ((i - l) % 2 == 0) b[i - l] = trans[i - l][1];
		else b[i - l] = 0;
	NTT :: times(a, b, c, mid - l, r - l);
	for (int i = mid + 1; i <= r; i++)
		update(dp[i][0], c[i - l]);
	
	for (int i = l; i <= mid; i++)
		a[i - l] = dp[i][1];
	for (int i = l; i <= r; i++)
		if ((i - l) % 2 == 1) b[i - l] = trans[i - l][1];
		else b[i - l] = 0;
	NTT :: times(a, b, c, mid - l, r - l);
	for (int i = mid + 1; i <= r; i++)
		update(dp[i][1], c[i - l]);
	solve(mid + 1, r);
}
int main() {
	read(n), fib[0] = fib[1] = 1, NTT :: preinit();
	for (int i = 2; i <= n; i++) {
		int tmp = i - 1;
		fib[i] = (fib[i - 1] + fib[i - 2]) % P;
		trans[i][0] = 1ll * tmp * tmp % P * fib[tmp / 2] % P;
		if (tmp & 1) trans[i][1] = 1ll * tmp * tmp % P * fib[tmp / 2] % P;
		else trans[i][1] = 1ll * tmp * tmp % P * fib[tmp / 2 - 1] % P;
	}
	memset(dp, 0, sizeof(dp)), dp[1][0] = 1, solve(1, n);
	for (int i = 1; i <= n - 1; i++) {
		int tmp = n - i;
		if (tmp & 1) update(ans, 1ll * dp[i][1] * tmp % P * tmp % P * fib[tmp / 2] % P * (n - i + 1) % P);
		else update(ans, 1ll * dp[i][0] * tmp % P * tmp % P * fib[tmp / 2] % P * (n - i + 1) % P);
	}
	memset(dp, 0, sizeof(dp)), dp[1][1] = 1, solve(1, n);
	for (int i = 1; i <= n - 1; i++) {
		int tmp = n - i;
		if (tmp & 1) update(ans, 1ll * dp[i][0] * tmp % P * tmp % P * fib[tmp / 2] % P * (n - i + 1) % P);
		else update(ans, 1ll * dp[i][1] * tmp % P * tmp % P * fib[tmp / 2 - 1] % P * (n - i + 1) % P);
	}
	writeln(ans);
	return 0;
}