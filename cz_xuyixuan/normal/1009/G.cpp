#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int MAXS = 1 << 6;
const int MAXC = 7;
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
char s[MAXN];
int n, m, goal, bit[MAXC], a[MAXN], cnt[MAXS], sum[MAXS];
bool tryans(int bit, int pos) {
	for (int i = 0; i <= goal; i++) {
		if (i & bit) cnt[i]--;
		if (i & a[pos]) sum[i]--;
	}
	for (int j = 0; j <= goal; j++) {
		if (cnt[j] > sum[j]) {
			for (int i = 0; i <= goal; i++) {
				if (i & bit) cnt[i]++;
				if (i & a[pos]) sum[i]++;
			}
			return false;
		}
	}
	return true;
}
int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1), read(m);
	for (int i = 1; i <= 6; i++)
		bit[i] = 1 << (i - 1);
	goal = (1 << 6) - 1;
	for (int i = 1; i <= n; i++)
		a[i] = goal;
	for (int i = 1; i <= m; i++) {
		int pos; char tmp[15];
		scanf("%d %s", &pos, tmp + 1);
		int len = strlen(tmp + 1), tans = 0;
		for (int j = 1; j <= len; j++)
			tans += bit[tmp[j] - 'a' + 1];
		a[pos] = tans;
	}
	for (int i = 1; i <= n; i++) {
		int tmp = bit[s[i] - 'a' + 1];
		for (int j = 0; j <= goal; j++) {
			if (j & tmp) cnt[j]++;
			if (j & a[i]) sum[j]++;
		}
	}
	for (int i = 0; i <= goal; i++)
		if (cnt[i] > sum[i]) {
			printf("Impossible\n");
			return 0;
		}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 6; j++)
			if ((a[i] & bit[j]) != 0 && tryans(bit[j], i)) {
				putchar('a' + j - 1);
				break;
			}
	}
	printf("\n");
	return 0;
}