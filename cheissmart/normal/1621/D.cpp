#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
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
const ll oo = 1e18;

void solve() {
	int n;
	cin >> n;
	V<vi> a(2 * n, vi(2 * n));
    ll ans = 0;
    for (int i = 0; i < 2 * n; i++) {
		for (int j = 0; j < 2 * n; j++) {
        	cin >> a[i][j];
        	if (i >= n && j >= n) {
          		ans += a[i][j];
        	}
      	}
    }
    int add = min({a[n][0], a[n][n - 1], a[2 * n - 1][0], a[2 * n - 1][n - 1]});
    add = min({add, a[0][n], a[n - 1][n], a[0][2 * n - 1], a[n - 1][2 * n - 1]});
    cout << ans + add << '\n';
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) solve();

}