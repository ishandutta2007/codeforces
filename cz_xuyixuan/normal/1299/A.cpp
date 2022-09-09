#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
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
int a[MAXN], pre[MAXN], suf[MAXN];
int main() {
	int n; read(n);
	int ans = 0, pos = 1;
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		pre[i] = pre[i - 1] | a[i];
	}
	for (int i = n; i >= 1; i--)
		suf[i] = suf[i + 1] | a[i];
	for (int i = 1; i <= n; i++) {
		int tmp = pre[i - 1] | suf[i + 1];
		int res = a[i] & (~tmp);
		if (res > ans) {
			ans = res;
			pos = i;
		}
	}
	swap(a[pos], a[1]);
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	return 0;
}