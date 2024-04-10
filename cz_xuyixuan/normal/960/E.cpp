#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
const int P = 1e9 + 7;
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
int n, val[MAXN];
int size[MAXN], father[MAXN];
vector <int> a[MAXN];
int f[MAXN][2], g[MAXN][2];
void workg(int pos, int fa) {
	if (fa == 0) g[pos][0] = g[pos][1] = 0;
	else {
		g[pos][0] = f[fa][1] + g[fa][1] - f[pos][0];
		g[pos][1] = f[fa][0] + g[fa][0] - f[pos][1];
	}
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i] != fa) workg(a[pos][i], pos);
}
void workf(int pos, int fa) {
	size[pos] = 1; father[pos] = fa;
	f[pos][0] = 1, f[pos][1] = 0;
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i] != fa) {
			workf(a[pos][i], pos);
			size[pos] += size[a[pos][i]];
			f[pos][0] += f[a[pos][i]][1];
			f[pos][1] += f[a[pos][i]][0];
		}
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		read(val[i]);
		if (val[i] < 0) val[i] += P;
	}
	for (int i = 1; i <= n - 1; i++) {
		int x, y;
		read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	workf(1, 0);
	workg(1, 0);
	int ans = 0;
	for (int pos = 1; pos <= n; pos++) {
		ans = (ans + 1ll * val[pos] * n) % P;
		for (unsigned i = 0; i < a[pos].size(); i++)
			if (a[pos][i] == father[pos]) {
				int lft = size[pos];
				ans = (ans + 1ll * lft * val[pos] % P * g[pos][0]) % P;
				ans = (ans + 1ll * lft * (P - val[pos]) % P * g[pos][1]) % P;
			} else {
				int lft = n - size[a[pos][i]];
				ans = (ans + 1ll * lft * val[pos] % P * f[a[pos][i]][1]) % P;
				ans = (ans + 1ll * lft * (P - val[pos]) % P * f[a[pos][i]][0]) % P;
			}
	}
	writeln(ans);
	return 0;
}