#include<bits/stdc++.h>
using namespace std;
#define MAXN	200005
vector <int> a[MAXN], b[MAXN];
bool visited[MAXN];
int tot, n, m, depth[MAXN];
bool work(int pos, int fa) {
	depth[pos] = depth[fa] + 1;
	for (unsigned i = 0; i < a[pos].size(); i++) {
		if (a[pos][i] == fa) continue;
		if (depth[a[pos][i]] == 0) {
			if (work(a[pos][i], pos))
				b[pos].push_back(a[pos][i]);
		} else {
			if (depth[a[pos][i]] < depth[pos])
				b[pos].push_back(a[pos][i]);
		}
	}
	for (unsigned i = 0, j = 1; j < b[pos].size(); i += 2, j += 2)
		cout << b[pos][i] << ' ' << pos << ' ' << b[pos][j] << endl;
	if (fa == 0) return false;
	if (b[pos].size() % 2 == 0) return true;
	else {
		cout << fa << ' ' << pos << ' ' << b[pos][b[pos].size() - 1] << endl;
		return false;
	}
}
void visit(int pos) {
	visited[pos] = true;
	tot += a[pos].size();
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (!visited[a[pos][i]]) visit(a[pos][i]);
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		tot = 0;
		visit(i);
		ans += tot / 4;
	}
	cout << ans << endl;
	for (int i = 1; i <= n; i++)
		if (depth[i] == 0) work(i, 0);
	return 0;
}