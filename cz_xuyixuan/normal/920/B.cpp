#include<bits/stdc++.h>
using namespace std;
const int MAXN = 8005;
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
int l[MAXN], r[MAXN], ans[MAXN], q[MAXN];
int main() {
	int T; read(T);
	while (T--) {
		int n; read(n);
		for (int i = 1; i <= n; i++)
			read(l[i]), read(r[i]);
		int ql = 0, qr = -1;
		memset(ans, 0, sizeof(ans));
		for (int timer = 1; timer <= MAXN; timer++) {
			for (int j = 1; j <= n; j++)
				if (l[j] == timer) q[++qr] = j;
			while (ql <= qr && r[q[ql]] < timer) ql++;
			if (ql <= qr) ans[q[ql++]] = timer;
		}
		for (int i = 1; i <= n; i++)
			printf("%d ", ans[i]);
		printf("\n");
	}
	return 0;
}