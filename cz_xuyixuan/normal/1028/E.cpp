#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
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
int n, Max, a[MAXN];
long long ans[MAXN];
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]), chkmax(Max, a[i]);
	if (Max == 0) {
		printf("YES\n");
		for (int i = 1; i <= n; i++)
			printf("%d ", 1);
		printf("\n");
		return 0;
	}
	a[0] = a[n];
	for (int i = 1; i <= n; i++)
		if (a[i] == Max && a[i - 1] != Max) {
			long long now = a[i];
			int pos = i - 1; ans[i] = now;
			if (pos == 0) pos = n;
			while (pos != i) {
				if (a[pos] == 0 && now == a[i]) now += a[i];
				else now += a[pos];
				ans[pos] = now;
				if (--pos == 0) pos = n;
			}
			printf("YES\n");
			for (int i = 1; i <= n; i++)
				write(ans[i]), putchar(' ');
			printf("\n");
			return 0;
		}
	printf("NO\n");
	return 0;
}