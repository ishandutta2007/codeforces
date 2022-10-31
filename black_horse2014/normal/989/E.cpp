#include <bits/stdc++.h>
#include <map>
using namespace std;

using db = double;
const db pi = acos(-1);
const db eps = 1e-10;

const int N = 220;
const int M = 100;

int x[N], y[N];

struct mdb {
	db x;
	mdb(db x = 0) : x(x) {}
	bool operator < (const mdb &m) const {
		return x < m.x - eps;
	}
};

db mat[M][N][N];
vector<vector<int>> Lines;

int main() {
	int n; cin >> n;
	cout.setf(ios::fixed); cout << setprecision(10);
	cerr.setf(ios::fixed); cerr << setprecision(10);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		map<mdb, vector<int>> ma;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			db ang = atan2(y[j] - y[i], x[j] - x[i]);
			if (ang < eps) ang += pi;
			ma[mdb(ang)].push_back(j);
		}
		int k = ma.size();
		for (auto t : ma) {
			int kk = t.second.size() + 1;
			for (int x : t.second) mat[1][i][x] += 1. / k / kk;
			mat[1][i][i] += 1. / k / kk;
			if (t.second[0] > i) {
				vector<int> line;
				line.push_back(i);
				line.insert(line.end(), t.second.begin(), t.second.end());
				Lines.push_back(line);
			}
		}
	}
	for (int i = 0; i < n; i++) mat[0][i][i] = 1;
	for (int T = 2; T < M; T++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					mat[T][i][j] += mat[T-1][i][k] * mat[1][k][j];
				}
			}
		}
	}
	int q; cin >> q;
	while (q--) {
		int y, m; cin >> y >> m; --y;
		db ans = 0;
		for (auto &t : Lines) {
			db cur = 0;
			int k = t.size();
			for (int x : t) {
				cur += mat[min(M-1, m-1)][x][y];
			}
			ans = max(ans, cur / k);
		} 
		cout << ans << endl;
	}
}