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

const int INF = 1e9 + 7, M = 1e9 + 7;

void add(int& a, int b) {
	a += b;
	if(a >= M) a -= M;
}

signed main()
{
	IO_OP;

	int n, p;
	cin >> n >> p;

	vi dp(p + 1);
	dp[0] = 1;
	for(int i = 1; i <= p; i++) {
		add(dp[i], dp[i - 1]);
		if(i - 2 >= 0) add(dp[i], dp[i - 2]);
	}
	for(int i = 1; i <= p; i++)
		add(dp[i], dp[i - 1]);

	vi a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(ALL(a));
	set<int> s;
	auto bad = [&] (int x) {
		while(x) {
			if(s.count(x)) return true;
			if(x & 1) x /= 2;
			else {
				if(x % 4) break;
				x /= 4;
			}
		}
		return false;
	};
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(!bad(a[i])) {
			int len = __lg(a[i]) + 1;
			if(len <= p) {
				int more = p - len;
				debug(more);
				add(ans, dp[more]);
			}
		}
		s.insert(a[i]);
	}
	cout << ans << '\n';

}