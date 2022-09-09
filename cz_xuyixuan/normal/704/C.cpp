#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int P = 1e9 + 7;
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
struct info {
	int dest, home;
	bool x, y;
};
vector <info> a[MAXN];
int n, m, ans[2], cur[2][2][2];
bool vis[MAXN], res[MAXN][2];
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
void work(int pos, int fa) {
	vis[pos] = true;
	for (auto x : a[pos])
		if (x.home != fa) {
			if (vis[x.dest]) {
				int tmp[2] = {0, 0};
				for (int i = 0; i <= 1; i++)
				for (int j = 0; j <= 1; j++)
				for (int k = 0; k <= 1; k++)
					update(tmp[k ^ ((j ^ x.x) || (i ^ x.y))], cur[i][j][k]);
				int res[2] = {0, 0};
				for (int i = 0; i <= 1; i++)
				for (int j = 0; j <= 1; j++)
					update(res[i ^ j], 1ll * tmp[i] * ans[j] % P);
				ans[0] = res[0];
				ans[1] = res[1];
			} else {
				int nxt[2][2][2];
				memset(nxt, 0, sizeof(nxt));
				for (int i = 0; i <= 1; i++)
				for (int j = 0; j <= 1; j++)
				for (int k = 0; k <= 1; k++)
				for (int t = 0; t <= 1; t++)
					update(nxt[i][t][k ^ res[x.dest][t ^ 1] ^ ((j ^ x.x) || (t ^ x.y))], cur[i][j][k]);
				memcpy(cur, nxt, sizeof(nxt));
				work(x.dest, x.home);
			}
			return;
		}
	int tmp[2] = {0, 0};
	for (int i = 0; i <= 1; i++)
	for (int j = 0; j <= 1; j++)
	for (int k = 0; k <= 1; k++)
		update(tmp[k], cur[i][j][k]);
	int res[2] = {0, 0};
	for (int i = 0; i <= 1; i++)
	for (int j = 0; j <= 1; j++)
		update(res[i ^ j], 1ll * tmp[i] * ans[j] % P);
	ans[0] = res[0];
	ans[1] = res[1];
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++) {
		int k, x[3] = {0, 0, 0}; read(k);
		for (int j = 1; j <= k; j++)
			read(x[j]);
		if (k == 1) res[abs(x[1])][x[1] < 0] ^= true;
		else {
			int b = abs(x[1]), c = abs(x[2]);
			a[b].push_back((info) {c, i, x[1] < 0, x[2] < 0});
			a[c].push_back((info) {b, i, x[2] < 0, x[1] < 0});
		}
	}
	ans[0] = 1, ans[1] = 0;
	for (int i = 1; i <= m; i++)
		if (!vis[i] && a[i].size() <= 1) {
			memset(cur, 0, sizeof(cur));
			cur[0][0][res[i][1]] = 1;
			cur[1][1][res[i][0]] = 1;
			work(i, 0);
		}
	for (int i = 1; i <= m; i++)
		if (!vis[i]) {
			memset(cur, 0, sizeof(cur));
			cur[0][0][res[i][1]] = 1;
			cur[1][1][res[i][0]] = 1;
			work(i, 0);
		}
	cout << ans[1] << endl;
	return 0;
}