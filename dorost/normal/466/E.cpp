/* In the name of God */

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
const int N = 101234, LG = 17;
vector <pair <int, int>> g[N];
int n, h[N], w[N];
bool f[N];
pair <int, int> sp[N][LG]; // x ^ (1 << y), max (x -> x ^ (1 << y))

inline void sparse() {
	for (int j = 1; j < LG; j++) {
		for (int i = 1; i <= n; i++) {
			sp[i][j] = make_pair(sp[sp[i][j - 1].F][j - 1].F, max(sp[i][j - 1].S, sp[sp[i][j - 1].F][j - 1].S));
		}
	}
}

void dfs(int x) {
	for (pair <int, int> p : g[x]) {
		sp[p.F][0] = make_pair(x, p.S);
		h[p.F] = h[x] + 1;
		dfs(p.F);
	}
}

int main() {
	int m;
	cin >> n >> m;
	vector <pair <pair <int, int>, int>> q;
	int cnt = 1;
	for (int i = 0; i < m; i++) {
		int t, x, y;
		cin >> t >> x;
		if (t == 1) {
			f[x] = true;
			cin >> y;
			g[y].push_back(make_pair(x, cnt));
		} 
		if (t == 2) {
			w[cnt] = x;
			cnt++;
		}
		if (t == 3) {
			cin >> y;
			q.push_back(make_pair(make_pair(x, y), y));
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!f[i]) {
			h[i] = 0;
			sp[i][0] = {i, 0};
			dfs(i);
		}
	}
	sparse();
	for (pair <pair <int, int>, int> p : q) {
		int x = p.F.F, y = w[p.F.S];
		if (x == y) {
			cout << "YES\n";
			continue;
		}
		if (h[y] <= h[x]) {
			cout << "NO\n";
			continue;
		}
		int l = h[y] - h[x];
		int mx = 0;
		for (int i = LG - 1; i >= 0; i--) {
			if (l & (1 << i)) {
				mx = max(mx, sp[y][i].S);
				y = sp[y][i].F;
			}
		}
		if (x != y) {
			cout << "NO\n";
			continue;
		}
		if (mx <= p.S) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}