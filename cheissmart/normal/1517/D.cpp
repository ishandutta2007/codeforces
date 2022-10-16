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

const int INF = 1e9 + 7, N = 505;

int a[N][N], b[N][N], dp[N][N][11];
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

signed main()
{
	IO_OP;

	int n, m, k;
	cin >> n >> m >> k;
	if(k & 1) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++)
				cout << -1 << ' ';
			cout << '\n';
		}
		return 0;
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m - 1; j++)
			cin >> a[i][j];
	for(int i = 0; i < n - 1; i++)
		for(int j = 0; j < m; j++)
			cin >> b[i][j];

	for(int d = 1; d <= k / 2; d++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				dp[i][j][d] = INF;
				for(int dir = 0; dir < 4; dir++) {
					int ii = i + di[dir], jj = j + dj[dir];
					if(ii < 0 || jj < 0 || ii >= n || jj >= m)
						continue;
					int cost = 0;
					if(dir == 0) cost = b[i][j];
					else if(dir == 1) cost = b[i - 1][j];
					else if(dir == 2) cost = a[i][j];
					else cost = a[i][j - 1];
					dp[i][j][d] = min(dp[i][j][d], dp[ii][jj][d - 1] + cost);
				}
			}
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)
			cout << dp[i][j][k / 2] * 2 << ' ';
		cout << '\n';
	}
	

}