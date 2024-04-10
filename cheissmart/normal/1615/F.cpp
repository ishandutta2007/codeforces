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

const int INF = 1e9 + 7, N = 2002, M = 1e9 + 7;

void add(int& a, int b) {
	a += b;
	if(a >= M)
		a -= M;
}

void solve() {
	int n;
	string s, t;
	cin >> n >> s >> t;
	for(int i = 0; i < n; i += 2) {
		if(s[i] != '?') s[i] ^= 1;
		if(t[i] != '?') t[i] ^= 1;
	} 
	V<pi> dp(2 * n + 1); // {cnt, sum}
	dp[n] = {1, 0};
	for(int i = 0; i < n; i++) {
		V<pi> ndp(2 * n + 1);
		for(int j = 0; j < 2 * n + 1; j++) if(dp[j].F) {
			for(int x = 0; x < 2; x++) if(s[i] != ('1' ^ x)) {
				for(int y = 0; y < 2; y++) if(t[i] != ('1' ^ y)) {
					int nj = j + x - y, cost = 0;
					if(!(j == n && x == 1 && y == 1)) {
						if(x) {
							if(j >= n) add(cost, M - i);
							else add(cost, i);
						}
						if(y) {
							if(j <= n) add(cost, M - i);
							else add(cost, i);
						}
					}
					add(ndp[nj].F, dp[j].F);
					add(ndp[nj].S, dp[j].S);
					add(ndp[nj].S, int(1LL * dp[j].F * cost % M));
				}
			}
		}
		swap(dp, ndp);
	}
	cout << dp[n].S << '\n';
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--)
		solve();

}