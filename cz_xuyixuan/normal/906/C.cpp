#include<bits/stdc++.h>
using namespace std;
#define MAXN	25
#define INF	1e9
#define MAXS	10000005
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
int n, m, ans = INF, cans;
int mem[MAXS];
int num[MAXN];
bool mp[MAXN][MAXN];
int get(int curr) {
	if (mem[curr] != -1) return mem[curr];
	if (curr == (1 << n + 1) - 2) return mem[curr] = 0;
	int ans = INF;
	for (int i = 1; i <= n; i++) {
		int tmp = 1 << i;
		if ((tmp & curr) && (curr | num[i]) != curr) ans = min(ans, 1 + get(curr | num[i]));
	}
	return mem[curr] = ans;
}
void dfs(int pos, int curr) {
	if (pos == n + 1) {
		int tmp = get(curr);
		if (tmp < ans) {
			ans = tmp;
			cans = curr;
		}
		return;
	}
	bool flg = true;
	for (int i = 1; i < pos; i++) {
		int tmp = 1 << i;
		if ((tmp & curr) && mp[i][pos] == false) {
			flg = false;
			break;
		}
	}
	if (flg) dfs(pos + 1, curr | (1 << pos));
	dfs(pos + 1, curr);
}
void work(int curr, int ans) {
	if (ans == 0) return;
	for (int i = 1; i <= n; i++) {
		int tmp = 1 << i;
		if ((tmp & curr) && get(curr | num[i]) == ans - 1) {
			cout << i << ' ';
			work(curr | num[i], ans - 1);
			return;
		}
	}
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		read(x), read(y);
		mp[x][y] = mp[y][x] = true;
		num[x] |= 1 << y;
		num[y] |= 1 << x;
	}
	memset(mem, -1, sizeof(mem));
	dfs(1, 0);
	cout << ans << endl;
	work(cans, ans);
	return 0;
}