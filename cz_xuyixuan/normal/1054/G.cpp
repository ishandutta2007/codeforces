#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e3 + 5;
const int MAXM = MAXN * MAXN;
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
int n, m, f[MAXN], ansx[MAXN], ansy[MAXN];
int x[MAXM], y[MAXM], len[MAXM], pos[MAXM];
bitset <MAXN> a[MAXN], b[MAXN], now;
vector <int> e[MAXN];
int F(int x) {
	if (f[x] == x) return x;
	else return f[x] = F(f[x]);
}
void work(int pos) {
	if (now[pos]) now[pos] = 0;
	else return;
	for (auto x : e[pos]) work(x);
}
bool check() {
	for (int i = 1; i <= n; i++)
		e[i].clear();
	for (int i = 1; i <= n - 1; i++) {
		e[ansx[i]].push_back(ansy[i]);
		e[ansy[i]].push_back(ansx[i]);
	}
	for (int i = 1; i <= m; i++) {
		now = a[i];
		work(now._Find_first());
		if (now.count()) return false;
	}
	return true;
}
int main() {
	int T; read(T);
	while (T--) {
		read(n), read(m);
		for (int i = 1; i <= n || i <= m; i++)
			a[i].reset(), b[i].reset();
		for (int i = 1; i <= m; i++) {
			static char s[MAXN];
			scanf("\n%s", s + 1);
			for (int j = 1; j <= n; j++)
				a[i][j] = b[j][i] = s[j] - '0';
		}
		int tot = 0;
		for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) {
			tot++, pos[tot] = tot;
			x[tot] = i, y[tot] = j, len[tot] = (b[i] & b[j]).count();
		}
		sort(pos + 1, pos + tot + 1, [&] (int x, int y) {return len[x] > len[y];});
		for (int i = 1; i <= n; i++)
			f[i] = i;
		int cnt = 0;
		for (int i = 1; i <= tot; i++) {
			int tmp = pos[i];
			if (F(x[tmp]) != F(y[tmp])) {
				f[F(x[tmp])] = F(y[tmp]), cnt++;
				ansx[cnt] = x[tmp];
				ansy[cnt] = y[tmp];
			}
		}
		if (check()) {
			printf("YES\n");
			for (int i = 1; i <= cnt; i++)
				printf("%d %d\n", ansx[i], ansy[i]);
		} else printf("NO\n");
	}
	return 0;
}