#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
const char rev[5] = {' ', 'A', 'C', 'G', 'T'};
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
int n, m, Min, r[MAXN][2][5], c[MAXN][2][5];
bool vis[5]; vector <int> ans[MAXN], s[MAXN];
int verans() {
	int res = 0;
	for (int i = 1, now = 1, nxt = 2; i <= n; i++, swap(now, nxt))
		res += m - max(r[i][0][ans[now][1]] + r[i][1][ans[now][2]], r[i][0][ans[now][2]] + r[i][1][ans[now][1]]);
	return res;
}
int horans() {
	int res = 0;
	for (int i = 1, now = 1, nxt = 2; i <= m; i++, swap(now, nxt))
		res += n - max(c[i][0][ans[1][now]] + c[i][1][ans[2][now]], c[i][0][ans[2][now]] + c[i][1][ans[1][now]]);
	return res;
}
void output() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			putchar(rev[ans[i][j]]);
		putchar('\n');
	}
	exit(0);
}
void getverans() {
	int tmp[3][3];
	for (int i = 1; i <= 2; i++)
	for (int j = 1; j <= 2; j++)
		tmp[i][j] = ans[i][j];
	for (int i = 1, now = 1, nxt = 2; i <= n; i++, swap(now, nxt)) {
		if (r[i][0][tmp[now][1]] + r[i][1][tmp[now][2]] > r[i][0][tmp[now][2]] + r[i][1][tmp[now][1]]) {
			for (int j = 1; j <= m; j++)
				if (j & 1) ans[i][j] = tmp[now][2];
				else ans[i][j] = tmp[now][1];
		} else {
			for (int j = 1; j <= m; j++)
				if (j & 1) ans[i][j] = tmp[now][1];
				else ans[i][j] = tmp[now][2];
		}
	}
	output();
}
void gethorans() {
	int tmp[3][3];
	for (int i = 1; i <= 2; i++)
	for (int j = 1; j <= 2; j++)
		tmp[i][j] = ans[i][j];
	for (int i = 1, now = 1, nxt = 2; i <= m; i++, swap(now, nxt)) {
		if (c[i][0][tmp[1][now]] + c[i][1][tmp[2][now]] > c[i][0][tmp[2][now]] + c[i][1][tmp[1][now]]) {
			for (int j = 1; j <= n; j++)
				if (j & 1) ans[j][i] = tmp[2][now];
				else ans[j][i] = tmp[1][now];
		} else {
			for (int j = 1; j <= n; j++)
				if (j & 1) ans[j][i] = tmp[1][now];
				else ans[j][i] = tmp[2][now];
		}
	}
	output();
}
void getans(int x, int y) {
	if (x == 3) {
		if (Min == verans()) getverans();
		if (Min == horans()) gethorans();
		return;
	}
	int tx = x, ty = y + 1;
	if (ty == 3) ty = 1, tx++;
	for (int i = 1; i <= 4; i++)
		if (!vis[i]) {
			vis[i] = true;
			ans[x][y] = i;
			getans(tx, ty);
			vis[i] = false;
		}
}
void work(int x, int y) {
	if (x == 3) {
		chkmin(Min, verans());
		chkmin(Min, horans());
		return;
	}
	int tx = x, ty = y + 1;
	if (ty == 3) ty = 1, tx++;
	for (int i = 1; i <= 4; i++)
		if (!vis[i]) {
			vis[i] = true;
			ans[x][y] = i;
			work(tx, ty);
			vis[i] = false;
		}
}
int main() {
	read(n), read(m);
	s[0].resize(m + 2);
	s[n + 1].resize(m + 2);
	for (int i = 1; i <= n; i++) {
		s[i].resize(m + 2);
		ans[i].resize(m + 1);
		static char tmp[MAXN];
		scanf("\n%s", tmp + 1);
		for (int j = 1; j <= m; j++) {
			if (tmp[j] == 'A') s[i][j] = 1;
			if (tmp[j] == 'C') s[i][j] = 2;
			if (tmp[j] == 'G') s[i][j] = 3;
			if (tmp[j] == 'T') s[i][j] = 4;
			r[i][j & 1][s[i][j]]++;
			c[j][i & 1][s[i][j]]++;
		}
	}
	Min = n * m + 5;
	work(1, 1);
	//cerr << Min << endl;
	getans(1, 1);
	return 0;
}