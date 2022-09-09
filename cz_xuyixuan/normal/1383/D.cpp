#include<bits/stdc++.h>
using namespace std;
const int MAXN = 255;
const int MAXM = 1e5 + 5;
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
int n, m, a[MAXN][MAXN];
bool r[MAXM], c[MAXM];
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
		read(a[i][j]);
	for (int i = 1; i <= n; i++) {
		int Max = 0;
		for (int j = 1; j <= m; j++)
			chkmax(Max, a[i][j]);
		r[Max] = true;
	}
	for (int i = 1; i <= m; i++) {
		int Max = 0;
		for (int j = 1; j <= n; j++)
			chkmax(Max, a[j][i]);
		c[Max] = true;
	}
	deque <pair <int, int>> q;
	int cntr = 0, cntc = 0;
	for (int i = n * m; i >= 1; i--) {
		if (!r[i] && !c[i]) {
			a[q.front().first][q.front().second] = i;
			q.pop_front();
		} else {
			cntr += r[i];
			cntc += c[i];
			a[cntr][cntc] = i;
			if (r[i]) {
				for (int j = cntc - 1; j >= 1; j--)
					q.emplace_back(cntr, j);
			}
			if (c[i]) {
				for (int j = cntr - 1; j >= 1; j--)
					q.emplace_back(j, cntc);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	return 0;
}