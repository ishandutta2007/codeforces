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

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		ll k, x;
		cin >> k >> x;
		ll lb = 1, rb = 2 * k - 1;
		auto go = [&] (ll tt) {
			if(tt <= k)
				return tt * (tt + 1) / 2;
			return k * (k + 1) / 2 + (k - 1 + 2 * k - tt) * (tt - k) / 2;
		};
		while(lb <= rb) {
			ll mb = (lb + rb) / 2;
			if(go(mb) >= x)
				rb = mb - 1;
			else
				lb = mb + 1;
		}
		cout << min(lb, 2 * k - 1) << '\n';;
	}
	
}