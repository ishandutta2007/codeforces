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
int n, ans[MAXN];
vector <int> a[MAXN];
void dfs(int pos, int fa, int col, int dol) {
	int tcol = 1;
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i] != fa) {
			int tmp = a[pos][i];
			while (tcol == col || tcol == dol) tcol++;
			ans[tmp] = tcol;
			dfs(tmp, pos, dol, tcol);
			tcol++;
		}
}
int main() {
	read(n);
	for (int i = 1; i <= n - 1; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	int Max = 0;
	for (int i = 1; i <= n; i++)
		if (a[i].size() >= Max) Max = a[i].size() + 1;
	writeln(Max);
	for (int i = 1; i <= n; i++)
		if (a[i].size() + 1 == Max) {
			ans[i] = 1;
			for (unsigned j = 0; j < a[i].size(); j++) {
				int tmp = a[i][j];
				ans[tmp] = j + 2;
				dfs(tmp, i, 1, j + 2);
			}
			for (int j = 1; j <= n; j++)
				printf("%d ", ans[j]);
			break;
		}
	return 0;
}