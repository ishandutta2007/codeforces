#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e3 + 5;
const int MAXQ = 8e6 + 5;
const int MIDQ = 4e6 + 2;
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
char mp[MAXN][MAXN];
int x[MAXQ], y[MAXQ], ml[MAXQ], mr[MAXQ];
int main() {
	int n, m;
	read(n), read(m);
	int l = MIDQ, r = MIDQ;
	read(x[MIDQ]), read(y[MIDQ]);
	read(ml[MIDQ]), read(mr[MIDQ]);
	for (int i = 1; i <= n; i++)
		scanf("%s", mp[i] + 1);
	mp[x[MIDQ]][y[MIDQ]] = '*';
	int ans = 0;
	while (l <= r) {
		int nx = x[l], ny = y[l], tx, ty; ans++;
		int nml = ml[l], nmr = mr[l++];
		tx = nx - 1, ty = ny;
		if (mp[tx][ty] == '.') {
			l--, x[l] = tx, y[l] = ty;
			ml[l] = nml, mr[l] = nmr;
			mp[tx][ty] = '*';
		}
		tx = nx + 1, ty = ny;
		if (mp[tx][ty] == '.') {
			l--, x[l] = tx, y[l] = ty;
			ml[l] = nml, mr[l] = nmr;
			mp[tx][ty] = '*';
		}
		tx = nx, ty = ny - 1;
		if (nml != 0 && mp[tx][ty] == '.') {
			r++, x[r] = tx, y[r] = ty;
			ml[r] = nml - 1, mr[r] = nmr;
			mp[tx][ty] = '*';
		}
		tx = nx, ty = ny + 1;
		if (nmr != 0 && mp[tx][ty] == '.') {
			r++, x[r] = tx, y[r] = ty;
			ml[r] = nml, mr[r] = nmr - 1;
			mp[tx][ty] = '*';
		}
	}
	printf("%d\n", ans);
	return 0;
}