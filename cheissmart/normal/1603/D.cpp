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

const int INF = 1e9 + 7, K = 17, N = 1e5, B = 320;
const ll oo = 1e18;

ll dp[K + 1][N + 1], p1[N + 1][B], p2[N + 1][B];
ll phi[N + 1];

ll c(int l, int r) {
	if(r / l < B) return (r / (r / l) - l + 1) * phi[r / l] + p2[r][r / l - 1];
	else return p1[r][l];
}

signed main()
{
	IO_OP;

	for(int i = 1; i <= N; i++) {
		phi[i] += i;
		for(int j = i + i; j <= N; j += i)
			phi[j] -= phi[i];
	}
	for(int i = 1; i <= N; i++)
		phi[i] += phi[i - 1];

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= i; j++) {
			int l = j, r = i / (i / j);
			if(i / l < B)
				p2[i][i / l] += phi[i / l] * (r - l + 1);
			j = r;
		}
		for(int j = 1; j < B; j++)
			p2[i][j] += p2[i][j - 1];
		if(i >= B - 1) p1[i][B - 1] = c(B - 1, i);
		for(int j = B - 2; j >= 1; j--)
			p1[i][j] = p1[i][j + 1] + phi[i / j];
	}

	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;

	function<void(int, int, int, int, int)> solve = [&] (int i, int l, int r, int ql, int qr) {
		l = max(l, i);
		if(l > r) return;
		if(r == l) {
			for(int j = ql; j <= qr; j++) {
				if(j <= l)
					dp[i][l] = min(dp[i][l], dp[i - 1][j - 1] + c(j, l));
			}
			return;
		}
		int m = (l + r) / 2, qm = -1;
		for(int j = ql; j <= qr; j++) {
			if(j <= m) {
				if(dp[i - 1][j - 1] + c(j, m) < dp[i][m]) {
					dp[i][m] = dp[i - 1][j - 1] + c(j, m);
					qm = j;
				}
			}
		}
		assert(qm != -1);
		solve(i, l, m - 1, ql, qm);
		solve(i, m + 1, r, qm, qr);
	};

	for(int i = 1; i <= K; i++) {
		solve(i, 1, N, 1, N);
	}

	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		if(k <= K) cout << dp[k][n] << '\n';
		else cout << n << '\n';
	}

}