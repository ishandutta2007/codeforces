#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e4 + 5;
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
int n, tot, point[MAXN][2], d[MAXN];
bool vis[MAXN], win[MAXN];
vector <int> s, t, a[MAXN];
int main() {
	read(n);
	int k; read(k);
	while (k--) {
		int x; read(x);
		s.push_back(x);
	}
	read(k);
	while (k--) {
		int x; read(x);
		t.push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		point[i][0] = ++tot;
		d[tot] = s.size();
		point[i][1] = ++tot;
		d[tot] = t.size();
	}
	int l = 0, r = 1;
	static int q[MAXN];
	q[0] = point[1][0], q[1] = point[1][1];
	vis[q[0]] = vis[q[1]] = true;
	win[q[0]] = win[q[1]] = false;
	while (l <= r) {
		int tmp = q[l++], type = tmp % 2;
		int pos = (tmp + 1) / 2;
		if (win[tmp]) {
			if (type) {
				for (unsigned i = 0; i < t.size(); i++) {
					int tnp = point[(pos - t[i] + n - 1) % n + 1][1];
					if (!vis[tnp] && --d[tnp] == 0) {
						vis[tnp] = true;
						win[tnp] = false;
						q[++r] = tnp;
					}
				}
			} else {
				for (unsigned i = 0; i < s.size(); i++) {
					int tnp = point[(pos - s[i] + n - 1) % n + 1][0];
 					if (!vis[tnp] && --d[tnp] == 0) {
						vis[tnp] = true;
						win[tnp] = false;
						q[++r] = tnp;
					}
				}
			}
		} else {
			if (type) {
				for (unsigned i = 0; i < t.size(); i++) {
					int tnp = point[(pos - t[i] + n - 1) % n + 1][1];
					if (!vis[tnp]) {
						vis[tnp] = true;
						win[tnp] = true;
						q[++r] = tnp;
					}
				}
			} else {
				for (unsigned i = 0; i < s.size(); i++) {
					int tnp = point[(pos - s[i] + n - 1) % n + 1][0];
					if (!vis[tnp]) {
						vis[tnp] = true;
						win[tnp] = true;
						q[++r] = tnp;
					}
				}
			}
		}
	}
	for (int i = 2; i <= n; i++)
		if (vis[point[i][0]]) {
			if (win[point[i][0]]) printf("Win ");
			else printf("Lose ");
		} else printf("Loop ");
	printf("\n");
	for (int i = 2; i <= n; i++)
		if (vis[point[i][1]]) {
			if (win[point[i][1]]) printf("Win ");
			else printf("Lose ");
		} else printf("Loop ");
	printf("\n");
	return 0;
}