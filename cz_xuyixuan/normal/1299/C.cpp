#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
typedef long long ll;
typedef double ld;
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
int n; ld a[MAXN], s[MAXN];
int top, q[MAXN];
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]), s[i] = s[i - 1] + a[i];
	for (int i = n; i >= 1; i--) {
		q[++top] = i;
		while (top >= 2 && (s[q[top]] - s[i - 1]) / (q[top] - (i - 1)) > (s[q[top - 1]] - s[q[top]]) / (q[top - 1] - q[top])) top--;
	}
	q[top + 1] = 0;
	for (int i = top; i >= 1; i--) {
		ld res = (s[q[i]] - s[q[i + 1]]) / (q[i] - q[i + 1]);
		for (int j = q[i + 1] + 1; j <= q[i]; j++)
			printf("%.10lf\n", res);
	}
	return 0;
}