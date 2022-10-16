#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(v) int((v).size())
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << _yellow << _bold << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7;

int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, 1, -1};

signed main()
{
	IO_OP;

	int n, m;
	cin >> n >> m;
	V<vi> a(n, vi(m));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];

	auto bad = [&] (int i, int j) {
		if(a[i][j] == 1) return false;
		for(int k = 1; k < 5; k++) {
			int he = i + dx[k], be = j + dy[k];
			if(he < 0 || be < 0 || he >= n || be >= m) continue;
			if(a[he][be] < a[i][j]) return false;
		}		
		return true;
	};

	int bad_cnt = 0, ii = -1, jj = -1;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			if(bad(i, j)) {
				bad_cnt++;
				ii = i, jj = j;
			}
		}

	auto upd = [&] (int i, int j, int x) {
		for(int k = 0; k < 5; k++) {
			int he = i + dx[k], be = j + dy[k];
			if(he < 0 || be < 0 || he >= n || be >= m) continue;
			bad_cnt -= bad(he, be);
		}
		a[i][j] = x;
		for(int k = 0; k < 5; k++) {
			int he = i + dx[k], be = j + dy[k];
			if(he < 0 || be < 0 || he >= n || be >= m) continue;
			bad_cnt += bad(he, be);
		}
	};

	if(bad_cnt == 0) {
		cout << 0 << '\n';
		return 0;
	}
	assert(ii != -1 && bad(ii, jj));
	set<array<int, 4>> s;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			for(int k = 0; k < 5; k++) {
				int he = ii + dx[k], be = jj + dy[k];
				if(he < 0 || be < 0 || he >= n || be >= m) continue;
				if(he == i && be == j) continue;
				int sa = a[i][j], na = a[he][be];
				upd(i, j, na);
				upd(he, be, sa);
				if(bad_cnt == 0) {
					array<int, 4> x = (MP(i, j) < MP(he, be) ? (array<int, 4>){i, j, he, be} : (array<int, 4>){he, be, i, j});
					s.insert(x);
				}
				upd(i, j, sa);
				upd(he, be, na);
			}
		}
	}

	if(SZ(s) == 0) {
		cout << 2 << '\n';
		return 0;
	}
	cout << 1 << " " << SZ(s) << '\n';

}