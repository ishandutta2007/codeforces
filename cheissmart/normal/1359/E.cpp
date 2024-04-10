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

const int INF = 1e9 + 7, M = 998244353, N = 5e5 + 7;

int f[N], inv[N], fi[N];

int C(int n, int k) {
	return f[n] * fi[k] % M * fi[n - k] % M;
}

signed main()
{
	IO_OP;
	
	f[0] = 1;
	for(int i = 1; i < N; i++) f[i] = f[i - 1] * i % M;
	inv[1] = 1;
	for(int i = 2; i < N; i++) inv[i] = M - M / i * inv[M % i] % M;
	fi[0] = 1;
	for(int i = 1; i < N; i++) fi[i] = fi[i - 1] * inv[i] % M;

	int n, k;
	cin >> n >> k;
	if(k == 1) {
		return cout << n << endl, 0;
	}
	if(n < k) {
		return cout << 0 << endl, 0;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int choose = n / i;
		if(choose >= k) {
			ans += C(choose - 1, k - 1);
		}
	}
	cout << ans % M << endl;
}