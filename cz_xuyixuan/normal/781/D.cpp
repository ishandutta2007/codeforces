#include<bits/stdc++.h>
using namespace std;
const int MAXN = 505;
const int MAXLOG = 61;
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
bool mp[MAXLOG][2][MAXN][MAXN];
bitset <MAXN> row[2][MAXN], col[2][MAXN];
int main() {
	int n, m; read(n), read(m);
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		read(x), read(y), read(z);
		mp[0][z][x][y] = true;
	}
	for (int p = 1; p < MAXLOG; p++) {
		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			row[0][i][j] = mp[p - 1][0][i][j];
			row[1][i][j] = mp[p - 1][1][i][j];
			col[0][j][i] = mp[p - 1][0][i][j];
			col[1][j][i] = mp[p - 1][1][i][j];
		}
		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			mp[p][0][i][j] = (row[0][i] & col[1][j]).count() != 0;
			mp[p][1][i][j] = (row[1][i] & col[0][j]).count() != 0;
		}
	}
	bool type = 0; long long ans = 0;
	static bool now[MAXN], tmp[MAXN];
	now[1] = true;
	for (int p = MAXLOG - 1; p >= 0; p--) {
		memset(tmp, false, sizeof(tmp));
		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			tmp[j] |= now[i] & mp[p][type][i][j];
		bool succeed = false;
		for (int i = 1; i <= n; i++)
			succeed |= tmp[i];
		if (succeed) {
			ans += 1ll << p; type ^= true;
			memcpy(now, tmp, sizeof(tmp));
		}
	}
	if (ans > 1e18) printf("-1\n");
	else writeln(ans);
	return 0;
}