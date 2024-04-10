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

const int INF = 1e9 + 7, N = 2e5 + 7;

int a[2][N], b[2][N];

signed main()
{
	IO_OP;

	int n, bal = 0;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[0][i], bal += a[0][i];
	for(int i = 0; i < n; i++) cin >> a[1][i], bal += a[1][i];
	for(int i = 0; i < n; i++) cin >> b[0][i], bal -= b[0][i];
	for(int i = 0; i < n; i++) cin >> b[1][i], bal -= b[1][i];

	if(bal) {
		cout << -1 << '\n';
		return 0;
	}

	int he = 0, be = 0;
	ll ans = 0;

	for(int i = 0; i < n; i++) {
		he += a[0][i], be += a[1][i];
		he -= b[0][i], be -= b[1][i];
		int take = max({min(-be, he), min(be, -he), 0});
		ans += take;
		if(he > 0) he -= take;
		else he += take;
		if(be > 0) be -= take;
		else be += take;
		ans += abs(he) + abs(be);
	}
	cout << ans << '\n';

}