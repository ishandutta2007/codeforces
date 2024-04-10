#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

char matrix[1000][1000];
bool used[1000][1000];

int n, m;

void dfs(int x, int y) {

	used[x][y] = true;

	for (int dx = -1; dx <= 1; ++dx) for (int dy = -1; dy <= 1; ++dy) {
		if (abs(dx) + abs(dy) != 1) continue;
		int a = x+dx, b = y+dy;
		if (a < 0 || a >= n || b <0 || b >= m) continue;
		if (matrix[a][b] == '.') continue;
		if (used[a][b]) continue;
		dfs(a, b);
	}
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//int n, m;
	cin >> n >> m;
	int cnt = 0;

	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		cin >> matrix[i][j];
		if (matrix[i][j] == '#') cnt++;
	}

	if (cnt==0) {
		cout << 0;
		exit(0);
	}

	int e = 0, f = 0;

	for (int i = 0; i < n; ++i) {
		int now = 0;
		for (int j = 0; j < m; ++j) {
			if (matrix[i][j] == '.') {
				if (now >= 1) now = 2;
			}
			else {
				if (now == 0) now = 1;
				else if (now == 2) {
					cout << -1;
					exit(0);
				}
			}
		}
		if (now==0) {
			e++;
		}
	}

	for (int i = 0; i < m; ++i) {
		int now = 0;
		for (int j = 0; j < n; ++j) {
			if (matrix[j][i] == '.') {
				if (now >= 1) now = 2;
			}
			else {
				if (now == 0) now = 1;
				else if (now == 2) {
					cout << -1;
					exit(0);
				}
			}

		}
		if (now==0) {
			f++;
		}
	}

	if (e+f > 0 && (e == 0 ||f == 0)) {
		cout << -1;
		exit(0);
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		if (used[i][j]) continue;
		if (matrix[i][j] == '.') continue;
		dfs(i, j);
		ans++;
	}
	cout << ans;



}