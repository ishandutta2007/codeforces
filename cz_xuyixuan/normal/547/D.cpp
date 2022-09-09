#include<bits/stdc++.h>
using namespace std;
const int MAXN = 4e5 + 5;
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
vector <pair <int, int>> a[MAXN];
int n, m, x[MAXN], y[MAXN]; unsigned cur[MAXN];
set <pair <int, int>> path;
bool vis[MAXN];
void work(int pos, int fa) {
	for (unsigned &i = cur[pos]; i < a[pos].size(); i++)
		if (!vis[a[pos][i].second]) {
			vis[a[pos][i].second] = true;
			work(a[pos][i].first, pos);
		}
	if (fa) path.insert(make_pair(fa, pos));
}
int main() {
	n = 2e5, read(m);
	for (int i = 1; i <= m; i++) {
		read(x[i]), read(y[i]), y[i] += n;
		a[x[i]].emplace_back(y[i], i);
		a[y[i]].emplace_back(x[i], i);
	}
	vector <int> odd;
	for (int i = 1; i <= 2 * n; i++)
		if (a[i].size() & 1) odd.push_back(i);
	int tot = m;
	while (!odd.empty()) {
		int x = odd.back(); odd.pop_back();
		int y = odd.back(); odd.pop_back();
		a[x].emplace_back(y, ++tot);
		a[y].emplace_back(x, tot);
	}
	for (int i = 1; i <= 2 * n; i++)
		work(i, 0);
	for (int i = 1; i <= m; i++)
		if (path.count(make_pair(x[i], y[i]))) putchar('b');
		else putchar('r');
	putchar('\n');
	return 0;
}