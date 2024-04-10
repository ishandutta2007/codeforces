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

int qry(int i, int j, int k) {
	cout << "? " << i << " "  << j << " " << k << endl;
	int res; cin >> res;
	return res;
}

void solve() {
	int n;
	cin >> n;
	vi p(n); iota(ALL(p), 1);
	while(SZ(p) > 2) {
		assert(SZ(p) != 3);
		vi tt;
		for(int i = 0; i < 4; i++) {
			tt.PB(p.back());
			p.pop_back();
		}
		V<pi> res;
		res.EB(qry(tt[1], tt[2], tt[3]), 0);
		res.EB(qry(tt[0], tt[2], tt[3]), 1);
		res.EB(qry(tt[0], tt[1], tt[3]), 2);
		res.EB(qry(tt[0], tt[1], tt[2]), 3);
		sort(ALL(res));
		int take = 2;
		if(SZ(p) == 1) take = 1;
		bool dead[4] = {};
		while(take--) {
			dead[res.back().S] = true;
			res.pop_back();
		}
		for(int i = 0; i < 4; i++) if(!dead[i])
			p.PB(tt[i]);
	}
	cout << "! " << p[0] << " " << p[1] << endl;
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--)
		solve();

}