#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

int n, dp[101][2][52][2]; // # current position, current direction, # changes done, min or max
int dir[2] = {-1,1};
string s;

int main() {
	cin >> s >> n;
	F0R(a,101) F0R(b,2) F0R(c,52) {
		if (a == s.length() && c <= n && (n-c) % 2 == 0) {
			dp[a][b][c][0] = 0;
			dp[a][b][c][1] = 0;
		} else {
			dp[a][b][c][0] = MOD;
			dp[a][b][c][1] = -MOD;
		}
	}
	F0Rd(a,s.length()) F0R(b,2) F0R(c,min(n,a)+1) {
		if (s[a] == 'F') {
			dp[a][b][c][0] = min(dp[a][b][c][0],dp[a+1][b][c][0]+dir[b]);
			dp[a][b][c][1] = max(dp[a][b][c][1],dp[a+1][b][c][1]+dir[b]);
			dp[a][b][c][0] = min(dp[a][b][c][0],dp[a+1][b^1][c+1][0]);
			dp[a][b][c][1] = max(dp[a][b][c][1],dp[a+1][b^1][c+1][1]);
		} else {
			dp[a][b][c][0] = min(dp[a][b][c][0],dp[a+1][b^1][c][0]);
			dp[a][b][c][1] = max(dp[a][b][c][1],dp[a+1][b^1][c][1]);
			dp[a][b][c][0] = min(dp[a][b][c][0],dp[a+1][b][c+1][0]+dir[b]);
			dp[a][b][c][1] = max(dp[a][b][c][1],dp[a+1][b][c+1][1]+dir[b]);
		}
	}
	cout << max(abs(dp[0][1][0][0]), abs(dp[0][1][0][1]));
}