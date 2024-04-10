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
const int N = 500000 + 7;
const int M = 30;
const int multipleTest = 0;
const double pi = acos(-1);

int k, n;
int t[N];

int dp[2][2][5007];

void solve() {
	cin >> k >> n;
	rep(i, 0, n) scanf("%d", t + i);
	sort(t, t + n);
	vii x;
	rep(i, 1, n) x.push_back({t[i] - t[i - 1], i});
	sort(x.begin(), x.end());
	
	set<int> all;
	rep(i, 0, min(sz(x), 2 * k)) {
		all.insert(t[x[i].second]);
		all.insert(t[x[i].second - 1]);
	}
	
	n = 0;
	for (auto x : all) t[n++] = x;
	
	rep(j, 0, 5007) rep(u, 0, 2) rep(v, 0, 2) dp[u][v][j] = inf;
	int cur = 0;
	dp[0][0][0] = 0;
	
	rep(i, 0, n) {
		int prv = cur; cur ^= 1;
		rep(j, 0, k + 1) {
			dp[cur][0][j] = min(dp[prv][0][j], dp[prv][1][j]);
			dp[cur][1][j] = dp[cur][0][j];
			if (i > 0 && j > 0) dp[cur][1][j] = min(dp[cur][1][j], dp[prv][0][j - 1] + t[i] - t[i - 1]);
		}
	}
	
	cout << dp[cur][1][k] << '\n';
	
	
	
	
	
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