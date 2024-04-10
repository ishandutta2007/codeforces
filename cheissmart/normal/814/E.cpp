#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 51, M = 1e9 + 7;

void add(int& a, int b) {
	 a += b;
	 if(a >= M) a -= M;
}

int dp[2][N][N][N][N], d[N];

int C2(int a) {
	return (ll) a * (a - 1) / 2 % M;
}

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> d[i];
	int start = 2;
	if(d[1] == 2) {
		dp[0][0][1][0][0] = 1;
	} else {
		start = 3;
		if(d[2] == 2)
			dp[0][0][1][1][0] = 1;
		else
			dp[0][0][1][0][1] = 1;
	}
	for(int i = start; i <= n; i++) {
		for(int p1 = 0; p1 <= n; p1++) for(int p2 = 0; p1 + p2 <= n; p2++) {
			for(int c1 = 0; p1 + p2 + c1 <= n; c1++) for(int c2 = 0; p1 + p2 + c1 + c2 <= n; c2++) {
				if(p1 + p2 == 0) {
					add(dp[0][c1][c2][0][0], dp[0][p1][p2][c1][c2]);
				} else {
					if(dp[0][p1][p2][c1][c2] == 0) continue;
					auto upd = [&] (int new_p1, int new_p2, int ways) {
						if(d[i] == 2) { // 1 rem
							// connect same level
							if(c1) add(dp[1][new_p1][new_p2][c1 - 1][c2], (ll) ways * c1 % M);
							if(c2) add(dp[1][new_p1][new_p2][c1 + 1][c2 - 1], (ll) ways * c2 % M);
							// otherwise
							add(dp[1][new_p1][new_p2][c1 + 1][c2], ways);
						} else { // 2 rem
							// connect 2 same level
							if(c1 >= 2) add(dp[1][new_p1][new_p2][c1 - 2][c2], (ll) ways * C2(c1) % M);
							if(c2 >= 2) add(dp[1][new_p1][new_p2][c1 + 2][c2 - 2], (ll) ways * C2(c2) % M);
							if(c1 && c2) add(dp[1][new_p1][new_p2][c1][c2 - 1], (ll) ways * c1 % M * c2 % M);
							// connect 1 same level
							if(c1) add(dp[1][new_p1][new_p2][c1][c2], (ll) ways * c1 % M);
							if(c2) add(dp[1][new_p1][new_p2][c1 + 2][c2 - 1], (ll) ways * c2 % M);
							// otherwise
							add(dp[1][new_p1][new_p2][c1][c2 + 1], ways);
						}
					};
					if(p1) upd(p1 - 1, p2, (ll) dp[0][p1][p2][c1][c2] * p1 % M);
					if(p2) upd(p1 + 1, p2 - 1, (ll) dp[0][p1][p2][c1][c2] * p2 % M);
				}
			}
		}
		memcpy(dp[0], dp[1], sizeof dp[1]);
		memset(dp[1], 0, sizeof dp[1]);
	}
	cout << dp[0][0][0][0][0] << '\n';
}