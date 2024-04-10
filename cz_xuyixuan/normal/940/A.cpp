#include<bits/stdc++.h>
using namespace std;
const int MAXN = 105;
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
int n, k, cnt[MAXN], pre[MAXN], bck[MAXN];
int main() {
	read(n), read(k);
	for (int i = 1; i <= n; i++) {
		int x; read(x);
		cnt[x]++;
	}
	for (int i = 1; i < MAXN; i++)
		pre[i] = pre[i - 1] + cnt[i];
	for (int i = MAXN - 1; i >= 0; i--)
		bck[i] = bck[i + 1] + cnt[i];
	int ans = n - 1;
	for (int i = 1, j = k + 1; j <= 101; i++, j++)
		ans = min(ans, pre[i - 1] + bck[j + 1]);
	writeln(ans);
	return 0;
}