#include<bits/stdc++.h>
using namespace std;
const int MAXN = 6e5 + 5;
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
int tr, fl, ans, f[MAXN], s[MAXN][2];
int find(int x) {
	if (f[x] == x) return x;
	else return f[x] = find(f[x]);
}
char st[MAXN];
vector <int> a[MAXN];
int calc(int x) {
	x = find(x);
	if (x == tr) return s[x][1];
	if (x == fl) return s[x][0];
	return min(s[x][1], s[x][0]);
}
void merge(int x, int y) {
	if (find(x) == find(y)) return;
	x = find(x), y = find(y);
	if (x > y) swap(x, y);
	f[x] = y, s[y][0] += s[x][0], s[y][1] += s[x][1];
}
int main() {
	int n, m; read(n), read(m);
	scanf("\n%s", st + 1);
	for (int i = 1; i <= m; i++) {
		int x; read(x);
		while (x--) {
			int y; read(y);
			a[y].push_back(i);
		}
	}
	for (int i = 1; i <= m; i++) {
		f[i] = i, f[i + m] = i + m;
		s[i][0] = 1, s[i + m][1] = 1;
	}
	tr = m * 2 + 1, fl = m * 2 + 2, ans = 0;
	f[tr] = tr, f[fl] = fl;
	for (int i = 1; i <= n; i++) {
		int x, y;
		if (a[i].size() != 0) {
			if (st[i] == '0') {
				if (a[i].size() == 1) {
					int x = a[i][0];
					if (find(x + m) != find(tr)) {
						ans -= calc(x + m);
						ans -= calc(tr);
						merge(x + m, tr);
						merge(x, fl);
						ans += calc(x + m);
					}
				} else {
					int x = a[i][0], y = a[i][1];
					if (find(x) != find(y + m)) {
						ans -= calc(x);
						ans -= calc(y);
						merge(x + m, y);
						merge(x, y + m);
						ans += calc(x);
					}
				}
			} else {
				if (a[i].size() == 1) {
					int x = a[i][0];
					if (find(x) != find(tr)) {
						ans -= calc(x);
						ans -= calc(tr);
						merge(x, tr);
						merge(x + m, fl);
						ans += calc(x);
					}
				} else {
					int x = a[i][0], y = a[i][1];
					if (find(x) != find(y)) {
						ans -= calc(x);
						ans -= calc(y);
						merge(x, y);
						merge(x + m, y + m);
						ans += calc(x);
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}