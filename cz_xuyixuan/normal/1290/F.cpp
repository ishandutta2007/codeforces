#include<bits/stdc++.h>
using namespace std;
const int MAXN = 45;
const int P = 998244353;
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
int n, m, Log, a[MAXN], x[MAXN], y[MAXN], bit[MAXN];
int dp[2][MAXN][MAXN][MAXN][MAXN][2][2];
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
int main() {
	read(n), read(m);
	while (m != 0) {
		a[++Log] = m % 2;
		m >>= 1;
	}
	for (int i = 1; i <= n; i++) {
		read(x[i]), read(y[i]);
		bit[i] = 1 << (i - 1);
	}
	int lim = 32;
	dp[Log & 1][0][0][0][0][1][1] = 1;
	for (int i = Log, s = Log & 1, t = s ^ 1; i >= 1; i--, swap(s, t)) {
		memset(dp[t], 0, sizeof(dp[t]));
		for (int px = 0; px <= lim; px++)
		for (int py = 0; py <= lim; py++)
		for (int nx = 0; nx <= lim; nx++)
		for (int ny = 0; ny <= lim; ny++) {
			int vzz = dp[s][px][py][nx][ny][0][0];
			int vzo = dp[s][px][py][nx][ny][0][1];
			int voz = dp[s][px][py][nx][ny][1][0];
			int voo = dp[s][px][py][nx][ny][1][1];
			if (!(vzz || vzo || voz || voo)) continue;
			for (int s = 0; s <= (1 << n) - 1; s++) {
				int incpx = 0, incpy = 0, incnx = 0, incny = 0;
				for (int j = 1; j <= n; j++)
					if (s & bit[j]) {
						if (x[j] >= 0) incpx += x[j];
						else incnx -= x[j];
						if (y[j] >= 0) incpy += y[j];
						else incny -= y[j];
					}
				if (px >= incpx && py >= incpy && nx >= incnx && ny >= incny) {
					int tpx = (px - incpx) * 2;
					int tpy = (py - incpy) * 2;
					int tnx = (nx - incnx) * 2;
					int tny = (ny - incny) * 2;
					if (tpx <= lim && tpy <= lim && tnx <= lim && tny <= lim) {
						update(dp[t][tpx][tpy][tnx][tny][0][0], vzz);
						update(dp[t][tpx][tpy][tnx][tny][0][a[i] == 0], vzo);
						update(dp[t][tpx][tpy][tnx][tny][a[i] == 0][0], voz);
						update(dp[t][tpx][tpy][tnx][tny][a[i] == 0][a[i] == 0], voo);
					}
				}
				if (px + 1 >= incpx && py >= incpy && nx + 1 >= incnx && ny >= incny) {
					int tpx = (px + 1 - incpx) * 2;
					int tpy = (py - incpy) * 2;
					int tnx = (nx + 1 - incnx) * 2;
					int tny = (ny - incny) * 2;
					if (tpx <= lim && tpy <= lim && tnx <= lim && tny <= lim) {
						update(dp[t][tpx][tpy][tnx][tny][0][0], vzz);
						update(dp[t][tpx][tpy][tnx][tny][0][a[i] == 0], vzo);
						if (a[i] == 1) update(dp[t][tpx][tpy][tnx][tny][1][0], voz);
						if (a[i] == 1) update(dp[t][tpx][tpy][tnx][tny][1][a[i] == 0], voo);
					}
				}
				if (px >= incpx && py + 1 >= incpy && nx >= incnx && ny + 1 >= incny) {
					int tpx = (px - incpx) * 2;
					int tpy = (py + 1 - incpy) * 2;
					int tnx = (nx - incnx) * 2;
					int tny = (ny + 1 - incny) * 2;
					if (tpx <= lim && tpy <= lim && tnx <= lim && tny <= lim) {
						update(dp[t][tpx][tpy][tnx][tny][0][0], vzz);
						if (a[i] == 1) update(dp[t][tpx][tpy][tnx][tny][0][1], vzo);
						update(dp[t][tpx][tpy][tnx][tny][a[i] == 0][0], voz);
						if (a[i] == 1) update(dp[t][tpx][tpy][tnx][tny][a[i] == 0][1], voo);
					}
				}
				if (px + 1 >= incpx && py + 1 >= incpy && nx + 1 >= incnx && ny + 1 >= incny) {
					int tpx = (px + 1 - incpx) * 2;
					int tpy = (py + 1 - incpy) * 2;
					int tnx = (nx + 1 - incnx) * 2;
					int tny = (ny + 1 - incny) * 2;
					if (tpx <= lim && tpy <= lim && tnx <= lim && tny <= lim) {
						update(dp[t][tpx][tpy][tnx][tny][0][0], vzz);
						if (a[i] == 1) update(dp[t][tpx][tpy][tnx][tny][0][1], vzo);
						if (a[i] == 1) update(dp[t][tpx][tpy][tnx][tny][1][0], voz);
						if (a[i] == 1) update(dp[t][tpx][tpy][tnx][tny][1][1], voo);
					}
				}
			}
		}
	}
	int ans = P - 1;
	for (int l1 = 0; l1 <= 1; l1++)
	for (int l2 = 0; l2 <= 1; l2++)
		update(ans, dp[0][0][0][0][0][l1][l2]);
	cout << ans << endl;
	return 0;
}