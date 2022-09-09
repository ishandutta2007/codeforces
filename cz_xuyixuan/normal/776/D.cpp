#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
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
int n, m, f[MAXN], r[MAXN], point[MAXN][2];
vector <int> p[MAXN];
int F(int x) {
	if (f[x] == x) return x;
	else return f[x] = F(f[x]);
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(r[i]);
	for (int i = 1; i <= m; i++) {
		int x; read(x);
		for (int j = 1; j <= x; j++) {
			int pos; read(pos);
			p[pos].push_back(i);
		}
	}
	int tot = 0;
	for (int i = 1; i <= m; i++) {
		point[i][0] = ++tot;
		point[i][1] = ++tot;
	}
	for (int i = 1; i <= tot; i++)
		f[i] = i;
	for (int i = 1; i <= n; i++) {
		int x = p[i][0];
		int y = p[i][1];
		if (r[i] == 0) {
			f[F(point[x][0])] = F(point[y][1]);
			f[F(point[x][1])] = F(point[y][0]);
		} else {
			f[F(point[x][0])] = F(point[y][0]);
			f[F(point[x][1])] = F(point[y][1]);
		}
	}
	for (int i = 1; i <= m; i++)
		if (F(point[i][0]) == F(point[i][1])) {
			printf("NO\n");
			return 0;
		}
	printf("YES\n");
	return 0;
}