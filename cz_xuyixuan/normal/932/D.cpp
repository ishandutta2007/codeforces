#include<bits/stdc++.h>
using namespace std;
const int MAXN = 400005;
const int MAXLOG = 20;
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
int weight[MAXN];
int gather[MAXN][MAXLOG];
long long sum[MAXN][MAXLOG];
int father[MAXN][MAXLOG], Max[MAXN][MAXLOG];
int main() {
	int n, cnt = 1; read(n);
	long long lastans = 0;
	for (int q = 1; q <= n; q++) {
		int opt; long long e, f;
		read(opt), read(e), read(f);
		e ^= lastans; f ^= lastans;
		if (opt == 1) {
			father[++cnt][0] = e;
			sum[cnt][0] = weight[cnt] = Max[cnt][0] = f;
			for (int i = 1; i < MAXLOG; i++) {
				father[cnt][i] = father[father[cnt][i - 1]][i - 1];
				Max[cnt][i] = max(Max[cnt][i - 1], Max[father[cnt][i - 1]][i - 1]);	
			}
			int now = father[cnt][0];
			for (int i = MAXLOG - 1; i >= 0; i--)
				if (Max[now][i] < weight[cnt]) now = father[now][i];
			gather[cnt][0] = now;
			for (int i = 1; i < MAXLOG; i++) {
				gather[cnt][i] = gather[gather[cnt][i - 1]][i - 1];
				sum[cnt][i] = sum[cnt][i - 1] + sum[gather[cnt][i - 1]][i - 1];	
			}
		} else {
			int ans = 0, now = e;
			for (int i = MAXLOG - 1; i >= 0; i--)
				if (gather[now][i] != 0 && f >= sum[now][i]) {
					f -= sum[now][i];
					now = gather[now][i];
					ans += 1 << i;
				}
			if (f >= sum[now][0]) ans++;
			writeln(lastans = ans);
		}
	}
	return 0;
}