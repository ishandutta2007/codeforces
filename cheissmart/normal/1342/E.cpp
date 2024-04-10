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
// typedef V<int> vi;

const int INF = 1e9 + 7, M = 998244353, N = 200005;

int f[N], inv[N], fi[N];

int c(int n, int k) {
	return f[n] * fi[k] % M * fi[n - k] % M;
}

int qpow(int a, int b) {
	if(b == 0) return 1;
	int t = qpow(a, b/2);
	t = t * t % M;
	if(b & 1) return t * a % M;
	else return t;
}

int solve(int n, int k) {
	int ans = 0;
	for(int i = 0; i < k; i++) {
		ans += qpow((k-i), n) * c(k, i) % M * ((i & 1) ?  -1 : 1);
	}
	ans %= M;
	ans = ans * c(n, k) % M;
	ans = (ans + M) % M;
	return ans;
}

signed main()
{
	IO_OP;

	f[0] = 1;
	for(int i = 1; i < N; i++) f[i] = f[i-1] * i % M;
	inv[1] = 1;
	for(int i = 2; i < N; i++) inv[i] = M - M / i * inv[M % i] % M;
	fi[0] = 1;
	for(int i = 1; i < N; i++) fi[i] = fi[i-1] * inv[i] % M;
	int n, k;
	cin >> n >> k;
	int group = n - k;
	if(group <= 0 || group > n) {
		cout << 0 << endl;
		return 0;
	}
	int ans = solve(n, group);
	if(k != 0) ans = ans * 2 % M;
	cout << ans << endl;
	
}