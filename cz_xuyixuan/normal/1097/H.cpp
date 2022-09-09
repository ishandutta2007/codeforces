#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e4 + 5;
const int MAXD = 25;
const int MAXM = 65;
const int MAXLOG = 64;
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
struct info {
	ll ans, len;
	bitset <MAXN> pre, suf;
};
bitset <MAXN> all;
int n, d, m, gen[MAXD], b[MAXN];
int tot; ll len[MAXLOG]; info dp[MAXLOG][MAXM];
info operator + (const info &a, const info &b) {
	if (a.len == 0) return b;
	info res;
	res.len = a.len + b.len;
	res.ans = a.ans + b.ans;
	res.pre = a.pre;
	res.suf = b.suf;
	if (a.len <= n - 2) res.pre &= (b.pre >> a.len) | (all << (n - 1 - a.len));
	if (b.len <= n - 2) res.suf &= (a.suf << b.len) | (all >> (n - 1 - b.len));
	if (a.len + b.len >= n) {
		bitset <MAXN> tmp = a.suf & b.pre;
		if (a.len <= n - 2) tmp &= all >> (n - 1 - a.len);
		if (b.len <= n - 2) tmp &= all << (n - 1 - b.len);
		res.ans += tmp.count(); 
	}
	return res;
}
ll work(ll x) {
	info res;
	res.ans = 0;
	res.len = 0;
	res.pre.reset();
	res.suf.reset();
	int add = 0;
	for (int i = tot; i >= 0; i--) {
		for (int j = 1; j <= d; j++)
			if (x >= len[i]) {
				x -= len[i];
				res = res + dp[i][(add + gen[j]) % m];
			} else {
				add = (add + gen[j]) % m;
				break;
			}
	}
	return res.ans;
}
int main() {
	read(d), read(m);
	for (int i = 1; i <= d; i++)
		read(gen[i]);
	read(n);
	for (int i = 1; i <= n; i++)
		read(b[i]);
	for (int i = 1; i <= n - 1; i++)
		all.set(i);
	tot = 0, len[0] = 1;
	for (int i = 0; i <= m - 1; i++) {
		dp[0][i].len = 1;
		if (n == 1) dp[0][i].ans = i <= b[1];
		else {
			for (int j = 1; j <= n - 1; j++) {
				dp[0][i].pre[j] = i <= b[j + 1];
				dp[0][i].suf[j] = i <= b[j];
			}
		}
	}
	ll ql, qr; read(ql), read(qr);
	while (len[tot] <= qr / d) {
		tot++, len[tot] = len[tot - 1] * d;
		for (int i = 0; i <= m - 1; i++)
		for (int j = 1; j <= d; j++)
			dp[tot][i] = dp[tot][i] + dp[tot - 1][(i + gen[j]) % m];
	}
	writeln(work(qr) - work(ql + n - 2));
	return 0;
}