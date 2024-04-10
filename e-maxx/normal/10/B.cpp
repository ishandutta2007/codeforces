#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


const int MAXN = 100;
bool u[MAXN][MAXN];

int dist (int x, int y, int n) {
	return abs (x+1 - (n+1)/2) + abs (y+1 - (n+1)/2);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	int n, m;
	cin >> m >> n;
	for (int it=0; it<m; ++it) {
		int a;
		cin >> a;

		pair<int, pair<int,int> > ans;
		ans.first = 1000000000;
		for (int i=0; i<n; ++i) {
			int cnt = 0,
				f = 0;
			for (int j=0; j+a<=n; ++j) {
				if (j == 0)
					for (int k=0; k<a; ++k) {
						cnt += u[i][k];
						f += dist (i, j, n);
					}
				else {
					cnt -= u[i][j-1];
					cnt += u[i][j+a-1];
					f -= dist (i, j-1, n);
					f += dist (i, j+a-1, n);
				}

				if (cnt == 0)
					ans = min (ans, make_pair (f, make_pair (i, j)));
			}
		}

		if (ans.first == 1000000000)
			cout << -1;
		else {
			cout << ans.second.first+1 << ' ' << ans.second.second+1 << ' ' << ans.second.second+a;
			for (int j=0; j<a; ++j)
				u[ans.second.first][ans.second.second+j] = true;
		}
		cout << endl;
	}

}