#include<bits/stdc++.h>
using namespace std;
const int MAXN = 505;
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
bool res[MAXN];
int dist[MAXN][MAXN];
int main() {
	int n, m; read(n), read(m);
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		if (i != j) dist[i][j] = n;
	for (int i = 1; i <= m; i++) {
		int k, x; read(k), read(x), k--;
		while (k--) {
			int y; read(y);
			dist[x][y] = dist[y][x] = 1, x = y;
		}
	}
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	for (int k = 1; k <= n; k++)
		chkmin(dist[j][k], dist[j][i] + dist[i][k]);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			res[j] = true;
		while (true) {
			int Min = INT_MAX, pos = 0;
			for (int j = 1; j <= n; j++)
				if (res[j]) {
					int tmp = 0;
					for (int k = 1; k <= n; k++)
						if (res[k]) tmp += dist[j][k];
					if (tmp < Min) {
						Min = tmp;
						pos = j;
					}
				}
			cout << pos << endl;
			string out; cin >> out;
			if (out == "FOUND") break;
			int r; cin >> r;
			for (int j = 1; j <= n; j++)
				res[j] &= dist[j][r] < dist[j][pos];
		}
	}
	return 0;
}