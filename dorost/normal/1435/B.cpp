/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 502;
int a[N][N], b[N][N], c[N][N];
pair <int, int> d[N * N], e[N * N]; 

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> b[i][j], d[b[i][j]] = {i, j};
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> c[i][j], e[c[i][j]] = {i, j};
	for (int i = 1; i <= n * m; i++) {
		a[e[i].S][d[i].S] = i;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << a[i][j] << ' ';
		cout << '\n';
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}