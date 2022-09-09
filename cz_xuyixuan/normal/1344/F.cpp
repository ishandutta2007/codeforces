#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e3 + 5;
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
bitset <MAXN> a[MAXN];
int n, m, q, point[MAXN][2];
bool b[MAXN][2][2], ans[MAXN];
void gauss() {
	int k = 0;
	for (int i = 1; i <= n * 2; i++) {
		bool found = false;
		for (int j = k + 1; j <= m; j++)
			if (a[j][i]) {
				swap(a[j], a[k + 1]);
				found = true;
				break;
			}
		if (found) {
			k++;
			for (int j = 1; j <= m; j++)
				if (j != k && a[j][i]) {
					a[j] ^= a[k];
				}
		} else {
			for (int j = 1; j <= m; j++)
				a[j][i] = false;
		}
	}
	for (int j = k + 1; j <= m; j++)
		if (a[j][0]) {
			puts("No");
			exit(0);
		}
	for (int i = 1; i <= k; i++) {
		int pos = 1;
		while (!a[i][pos]) pos++;
		ans[pos] = a[i][0];
	}
}
int main() {
	read(n), read(q);
	for (int i = 1; i <= n; i++) {
		b[i][0][0] = true;
		b[i][1][1] = true;
		point[i][0] = i * 2 - 1;
		point[i][1] = i * 2;
	}
	for (int i = 1; i <= q; i++) {
		string s, c; cin >> s;
		static int k, x[MAXN]; read(k);
		for (int j = 1; j <= k; j++)
			read(x[j]);
		if (s == "mix") {
			cin >> c;
			for (int t = 0; t <= 1; t++) {
				m++;
				for (int j = 1; j <= k; j++) {
					int pos = x[j];
					a[m][point[pos][0]] = b[pos][t][0];
					a[m][point[pos][1]] = b[pos][t][1];
				}
			}
			if (c == "R") a[m - 1][0] = true;
			else if (c == "Y") a[m][0] = true;
			else if (c == "B") a[m - 1][0] = a[m][0] = true;
		} else if (s == "RY") {
			for (int j = 1; j <= k; j++) {
				int pos = x[j];
				swap(b[pos][0][0], b[pos][1][0]);
				swap(b[pos][0][1], b[pos][1][1]);
			}
		} else if (s == "RB") {
			for (int j = 1; j <= k; j++) {
				int pos = x[j];
				b[pos][1][0] ^= b[pos][0][0];
				b[pos][1][1] ^= b[pos][0][1];
			}
		} else {
			for (int j = 1; j <= k; j++) {
				int pos = x[j];
				b[pos][0][0] ^= b[pos][1][0];
				b[pos][0][1] ^= b[pos][1][1];
			}
		}
	}
	gauss();
	puts("Yes");
	for (int i = 1; i <= n; i++) {
		if (ans[point[i][0]] && ans[point[i][1]]) putchar('B');
		else if (ans[point[i][0]]) putchar('R');
		else if (ans[point[i][1]]) putchar('Y');
		else putchar('.');
	}
	puts("");
	return 0;
}