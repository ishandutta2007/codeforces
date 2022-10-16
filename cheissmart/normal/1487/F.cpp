#include <bits/stdc++.h>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define V vector
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "LINE(" << __LINE__ << ") -> " << #x << " is " << (x) << endl
#define ckmin(a, b) (a) = min(a, b);

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int N = 250, M = 28, INF = 1e9 + 7;

int dp[2][M * 2 + 1][N][N];

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	string s;
	cin >> s;
	reverse(ALL(s));
	s += "0";
	int n = s.size();
	memset(dp[0], 0x3f, sizeof(dp[0]));
	dp[0][M][N - 1][N - 1] = 0;
	for(int i = 0; i < n; i++) {
		memset(dp[1], 0x3f, sizeof(dp[1]));
		for(int carry = 0; carry < 2 * M + 1; carry++) {
			for(int cp = N - 1; cp >= 0; cp--) {
				for(int cn = N - 1; cn >= 0; cn--) {
					if(cp > 0) ckmin(dp[0][carry][cp - 1][cn], dp[0][carry][cp][cn]);
					if(cn > 0) ckmin(dp[0][carry][cp][cn - 1], dp[0][carry][cp][cn]);
					int real_carry = carry - M;
					int val = real_carry + cp - cn;
					int digit = val % 10;
					int new_real_carry = val / 10;
					if(digit < 0) {
						digit += 10;
						new_real_carry--;
					}
					if(digit == s[i] - '0')
						ckmin(dp[1][new_real_carry + M][cp][cn], dp[0][carry][cp][cn] + cp + cn);
				}
			}
		}
		memcpy(dp[0], dp[1], sizeof (dp[1]));
	}
	int ans = INF;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			ckmin(ans, dp[0][M][i][j]);
	cout << ans << '\n';

}