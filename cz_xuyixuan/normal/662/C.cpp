#include<bits/stdc++.h>
using namespace std;
const int MAXN = 25;
const int MAXM = 100005;
const int MAXS = 1 << 20;
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
int n, m;
char s[MAXN][MAXM];
int bit[MAXN], x[MAXM];
long long cnt[MAXS], bits[MAXS], res[MAXS];
void FWT(long long *a, int N) {
	for (int len = 2; len <= N; len <<= 1)
	for (int i = 0; i < N; i += len)
	for (int j = i, k = i + len / 2; k < i + len; j++, k++) {
		long long tmp = a[j], tnp = a[k];
		a[j] = tmp + tnp;
		a[k] = tmp - tnp;
	}
}
void UFWT(long long *a, int N) {
	for (int len = 2; len <= N; len <<= 1)
	for (int i = 0; i < N; i += len)
	for (int j = i, k = i + len / 2; k < i + len; j++, k++) {
		long long tmp = a[j], tnp = a[k];
		a[j] = (tmp + tnp) / 2;
		a[k] = (tmp - tnp) / 2;
	}
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		scanf("\n%s", s[i] + 1);
	bit[1] = 1;
	for (int i = 2; i <= n; i++)
		bit[i] = bit[i - 1] << 1;
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++)
			if (s[i][j] == '1') x[j] += bit[i];
		cnt[x[j]]++;
	}
	int u = 1 << n;
	for (int i = 1; i < u; i++)
		bits[i] = bits[i ^ (i & -i)] + 1;
	for (int i = 0; i < u; i++)
		chkmin(bits[i], n - bits[i]);
	FWT(cnt, u);
	FWT(bits, u);
	for (int i = 0; i < u; i++)
		res[i] = cnt[i] * bits[i];
	UFWT(res, u);
	long long ans = n * m;
	for (int i = 0; i < u; i++)
		chkmin(ans, res[i]);
	writeln(ans);
	return 0;
}