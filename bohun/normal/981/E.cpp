#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 1e4 + 101;
const int MOD = 1e9 + 7;

void add(int &a, int b) {
	a += b;
	if (a < 0) a += MOD;
	if (a >= MOD) a -= MOD;
}

int n, q;
int l, r, x;
vector <int> Add[N], Del[N];

int dp[N];
bool ans[N];

int main() {
	scanf ("%d%d", &n, &q);
	rep(i, 1, q) {
		scanf ("%d%d%d", &l, &r, &x);
		Add[l].pb(x);
		Del[r + 1].pb(x);
	}
	dp[0] = 1;
	rep(i, 1, n) {
		for (auto it : Add[i]) 
			per(j, it, n)
				add(dp[j], dp[j - it]);
		for (auto it : Del[i])
			rep(j, it, n)
				add(dp[j], -dp[j - it]);
		rep(j, 1, n)
			ans[j] |= dp[j] > 0;
	}
	vector <int> res;
	rep(i, 1, n)
		if (ans[i])
			res.pb(i);
	printf ("%d\n", ss(res));
	for (auto it : res)
		printf ("%d ", it);
	
		
	return 0;
}