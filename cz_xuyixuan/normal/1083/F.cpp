#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int MAXM = 1 << 14;
const int BLOCK = 450;
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int n, m, k, nonezero, sum[MAXN], home[MAXN];
int x[MAXN], y[MAXN], a[MAXN], v[MAXN], d[MAXN];
int block, blockcnt, tag[MAXN], belong[MAXN], ql[MAXN], qr[MAXN], cnt[BLOCK][MAXM];
void modify(int pos, int d) {
	nonezero -= sum[pos % k] != 0;
	sum[pos % k] ^= d;
	nonezero += sum[pos % k] != 0;
	pos = home[pos];
	for (int i = pos, tmp = belong[pos]; i <= qr[tmp]; i++) {
		cnt[tmp][a[i]]--;
		a[i] ^= d;
		cnt[tmp][a[i]]++;
	}
	for (int i = belong[pos] + 1; i <= blockcnt; i++)
		tag[i] ^= d;
}
void output() {
	if (nonezero) puts("-1");
	else {
		int ans = n + 1;
		for (int i = 1; i <= blockcnt; i++)
			ans -= cnt[i][tag[i]];
		printf("%d\n", ans);
	}
}
int main() {
	read(n), read(k), read(m);
	for (int i = 1; i <= n; i++)
		read(x[i]);
	for (int i = 1; i <= n; i++)
		read(y[i]);
	for (int i = 1; i <= n + 1; i++) {
		v[i] = x[i] ^ y[i];
		d[i] = v[i] ^ v[i - 1];
	}
	int tot = 0;
	for (int i = 1; i <= k; i++)
	for (int j = i; j <= n + 1; j += k) {
		a[++tot] = d[j], home[j] = tot;
		sum[j % k] ^= d[j];
	}
	for (int i = 0; i <= k - 1; i++)
		nonezero += sum[i] != 0;
	block = sqrt(n + 1);
	for (int i = 1; i <= n + 1; i++) {
		a[i] ^= a[i - 1];
		if (i % block == 1 % block) ql[++blockcnt] = i;
		qr[blockcnt] = i, belong[i] = blockcnt;
		cnt[belong[i]][a[i]]++;
	}
	output();
	for (int i = 1; i <= m; i++) {
		char opt; int p, q, delta;
		scanf("\n%c%d%d", &opt, &p, &q);
		if (opt == 'a') delta = x[p] ^ q, x[p] = q;
		else delta = y[p] ^ q, y[p] = q;
		v[p] ^= delta, modify(p, delta), modify(p + 1, delta);
		output();
	}
	return 0;
}