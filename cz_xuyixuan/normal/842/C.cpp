#include<bits/stdc++.h>
using namespace std;
#define MAXN	200005
vector <int> a[MAXN], b[MAXN];
int value[MAXN], c[MAXN], n;
int gcd(int x, int y) {
	if (y == 0) return x;
	else return gcd(y, x % y);
}
void work(int pos, int fa) {
	if (pos == 1) {
		c[pos] = value[pos];
		b[pos].push_back(0);
	} else {
		c[pos] = gcd(value[pos], c[fa]);
		b[pos].push_back(c[fa]);
		for (unsigned i = 0; i < b[fa].size(); i++)
			b[pos].push_back(gcd(b[fa][i], value[pos]));
		b[pos].erase(unique(b[pos].begin(), b[pos].end()), b[pos].end());
	}
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i] != fa) work(a[pos][i], pos);
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> value[i];
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	work(1, 0);
	for (int i = 1; i <= n; i++) {
		sort(b[i].begin(), b[i].end());
		if (i == 1) cout << c[i] << ' ';
		else cout << max(c[i], b[i][b[i].size() - 1]) << ' ';
	}
	cout << endl;
	return 0;
}