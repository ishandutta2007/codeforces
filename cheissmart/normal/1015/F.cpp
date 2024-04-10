#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 202, M = 1e9 + 7;

int nxt[N][2], dp[N][N][N][2];
int n;
string s;

int max_prifix(string t) {
	for(int i = t.size(); i >= 1; i--)
		if(s.substr(0, i) == t.substr(t.size()-i)) 
			return i;
	return 0;
}

void add(int &a, int b) {
	a += b;
	if(a >= M) a -= M;
}

signed main()
{
	IO_OP;
	
	cin >> n >> s;
	// precalculate nxt for dp transistion
	for(int i = 0; i <= s.size(); i++) {
		string cur = s.substr(0, i);
		cur.PB('(');
		nxt[i][0] = max_prifix(cur);
		cur.pop_back();
		cur.PB(')');
		nxt[i][1] = max_prifix(cur);
		cur.pop_back();
	}
	dp[0][0][0][0] = 1;
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= i; j++) {
			for(int k = 0; k <= s.size(); k++) {
				for(int l = 0; l < 2; l++) {
					// add (
					add(dp[i+1][j][nxt[k][0]][l | (nxt[k][0] == s.size())], dp[i][j][k][l]);
					// add )
					add(dp[i][j+1][nxt[k][1]][l | (nxt[k][1] == s.size())], dp[i][j][k][l]);
				}

			}
		}
	}
	int ans = 0;
	for(int k = 0; k <= s.size(); k++)
		add(ans, dp[n][n][k][1]);
	cout << ans << endl;
}