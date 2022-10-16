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

void solve() {
	int n, k;
	cin >> n >> k;
	V<vi> wi(k + 1, vi(k + 1)), wj(k + 1, vi(k + 1));
	auto add_edge = [&] (int r1, int c1, int r2, int c2) {
		assert(r1 == r2 || c1 == c2);
		if(r1 == r2) {
			assert(abs(c1 - c2) == 1);
			wi[r1][max(c1, c2)]++;
		} else {
			assert(abs(r1 - r2) == 1);
			wj[max(r1, r2)][c1]++;
		}
	};
	for(int i = 0; i < n; i++) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		r1--, c1--, r2--, c2--;
		add_edge(r1, c1, r2, c2);
		r1 = k - 1 - r1, c1 = k - 1 - c1;
		r2 = k - 1 - r2, c2 = k - 1 - c2;
		add_edge(r1, c1, r2, c2);
	}

	priority_queue<array<int, 3>, V<array<int, 3>>, greater<array<int, 3>>> pq;
	V<vi> d(k + 1, vi(k + 1, INF));
	d[0][0] = 0;
	pq.push({d[0][0], 0, 0});
	while(pq.size()) {
		auto [dist, i, j] = pq.top(); pq.pop();
		if(dist > d[i][j]) continue;
		auto relax = [&] (int ni, int nj, int w) {
			if(d[i][j] + w < d[ni][nj]) {
				d[ni][nj] = d[i][j] + w;
				pq.push({d[ni][nj], ni, nj});
			}
		};
		if(i - 1 >= 0)
			relax(i - 1, j, wi[i - 1][j]);
		if(i + 1 <= k)
			relax(i + 1, j, wi[i][j]);
		if(j - 1 >= 0)
			relax(i, j - 1, wj[i][j - 1]);
		if(j + 1 <= k)
			relax(i, j + 1, wj[i][j]);
	}
	cout << n - d[k / 2][k / 2] << '\n';;
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--)
		solve();	
	
}