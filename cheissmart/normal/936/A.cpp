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

#define double long double

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

	ll k, d, t;
	cin >> k >> d >> t;
	ll x = (k + d - 1) / d;
	double ans = 0;
	double left = 1;
	ll tot = x * d, fast = k, slow = tot - fast;
	double kill = (double) 1 / t * fast + (double) 0.5 / t * slow;
	ll rounds = floor(left / kill);
	ans = rounds * tot;
	left -= rounds * kill;
	double tt = min(left, (double) 1 / t * fast) * t;
	ans += tt;
	left -= tt / t;
	ans += left * 2 * t;
	cout << fixed << setprecision(10) << ans << '\n';

}