#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
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
bool vis[MAXN];
unsigned cur[MAXN];
vector <int> ans, points;
vector <pair <int, int>> a[MAXN];
void work(int pos) {
	for (unsigned &i = cur[pos]; i < a[pos].size(); i++)
		if (!vis[a[pos][i].second]) {
			vis[a[pos][i].second] = true;
			work(a[pos][i].first);
		}
	ans.push_back(pos);
}
int main() {
	int n, m; read(n), read(m);
	for (int i = 1; i <= m; i++) {
		int x, y; read(x), read(y);
		a[x].emplace_back(y, i);
		a[y].emplace_back(x, i);
	}
	vector <int> points;
	for (int i = 1; i <= n; i++)
		if (a[i].size() & 1) points.push_back(i);
	while (!points.empty()) {
		int x = points.back(); points.pop_back();
		int y = points.back(); points.pop_back(), m++;
		a[x].emplace_back(y, m);
		a[y].emplace_back(x, m);
	}
	if (m & 1) {
		m++;
		a[1].emplace_back(1, m);
		a[1].emplace_back(1, m);
	}
	printf("%d\n", m); work(1);
	for (int i = 1; i <= m; i++)
		if (i & 1) printf("%d %d\n", ans[i - 1], ans[i]);
		else printf("%d %d\n", ans[i], ans[i - 1]);
	return 0;
}