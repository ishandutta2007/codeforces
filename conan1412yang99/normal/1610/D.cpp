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

const int INF = 1e9 + 7, M = 1e9 + 7, N = 2e5 + 7;

void add(int& a, int b) {
	a += b;
	if(a >= M)
		a -= M;
}

int dp[N][31][2];

signed main()
{
	IO_OP;

	int n, odd = 1, even = 1;
	cin >> n;
	vi a;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if(x % 2 == 0) {
			even = even * 2 % M;
			x /= 2;
			int cnt = 0;
			while(x % 2 == 0) {
				cnt++;
				x /= 2;
			}
			a.PB(cnt);
		} else {
			odd = odd * 2 % M;
		}
	}
	int ans = 0;
	add(ans, int(1LL * (odd - 1) * even % M));

	n = int(a.size());
	dp[0][30][0] = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 31; j++) {
			for(int k = 0; k < 2; k++) if(dp[i][j][k]) {
				if(a[i] < j) {
					add(dp[i + 1][a[i]][1], dp[i][j][k]);
				} else if(a[i] == j) {
					add(dp[i + 1][j][k ^ 1], dp[i][j][k]);
				} else if(a[i] > j) {
					add(dp[i + 1][j][k], dp[i][j][k]);
				}
				add(dp[i + 1][j][k], dp[i][j][k]);
			}
		}
	}
	for(int i = 0; i < 30; i++)
		add(ans, dp[n][i][0]);

	cout << ans << '\n';

}