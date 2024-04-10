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
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 2005, C = 200005, M = 1e9 + 7;

int f[C], inv[C], fi[C];

int ways(int dx, int dy) {
	return f[dx + dy] * fi[dx] % M * fi[dy] % M;
}

pi a[N];
int dp[N];

signed main()
{
	IO_OP;
	
	f[0] = 1;
	for(int i = 1; i < C; i++) f[i] = f[i-1] * i % M;
	inv[1] = 1;
	for(int i = 2; i < C; i++) inv[i] = M - M / i * inv[M % i] % M;
	fi[0] = 1;
	for(int i = 1; i < C; i++) fi[i] = fi[i-1] * inv[i] % M;

	int h, w, n;
	cin >> h >> w >> n;
	for(int i = 0; i < n; i++) cin >> a[i].F >> a[i].S;
	a[n++] = {h, w}, a[n++] = {1, 1};
	sort(a, a+n);

	for(int i = 1; i < n; i++) {
		dp[i] = ways(a[i].F - 1, a[i].S - 1);
		for(int j = 0; j < i; j++) if(a[j].F <= a[i].F && a[j].S <= a[i].S)
			dp[i] = (dp[i] - dp[j] * ways(a[i].F - a[j].F, a[i].S - a[j].S) % M) % M;
	}
	int ans = (dp[n-1] + M) % M;
	cout << ans << endl;
}