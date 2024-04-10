#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)

using namespace std;

void setIO(string name) {
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

const int N = 1e6 + 100;
const int MOD = 1e9 + 7;

int n, k;
string s;
int dp[2 * N];
int last[26];

int main() {
	cin.tie(0);
	cin >> n >> k >> s;
	int X = ss(s) + n;
	s = '#' + s;
	dp[0] = 1;
	rep(i, 1, X) {
		dp[i] = dp[i - 1] * 2 % MOD;
		int c;
		if (i < ss(s)) c = s[i] - 'a';
		else {
			pair <int, int> best = {1023021001, -1};
			rep(i, 0, k - 1) best = min(best, {last[i], i});
			c = best.se;
		}	
		if (last[c] > 0) dp[i] = (dp[i] - dp[last[c] - 1] + MOD) % MOD;
		last[c] = i;
		if (i == X) printf ("%d\n", dp[i]);
	}
	
	
	
	return 0;
}