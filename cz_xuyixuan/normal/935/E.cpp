#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10005;
const int MAXM = 105;
const int INF = 1e7;
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
char s[MAXN];
int size, p, m;
int sum[MAXN], lc[MAXN], rc[MAXN];
int Max[MAXN][MAXM];
int Min[MAXN][MAXM];
int split(int l, int r) {
	int cnt = 0;
	for (int i = l; i <= r; i++) {
		if (s[i] == '(') cnt++;
		if (s[i] == ')') cnt--;
		if (s[i] == '?' && cnt == 0) return i;
	}
	return -1;
}
void chkmax(int &x, int y) {x = max(x, y); }
void chkmin(int &x, int y) {x = min(x, y); }
void workp(int pos, int l, int r) {
	if (l == r) {
		Max[pos][0] = Min[pos][0] = s[l] - '0';
		return;
	}
	int mid = split(l + 1, r - 1);
	lc[pos] = ++size;
	rc[pos] = ++size;
	workp(lc[pos], l + 1, mid - 1);
	workp(rc[pos], mid + 1, r - 1);
	sum[pos] = 1 + sum[lc[pos]] + sum[rc[pos]];
	for (int i = 0; i <= p && i <= sum[pos]; i++) {
		Max[pos][i] = -INF; Min[pos][i] = INF;
		for (int j = 0; j <= i && j <= sum[lc[pos]]; j++) {
			int k = i - j;
			if (k > sum[rc[pos]]) continue;
			chkmax(Max[pos][i], Max[lc[pos]][j] - Min[rc[pos]][k]);
			chkmin(Min[pos][i], Min[lc[pos]][j] - Max[rc[pos]][k]);
		}
		if (i == 0) continue;
		for (int j = 0; j <= i - 1 && j <= sum[lc[pos]]; j++) {
			int k = i - j - 1;
			if (k > sum[rc[pos]]) continue;
			chkmax(Max[pos][i], Max[lc[pos]][j] + Max[rc[pos]][k]);
			chkmin(Min[pos][i], Min[lc[pos]][j] + Min[rc[pos]][k]);
		}
	}
}
void workm(int pos, int l, int r) {
	if (l == r) {
		Max[pos][0] = Min[pos][0] = s[l] - '0';
		return;
	}
	int mid = split(l + 1, r - 1);
	lc[pos] = ++size;
	rc[pos] = ++size;
	workm(lc[pos], l + 1, mid - 1);
	workm(rc[pos], mid + 1, r - 1);
	sum[pos] = 1 + sum[lc[pos]] + sum[rc[pos]];
	for (int i = 0; i <= m && i <= sum[pos]; i++) {
		Max[pos][i] = -INF; Min[pos][i] = INF;
		for (int j = 0; j <= i && j <= sum[lc[pos]]; j++) {
			int k = i - j;
			if (k > sum[rc[pos]]) continue;
			chkmax(Max[pos][i], Max[lc[pos]][j] + Max[rc[pos]][k]);
			chkmin(Min[pos][i], Min[lc[pos]][j] + Min[rc[pos]][k]);
		}
		if (i == 0) continue;
		for (int j = 0; j <= i - 1 && j <= sum[lc[pos]]; j++) {
			int k = i - j - 1;
			if (k > sum[rc[pos]]) continue;
			chkmax(Max[pos][i], Max[lc[pos]][j] - Min[rc[pos]][k]);
			chkmin(Min[pos][i], Min[lc[pos]][j] - Max[rc[pos]][k]);
		}
	}
}
int main() {
	scanf("%s", s + 1);
	read(p), read(m);
	if (p <= m) {
		workp(++size, 1, strlen(s + 1));
		printf("%d\n", Max[1][p]);
	} else {
		workm(++size, 1, strlen(s + 1));
		printf("%d\n", Max[1][m]);
	}
	return 0;
}