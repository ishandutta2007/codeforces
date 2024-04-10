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

const int INF = 0x3f3f3f3f, N = 6, S = 15625; // S = 5 ^ 6

int a[N], b[N + 1], c[N][N], pw[N];
int dp[N + 1][N][5][S];

void cmin(int& a, int b) {
	a = min(a, b);
}

signed main()
{
	IO_OP;

	pw[0] = 1;
	for(int i = 1; i < N; i++)
		pw[i] = pw[i - 1] * 5;

	int n, m;
	cin >> n >> m;
	int mx_flow = 0, k = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		mx_flow += a[i];
		k += pw[i] * a[i];
	}
	int sum = 0;
	for(int i = 0; i < m; i++) {
		cin >> b[i];
		sum += b[i];
	}
	if(mx_flow > sum) return cout << -1 << '\n', 0;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> c[i][j];

	memset(dp, 0x3f, sizeof dp);
	dp[0][0][b[0]][k] = 0;
	for(int x = 0; x < m; x++) {
		for(int y = 0; y < n; y++) {
			for(int f = 0; f <= 4; f++) {
				for(int mask = 0; mask < S; mask++) {
					if(dp[x][y][f][mask] == INF) continue;
					// don't take
					if(y + 1 < n)
						cmin(dp[x][y + 1][f][mask], dp[x][y][f][mask]);
					else
						cmin(dp[x + 1][0][b[x + 1]][mask], dp[x][y][f][mask]);
					// take
					for(int flow = 0; flow <= min(f, mask / pw[y] % 5); flow++) {
						int new_mask = mask - pw[y] * flow;
						if(y + 1 < n)
							cmin(dp[x][y + 1][f - flow][new_mask], dp[x][y][f][mask] + c[y][x]);
						else
							cmin(dp[x + 1][0][b[x + 1]][new_mask], dp[x][y][f][mask] + c[y][x]);
					}
				}
			}
		}
	}
	cout << dp[m][0][0][0] << '\n';

}