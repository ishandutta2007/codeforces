#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1048576;
const int P = 998244353;
const int Q = 1004535809;
const int G = 3;
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
long long power(int x, int y) {
	if (y == 0) return 1;
	long long tmp = power(x, y / 2);
	if (y % 2 == 0) return tmp * tmp % P;
	else return tmp * tmp % P * x % P;
}
long long qower(int x, int y) {
	if (y == 0) return 1;
	long long tmp = qower(x, y / 2);
	if (y % 2 == 0) return tmp * tmp % Q;
	else return tmp * tmp % Q * x % Q;
}
long long a[MAXN], b[MAXN];
int N, Log, g, n, m, home[MAXN];
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
void NTT(long long *a, int mode) {
	for (int i = 0; i < N; i++)
		if (home[i] < i) swap(a[i], a[home[i]]);
	for (int len = 2; len <= N; len <<= 1) {
		long long delta;
		if (mode == 1) delta = power(G, (P - 1) / len);
		else delta = power(G, P - 1 - (P - 1) / len);
		for (int i = 0; i < N; i += len) {
			long long now = 1;
			for (int j = i, k = i + len / 2; k < i + len; j++, k++) {
				long long tmp = a[j];
				long long tnp = a[k] * now % P;
				a[j] = (tmp + tnp) % P;
				a[k] = (tmp - tnp + P) % P;
				now = now * delta % P;
			}
		}
	}
	if (mode == -1) {
		long long inv = power(N, P - 2);
		for (int i = 0; i < N; i++)
			a[i] = a[i] * inv % P;
	}
}
void NTTII(long long *a, int mode) {
	for (int i = 0; i < N; i++)
		if (home[i] < i) swap(a[i], a[home[i]]);
	for (int len = 2; len <= N; len <<= 1) {
		long long delta;
		if (mode == 1) delta = qower(G, (Q - 1) / len);
		else delta = qower(G, Q - 1 - (Q - 1) / len);
		for (int i = 0; i < N; i += len) {
			long long now = 1;
			for (int j = i, k = i + len / 2; k < i + len; j++, k++) {
				long long tmp = a[j];
				long long tnp = a[k] * now % Q;
				a[j] = (tmp + tnp) % Q;
				a[k] = (tmp - tnp + Q) % Q;
				now = now * delta % Q;
			}
		}
	}
	if (mode == -1) {
		long long inv = qower(N, Q - 2);
		for (int i = 0; i < N; i++)
			a[i] = a[i] * inv % Q;
	}
}
int main() {
	read(n), read(m);
	N = 1, Log = 0;
	while (N <= 1000 * m) {
		N <<= 1;
		Log++;
	}
	for (int i = 1; i <= n; i++) {
		int x; read(x);
		a[x] = b[x] = 1;
	}
	NTTinit();
	NTT(a, 1); NTTII(b, 1);
	for (int i = 0; i < N; i++) {
		a[i] = power(a[i], m);
		b[i] = qower(b[i], m);
	}
	NTT(a, -1); NTTII(b, -1);
	for (int i = 0; i < N; i++)
		if (a[i] || b[i]) printf("%d ", i);
	return 0;
}