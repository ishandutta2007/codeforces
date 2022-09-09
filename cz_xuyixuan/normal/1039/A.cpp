#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
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
int n, x[MAXN], cnt[MAXN][2];
ll t, a[MAXN], b[MAXN];
int main() {
	read(n), read(t);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= n; i++) {
		read(x[i]);
		if (x[i] < i) {
			printf("No\n");
			return 0;
		}
		chkmax(b[x[i]], a[i] + t);
		cnt[1][0]++, cnt[i][0]--;
		cnt[x[i] + 1][0]++, cnt[n + 1][0]--;
		cnt[i][1]++, cnt[x[i]][1]--;
	}
	for (int i = 1; i <= n; i++) {
		cnt[i][0] += cnt[i - 1][0];
		cnt[i][1] += cnt[i - 1][1];
		if (cnt[i][0]) chkmax(b[i], a[i] + t);
		if (cnt[i][1]) chkmax(b[i], a[i + 1] + t);
		chkmax(b[i], b[i - 1] + 1);
	}
	for (int i = 1; i <= n; i++) {
		if (x[i] == n) continue;
		if (b[x[i]] >= a[x[i] + 1] + t) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	for (int i = 1; i <= n; i++)
		write(b[i]), putchar(' ');
	printf("\n");
	return 0;
}