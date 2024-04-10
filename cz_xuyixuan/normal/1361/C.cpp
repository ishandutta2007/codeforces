#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
const int MAXM = 1 << 20;
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
int n, a[MAXN], b[MAXN];
int d[MAXM], f[MAXM];
int find(int x) {
	if (f[x] == x) return x;
	else return f[x] = find(f[x]);
}
bool vis[MAXN * 2];
int cnt, ans[MAXN]; unsigned cur[MAXM];
vector <pair <int, int>> e[MAXM];
bool check(int res) {
	int u = (1 << res) - 1;
	for (int i = 0; i <= u; i++)
		d[i] = 0, f[i] = i;
	for (int i = 1; i <= n; i++) {
		int x = a[i] & u;
		int y = b[i] & u;
		d[x]++, d[y]++;
		f[find(x)] = find(y);
	}
	int cnt = 0, odd = 0;
	for (int i = 0; i <= u; i++) {
		cnt += f[i] == i && d[i] != 0;
		odd += d[i] & 1;
	}
	return cnt == 1 && odd == 0;
}
void work(int pos, int last) {
	if (last != 0) {
		if (last <= n) vis[last] = vis[last + n] = true;
		else vis[last] = vis[last - n] = true;
	}
	for (unsigned &i = cur[pos]; i < e[pos].size(); i++)
		if (!vis[e[pos][i].second]) work(e[pos][i].first, e[pos][i].second);
	if (last != 0) ans[++cnt] = last;
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]), read(b[i]);
	int l = 0, r = 20;
	while (l < r) {
		int mid = (l + r + 1) / 2;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << endl;
	int u = (1 << l) - 1;
	for (int i = 1; i <= n; i++) {
		int x = a[i] & u;
		int y = b[i] & u;
		e[x].emplace_back(y, i);
		e[y].emplace_back(x, i + n);
	}
	for (int i = 0; i <= u; i++)
		work(i, 0);
	for (int i = 1; i <= n; i++)
		if (ans[i] <= n) printf("%d %d ", ans[i] * 2, ans[i] * 2 - 1);
		else printf("%d %d ", (ans[i] - n) * 2 - 1, (ans[i] - n) * 2);
	printf("\n");
	return 0;
}