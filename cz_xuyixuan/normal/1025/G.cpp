#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int P = 1e9 + 7;
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
int n, bit[MAXN], cnt[MAXN], a[MAXN];
int main() {
	read(n), bit[0] = 1;
	for (int i = 1; i <= n; i++) {
		bit[i] = bit[i - 1] * 2 % P;
		read(a[i]);
		if (a[i] != -1) cnt[a[i]]++;
	}
	int ans = bit[n - 1] - 1;
	for (int i = 1; i <= n; i++)
		if (a[i] == -1) ans = (ans - (bit[cnt[i]] - 1)) % P;
	writeln((ans + P) % P);
	return 0;
}