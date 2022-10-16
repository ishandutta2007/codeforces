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

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	vi x, y;
	x.PB(a), y.PB(b);
	vi tt;
	for(int i = 1; i <= n; i++) if(i != a && i != b) {
		if(i < a) y.PB(i);
		else if(i > b) x.PB(i);
		else tt.PB(i);
	}
	if(x.size() > n / 2 || y.size() > n / 2) {
		cout << -1 << '\n';
		return;
	}
	if(*min_element(ALL(x)) != a || *max_element(ALL(y)) != b) {
		cout << -1 << '\n';
		return;
	}
	for(int i:tt) {
		if(x.size() < n / 2)
			x.PB(i);
		else
			y.PB(i);
	}
	assert(x.size() == n / 2 && y.size() == n / 2);
	for(int i = 0; i < n / 2; i++)
		cout << x[i] << ' ';
	for(int i = 0; i < n / 2; i++)
		cout << y[i] << ' ';
	cout << '\n';
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		solve();
	}

}