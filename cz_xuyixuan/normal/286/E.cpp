#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2097152;
const int P = 998244353;
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
bool exist[MAXN];
long long a[MAXN];
int N, Log, cnt, ans[MAXN], home[MAXN];
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
int main() {
	int n, m;
	read(n), read(m);
	for (int i = 1; i <= n; i++) {
		int x; read(x);
		a[x] = exist[x] = 1;
	}
	N = 1, Log = 0;
	while (N <= 2 * m) {
		N <<= 1;
		Log++;
	}
	NTTinit();
	NTT(a, 1);
	for (int i = 0; i < N; i++)
		a[i] = a[i] * a[i] % P;
	NTT(a, -1);
	for (int i = 1; i <= m; i++)
		if (a[i] && !exist[i]) {
			printf("NO\n");
			return 0;
		} else if (!a[i] && exist[i]) ans[++cnt] = i;
	printf("YES\n%d\n", cnt);
	for (int i = 1; i <= cnt; i++)
		printf("%d ", ans[i]);
	return 0;
}