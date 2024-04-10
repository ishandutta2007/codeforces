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

const int INF = 1e9 + 7, N = 405;

int dp[N][N];

signed main()
{
	IO_OP;

	int n, M;
	cin >> n >> M;

	auto add = [&] (int& a, int b) {
		a += b;
		if(a >= M) a -= M;
	};

	dp[1][1] = 1;
	for(int i = 1; i < n; i++) {
		for(int j = 1; j <= i; j++) {
			{ // begin or end
				int val = dp[i][j] * 2 % M;
				add(dp[i + 1][j + 1], val);
				add(dp[i + 1][j], val);
				add(dp[i + 2][j], val);
			}
			if(j >= 2) {
				int val = (ll) dp[i][j] * (j - 1) % M;
				add(dp[i + 1][j + 1], val);
				add(dp[i + 1][j], val);
				add(dp[i + 1][j], val);
				add(dp[i + 2][j - 1], val);
				add(dp[i + 2][j - 1], val);
				add(dp[i + 3][j - 1], val);
				add(dp[i + 2][j], val);
				add(dp[i + 2][j], val);
			}
		}
	}
	cout << dp[n][1] << '\n';

}