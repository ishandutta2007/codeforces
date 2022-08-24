#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

char matrix[1000][1000];
const int INF = 2e18;
int dist[1000][1000];

int n, m;

void calc() {

	queue<pair<int, int> > q;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			bool can = false;
			for (int dx = -1; dx <= 1; ++dx) for (int dy = -1; dy <= 1; ++dy) {
				if (abs(dx) + abs(dy) != 1) continue;
				int X = i+dx, Y = j+dy;
				if (X < 0 || X >= n || Y < 0 || Y >= m) continue;
				if (matrix[X][Y] == matrix[i][j]) can = true;
			}
			if (can) {
				dist[i][j] = 0;
				q.push(make_pair(i, j));
			}
		}
	}

	while (q.size()) {
		auto W = q.front();
		q.pop();

		int i = W.first, j = W.second;
		for (int dx = -1; dx <= 1; ++dx) for (int dy = -1; dy <= 1; ++dy) {
			if (abs(dx) + abs(dy) != 1) continue;
			int X = i+dx, Y = j+dy;
			if (X < 0 || X >= n || Y < 0 || Y >= m) continue;
			if (dist[X][Y] <= dist[i][j] + 1) continue;
			dist[X][Y] = dist[i][j] + 1;
			q.push(make_pair(X, Y));
		}

	}
}

main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> n >> m >> t;

	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		cin >> matrix[i][j];
	}

	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		dist[i][j] = INF;
	}

	calc();

//	cout << dist[0][0] << endl;

	for (int i = 0; i < t; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		c -= dist[a][b];

		if (c <= 0) {
			cout << matrix[a][b] << "\n";
		}
		else {
			if (c%2 == 0) {
				cout << matrix[a][b] << "\n";
			}
			else {
				if (matrix[a][b] == '1') cout << "0\n";
				else cout << "1\n";
			}
		}
	}

}