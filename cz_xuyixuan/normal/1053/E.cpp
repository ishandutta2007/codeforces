#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
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
int a[MAXN], nxtoccur[MAXN];
int n, pre[MAXN], suf[MAXN];
int now, vis[MAXN];
void error() {
	printf("no\n");
	exit(0);
}
int getnum() {
	while (vis[now]) now++;
	if (now > n) error();
	vis[now] = 1;
	return now;
}
void solve(int l, int r) {
	if ((r - l) % 2 != 0) error();
	int start = pre[l], endpos = suf[r];
	for (int i = suf[start]; i <= r; i = nxtoccur[i] ? nxtoccur[i] : suf[i]) {
		if (nxtoccur[i]) {
			int tmp = nxtoccur[i];
			if (tmp > r) error();
			solve(suf[i], pre[tmp]);
			int tnp = pre[i];
			suf[tnp] = tmp, pre[tmp] = tnp;
		}
	}
	int cnt = 0, all = 0;
	for (int i = suf[start]; i <= r; i = suf[i])
		all++, cnt += a[i] != 0;
	int goal = (all + 1) / 2;
	if (cnt > goal) error();
	for (int i = suf[suf[start]]; i <= r && cnt < goal; i = suf[i]) {
		if (a[i] == 0) {
			cnt++;
			a[i] = getnum();
		}
	}
	if (all != 1) {
		for (int i = suf[start], j = suf[suf[start]]; j <= r; i = suf[i], j = suf[j]) {
			while (i > suf[start] && a[i] && a[j]) {
				int tmp = pre[i];
				if (a[tmp] == 0) {
					a[tmp] = a[j];
					int tnp = pre[tmp];
					suf[tnp] = j, pre[j] = tnp;
					i = tnp;
				} else break;
			}
			while (j < r && a[i] && a[j]) {
				int tmp = suf[j];
				if (a[tmp] == 0) {
					a[tmp] = a[i];
					int tnp = suf[tmp];
					suf[i] = tnp, pre[tnp] = i;
					if (pre[i] >= l) j = i, i = pre[i];
					else j = tnp;
				} else break;
			}
		}
		for (int i = suf[start]; i <= r; i = suf[i])
			if (a[i] == 0) a[i] = a[start];
	} else if (cnt == 0) a[suf[start]] = getnum();
	endpos = pre[endpos];
	suf[start] = endpos;
	pre[endpos] = start;
}
int main() {
	read(n);
	for (int i = 1; i <= 2 * n - 1; i++) {
		read(a[i]);
		suf[i] = i + 1;
		pre[i] = i - 1;
	}
	if (a[1] && a[2 * n - 1] && a[1] != a[2 * n - 1]) error();
	if (a[1] == 0 || a[2 * n - 1] == 0) a[1] = a[2 * n - 1] = a[1] + a[2 * n - 1];
	vis[0] = 1;
	for (int i = 2 * n - 1; i >= 1; i--) {
		if (a[i]) {
			if (vis[a[i]]) nxtoccur[i] = vis[a[i]];
			vis[a[i]] = i;
		}
	}
	suf[0] = 1, pre[2 * n] = 2 * n - 1;
	solve(1, 2 * n - 1);
	printf("yes\n");
	for (int i = 1; i <= 2 * n - 1; i++)
		printf("%d ", a[i]);
	return 0;
}