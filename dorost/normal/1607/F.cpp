/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 2001;
string s[N];
int t[N][N], cnt;
short n, m;
bool w[N][N];
bool f;
pair <short, short> lst;
vector <pair <short, short>> v;

int dfs(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m)
		return 0;
	if (w[x][y] && t[x][y] == 0) {
		f = true;
		lst = {x, y};
	}
	if (w[x][y]) {
		return t[x][y];
	}
	v.push_back({x, y});
	int a = x, b = y;
	if (s[x][y] == 'D')
		a++;
	else if (s[x][y] == 'U')
		a--;
	else if (s[x][y] == 'R')
		b++;
	else
		b--;
	w[x][y] = true;
	int ans = 1 + dfs(a, b);
	t[x][y] = ans;
	return ans;
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < m; j++)
			w[i][j] = 0, t[i][j] = 0;
	}
	int mx = 0, x, y;
	cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (w[i][j] != 0) {
				continue;
			}
			f = false;
			v.clear();
			cnt++;
			int x2 = dfs(i, j);
			if (mx <= x2) {
				mx = x2;
				x = i + 1, y = j + 1;
			}
			if (f) {
				bool h = false;
				for (int k = 0; k < v.size(); k++) {
					if (v[k].F == lst.F && v[k].S == lst.S)
						h = true;
					if (h)
						t[v[k].F][v[k].S] = t[lst.F][lst.S];
				}
			}
		}
	}
	cout << x << ' ' << y << ' ' << mx << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}