#include<bits/stdc++.h>
using namespace std;
const int MAXN = 55;
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int n, pos, a[MAXN][MAXN]; char c;
int f[MAXN][MAXN], matchx[MAXN], matchy[MAXN], now[MAXN];
int main() {
	int T; read(T);
	while (T--) {
		read(n);
		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			read(a[i][j]);
		cout << 'B' << endl;
		cin >> c >> pos;
		if (c == 'D') {
			for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				a[i][j] = n * n + 1 - a[i][j];
		}
		bool flg = pos > n;
		if (flg) {
			for (int i = 1; i <= n; i++)
			for (int j = i; j <= n; j++)
				swap(a[i][j], a[j][i]);
		}
		static int q[MAXN * MAXN]; int l = 0, r = -1;
		for (int i = 1; i <= n; i++) {
			now[i] = 1, q[++r] = i;
			matchx[i] = matchy[i] = 0;
			for (int j = 1; j <= n; j++)
				f[i][j] = j;
			sort(f[i] + 1, f[i] + n + 1, [&] (int x, int y) {return a[i][x] < a[i][y]; });
		}
		while (l <= r) {
			int x = q[l++], y = f[x][now[x]];
			if (matchy[y] == 0) {
				matchx[x] = y;
				matchy[y] = x;
			} else if (a[x][y] > a[matchy[y]][y]) {
				q[++r] = matchy[y];
				matchx[matchy[y]] = 0;
				matchx[x] = y;
				matchy[y] = x;
			} else q[++r] = x;
			now[x]++;
		}
		while (true) {
			if (flg) cout << matchx[pos - n] << endl;
			else cout << matchx[pos] + n << endl;
			cin >> pos; if (pos == -1) break;
		}
	}
	return 0;
}