#include<bits/stdc++.h>
using namespace std;
const int MAXN = 15;
const int MAXK = 105;
const int MAXS = 5005;
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
int n, q, m, goal, w[MAXN], bit[MAXN];
int val[MAXS], cnt[MAXS], ans[MAXS][MAXK];
int calc(int x, int y) {
	int tmp = goal ^ (x ^ y);
	return val[tmp];
}
int getin() {
	static char s[MAXN];
	scanf("\n%s", s + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (s[i] == '1') ans += bit[i];
	return ans;
}
int main() {
	read(n), read(m), read(q);
	for (int i = 1; i <= n; i++) {
		bit[i] = 1 << (i - 1);
		read(w[i]);
	}
	goal = (1 << n) - 1;
	for (int s = 0; s <= goal; s++) {
		val[s] = 0;
		for (int i = 1; i <= n; i++)
			if (bit[i] & s) val[s] += w[i];
	}
	for (int i = 1; i <= m; i++) {
		int x = getin();
		cnt[x]++;
	}
	for (int s = 0; s <= goal; s++) {
		for (int t = 0; t <= goal; t++)
			if (calc(s, t) <= 100) ans[s][calc(s, t)] += cnt[t];
		for (int i = 1; i <= 100; i++)
			ans[s][i] += ans[s][i - 1];
	}
	while (q--) {
		int s = getin(), k;
		read(k);
		writeln(ans[s][k]);
	}
	return 0;
}