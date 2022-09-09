#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
const int num[6] = {0, 1, 2, 1, 2, 0};
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
int a[MAXN], ans[MAXN][6];
int main() {
	int n; read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 4; j++) {
			ans[i][j] += a[i] == num[j];
			for (int k = j; k <= 4; k++)
				ans[i + 1][k] = max(ans[i + 1][k], ans[i][j]);
		}
	}
	int Ans = 0;
	for (int i = 1; i <= 4; i++)
		Ans = max(Ans, ans[n][i]);
	writeln(Ans);
	return 0;
}