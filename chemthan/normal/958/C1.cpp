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
const int N = 100000 + 7;
const int M = 30;
const int multipleTest = 0;
const double pi = acos(-1);

ll dp[2][107][107];
ll sum[N];
int n, k, p;

void solve() {
	cin >> n >> p; k = 2;
	rep(i, 1, n + 1) {
		scanf("%d", sum + i);
		sum[i] = (sum[i] + sum[i - 1]) % p;
	}
	
	ll res = -linf;
	rep(i, 1, n) res = max(res, sum[i] + (sum[n] - sum[i] + p) % p);
	cout << res;
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