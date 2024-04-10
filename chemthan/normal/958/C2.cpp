#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define sz(a) (int)(a).size()
#define rep(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define frep(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;

const int inf = 1e9 + 7;
const ll linf  = 1ll * inf * inf;
const int N = 20000 + 7;
const int M = 30;
const int multipleTest = 0;
const double pi = acos(-1);

ll dp[2][107][107];
int sum[N];
int n, k, p;

void solve() {
	cin >> n >> k >> p;
	rep(i, 1, n + 1) {
		scanf("%d", sum + i);
		sum[i] = (sum[i] + sum[i - 1]) % p;
	}
	rep(i, 0, 107) rep(j, 0, 107) dp[0][i][j] = dp[1][i][j] = -linf;
	
	dp[0][0][0] = 0;
	int cur = 0;
	
	rep(i, 1, n + 1) {
		int prv = cur;
		cur ^= 1;
		
		rep(i, 0, k + 1) rep(j, 0, p + 1) dp[cur][i][j] = dp[prv][i][j];
		
		for (int last = 0; last < k; ++last) {
			for (int prvSum = 0; prvSum < p; ++prvSum) {
				int now = (sum[i] - prvSum + p) % p;
				dp[cur][last + 1][sum[i]] = max(dp[cur][last + 1][sum[i]], dp[prv][last][prvSum] + now);
			}
		}
	}
	
	cout << dp[cur][k][sum[n]] << '\n';
}

int main() {
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin);
	//    freopen("out.txt", "w", stdout);
#endif
	int Test = 1;
	if (multipleTest) {
		cin >> Test;
	}
	for(int i = 0; i < Test; ++i) {
//		printf("Case #%d: ", i + 1);
		solve();
	}
#ifdef _LOCAL_
	cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
#endif
}