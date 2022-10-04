/*

Code for problem F by cookiedoth
Generated 01 Mar 2020 at 08.02 PM


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

>_<
\_()_/
^_^

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()

using namespace std;

template<class T> int chkmax(T &a, T b) {
	if (b > a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T> int chkmin(T &a, T b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class iterator> void output(iterator begin, iterator end, ostream& out = cerr) {
	while (begin != end) {
		out << (*begin) << " ";
		begin++;
	}
	out << endl;
}

template<class T> void output(T x, ostream& out = cerr) {
	output(x.begin(), x.end(), out);
}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n, m, k;

vector<vector<int> > dir {
	{1, 0, 0},
	{-1, 0, 0},
	{0, 1, 0},
	{0, -1, 0},
	{0, 0, 1},
	{0, 0, -1}
};

struct keks {
	vector<int> dir_used;
	set<int> colors;
	int must_empty;

	keks() {
		dir_used.resize(6, -2);
		must_empty = 0;
	}

	void change(int pos, int val) {
		// cerr << "change " << pos << " " << val << endl;
		dir_used[pos] = val;
		if (val == -1) {
			must_empty = 1;
		} else {
			colors.insert(val);
			if (colors.size() > 1) {
				must_empty = 1;
			}
		}
	}
};

vector<vector<vector<keks> > > superkek;
queue<vector<int> > q;
vector<vector<vector<int> > > ans;

void bfs() {
	while (!q.empty()) {
		vector<int> v = q.front();
		q.pop();
		int OUT = (v[0] == 3 && v[1] == 3 && v[2] == 3);
		// if (OUT) {
		// 	cerr << "fail " << v[0] << " " << v[1] << " " << v[2] << endl;
		// 	cerr << superkek[3][3][3].dir_used[0] << endl;
		// }
		ans[v[0]][v[1]][v[2]] = -1;
		for (int it = 0; it < 6; ++it) {
			int x = v[0] + dir[it][0];
			int y = v[1] + dir[it][1];
			int z = v[2] + dir[it][2];
			int clr = superkek[v[0]][v[1]][v[2]].dir_used[it];
			if (clr != -2) {
				int ok = (x >= 0 && x < n && y >= 0 && y < m && z >= 0 && z < k);
				if (clr != -1 && !ok) {
					cout << -1 << endl;
					exit(0);
				}
				if (ok) {
					int before = superkek[x][y][z].must_empty;
					int kikos = 0;
					if (superkek[x][y][z].dir_used[it] == -2) {
						kikos = 1;
					}
					superkek[x][y][z].change(it, clr);
					int now = superkek[x][y][z].must_empty;
					if (now == 1 && kikos) {
						q.push({x, y, z});
					}
				}
			}
		}
	}
}

void colour() {
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			for (int z = 0; z < k; ++z) {
				if (ans[x][y][z] != -1) {
					// cerr << "kek " << x << " " << y << " " << z << endl;
					ans[x][y][z] = (superkek[x][y][z].colors.empty() ? 0 : (*superkek[x][y][z].colors.begin()));
				}
			}
		}
	}
}

vector<vector<vector<int> > > req(3), sat(3);

void no() {
	cout << -1 << endl;
	exit(0);
}

void check() {
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			for (int z = 0; z < k; ++z) {
				if (ans[x][y][z] != -1) {
					sat[0][x][y] = 1;
					sat[1][x][z] = 1;
					sat[2][y][z] = 1;
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (req[0][i][j] != sat[0][i][j]) {
				no();
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			if (req[1][i][j] != sat[1][i][j]) {
				no();
			}
		}
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < k; ++j) {
			if (req[2][i][j] != sat[2][i][j]) {
				no();
			}
		}
	}
}

signed main() {
	fast_io();
	cin >> n >> m >> k;
	superkek.resize(n, vector<vector<keks> > (m, vector<keks> (k)));
	req[0].resize(n, vector<int> (m));
	req[1].resize(n, vector<int> (k));
	req[2].resize(m, vector<int> (k));
	sat[0].resize(n, vector<int> (m));
	sat[1].resize(n, vector<int> (k));
	sat[2].resize(m, vector<int> (k));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < k; ++j) {
			int clr;
			cin >> clr;
			clr--;
			superkek[0][i][j].change(0, clr);
			if (clr != -1) {
				req[2][i][j] = 1;
				// cerr << "? " << i << " " << j << endl;
			}
		}
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < k; ++j) {
			int clr;
			cin >> clr;
			clr--;
			superkek[n - 1][i][j].change(1, clr);
			if (clr != -1) {
				req[2][i][j] = 1;
				// cerr << "? " << i << " " << j << endl;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			int clr;
			cin >> clr;
			clr--;
			superkek[i][0][j].change(2, clr);
			if (clr != -1) {
				req[1][i][j] = 1;
				// cerr << i << " ? " << j << endl;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			int clr;
			cin >> clr;
			clr--;
			superkek[i][m - 1][j].change(3, clr);
			if (clr != -1) {
				req[1][i][j] = 1;
				// cerr << i << " ? " << j << endl;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int clr;
			cin >> clr;
			clr--;
			superkek[i][j][0].change(4, clr);
			if (clr != -1) {
				req[0][i][j] = 1;
				// cerr << i << " " << j << " ?" << endl;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int clr;
			cin >> clr;
			clr--;
			superkek[i][j][k - 1].change(5, clr);
			if (clr != -1) {
				req[0][i][j] = 1;
				// cerr << i << " " << j << " ?" << endl;
			}
		}
	}
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			for (int z = 0; z < k; ++z) {
				if (superkek[x][y][z].must_empty) {
					q.push({x, y, z});
				}
			}
		}
	}
	ans.resize(n, vector<vector<int> > (m, vector<int> (k, -2)));
	bfs();
	colour();
	check();
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			for (int z = 0; z < k; ++z) {
				cout << ans[x][y][z] + 1 << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
}