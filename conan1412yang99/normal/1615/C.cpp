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
	int n;
	string a, b;
	cin >> n >> a >> b;
	if(a == b) {
		cout << 0 << '\n';
		return;
	}
	int ans = INF;
	vi x(n), y(n);
	for(int i = 0; i < n; i++) {
		x[i] = (a[i] - '0') ^ (b[i] - '0');
		y[i] = x[i] ^ 1;
	}
	// even
	{
		int sa = 0, na = 0;
		for(int i = 0; i < n; i++) if(x[i] == 1) {
			if(a[i] == '1')
				sa++;
			else
				na++;
		}
		if(sa == na)
			ans = min(ans, sa + na);
	}
	// odd
	{
		int sa = 0, na = 0;
		for(int i = 0; i < n; i++) if(y[i] == 1) {
			if(a[i] == '1')
				sa++;
			else
				na++;
		}
		if(sa == na + 1)
			ans = min(ans, sa + na);
	}
	if(ans == INF) ans = -1;
	cout << ans << '\n';
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