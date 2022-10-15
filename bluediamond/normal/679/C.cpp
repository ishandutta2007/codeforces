#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <cassert> 
#include <algorithm> 
#include <set> 
#include <iomanip> 
#include <queue> 
#include <deque> 
#include <unordered_set> 
#include <unordered_map> 
#include <functional> 
#include <cmath> 
#include <map> 
#include <random> 
#include <chrono> 
#include <cstdio> 
#include <bitset> 
#include <numeric> 

bool home = true;
using namespace std;


struct T {
	int n;
	vector<int> t;
	vector<int> sz;
	int mx;

	T(int n) : n(n), t(n), sz(n, 1), mx(1) {
		iota(t.begin(), t.end(), 0);
	}

	int root(int a) {
		assert(0 <= a && a < n);
		if (t[a] == a) return a;
		return t[a] = root(t[a]);
	}

	void unite(int a, int b) {
		a = root(a);
		b = root(b);

		if (a == b) return;
		t[a] = b;
		sz[b] += sz[a];
		mx = max(mx, sz[b]);
	}

	int get() {
		return mx;
	}
};

const int N = 500 + 7;
int n, k, a[N][N], code[N][N], y, sol, comp[N][N], sz[N * N], last_seen[N * N];

void print() {
	for (int i = 1; i <= n * n; i++) if (sz[i] >= 0) cout << sz[i] << " ";
	cout << "\n";
}

signed main() {
#ifdef ONLINE_JUDGE
	home = 0;
#endif

	if (home) {
		FILE* stream;
		freopen_s(&stream, "iron_man.txt", "r", stdin);
	}
	else {
		ios::sync_with_stdio(0); cin.tie(0);
	}

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= n; j++) a[i][j] = (s[j - 1] == '.'), code[i][j] = y++;
	}


	{
		T init(n * n);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (a[i][j] && a[i + 1][j]) init.unite(code[i][j], code[i + 1][j]);
				if (a[i][j] && a[i][j + 1]) init.unite(code[i][j], code[i][j + 1]);
			}
		}
		sol = max(sol, init.get());
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (!a[i][j]) continue;
				comp[i][j] = init.root(code[i][j]);
				sz[comp[i][j]] = init.sz[comp[i][j]];
			}
		}
		int cur, tt = 0;

		function<void(int, int)> ins = [&](int i, int j) {
			if (!a[i][j]) return;
			if (last_seen[comp[i][j]] == tt) return;
			last_seen[comp[i][j]] = tt;
			cur += sz[comp[i][j]];
		};

		for (int i = 1; i + k - 1 <= n; i++) {
			for (int j = 1; j + k - 1 <= n; j++) {
				tt++;
				if (j == 1) {
					for (int r = i; r < i + k; r++) {
						for (int c = j; c < j + k; c++) {
							sz[comp[r][c]]--;
						}
					}
				}
				else {
					for (int p = i; p < i + k; p++) {
						sz[comp[p][j + k - 1]]--;
						sz[comp[p][j - 1]]++;
					}
				}
				cur = k * k;
				for (int p = 0; p < k; p++) {
					ins(i - 1, j + p);
					ins(i + k, j + p);
					ins(i + p, j - 1);
					ins(i + p, j + k);
				}
				sol = max(sol, cur);
				if (j + k - 1 == n) {
					for (int r = i; r < i + k; r++) {
						for (int c = j; c < j + k; c++) {
							sz[comp[r][c]]++;
						}
					}
				}
			}
		}
	}
	cout << sol << "\n";
}