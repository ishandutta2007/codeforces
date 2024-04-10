#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
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
int n, m; bool key[MAXN];
vector <pair <int, int>> a[MAXN];
int depth[MAXN], father[MAXN], len[MAXN];
int x[MAXN], y[MAXN], f[MAXN], res[MAXN], rec[MAXN];
int find(int x) {
	if (f[x] == x) return x;
	else return f[x] = find(f[x]);
}
void work(int pos, int fa) {
	depth[pos] = depth[fa] + 1;
	for (auto x : a[pos])
		if (x.first != fa) {
			work(x.first, pos);
			father[x.first] = pos;
			len[x.first] = x.second;
		}
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		f[i] = i, res[i] = 1;
	for (int i = 1; i <= m; i++)
		read(x[i]), read(y[i]);
	for (int i = m; i >= 1; i--) {
		int tx = find(x[i]);
		int ty = find(y[i]);
		if (tx != ty) {
			a[x[i]].emplace_back(y[i], i);
			a[y[i]].emplace_back(x[i], i);
			f[tx] = ty;
		} else key[i] = true;
	}
	work(1, 0);
	for (int i = m; i >= 1; i--)
		if (!key[i]) rec[i] = res[x[i]] = res[y[i]] = res[x[i]] + res[y[i]];
		else {
			int ans = res[x[i]] + res[y[i]];
			int tx = x[i], ty = y[i];
			vector <int> s, t;
			while (tx != ty) {
				if (depth[tx] >= depth[ty]) {
					s.push_back(len[tx]);
					tx = father[tx];
				} else {
					t.push_back(len[ty]);
					ty = father[ty];
				}
			}
			while (!t.empty()) {
				s.push_back(t.back());
				t.pop_back();
			}
			int Max = 0;
			bool last = true, flg = true;
			for (unsigned j = 0; j < s.size(); j++) {
				chkmax(Max, s[j]);
				if (j != 0) {
					flg &= last >= (s[j - 1] < s[j]);
					last = s[j - 1] < s[j];
				}
			}
			if (flg) ans -= rec[Max];
			rec[i] = res[x[i]] = res[y[i]] = ans;
		}
	for (int i = 1; i <= n; i++)
		printf("%d ", res[i] - 1);
	printf("\n");
	return 0;
}