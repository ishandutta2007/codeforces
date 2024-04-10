#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, M = 998244353, N = 1e6 + 7;

int f[N], inv[N], fi[N];

int C(int n, int k) {
	return (ll) f[n] * fi[k] % M * fi[n - k] % M;
}

signed main()
{
	IO_OP;


	f[0] = 1;
	for(int i = 1; i < N; i++) f[i] = (ll) f[i - 1] * i % M;
	inv[1] = 1;
	for(int i = 2; i < N; i++) inv[i] = M - (ll) M / i * inv[M % i] % M;
	fi[0] = 1;
	for(int i = 1; i < N; i++) fi[i] = (ll) fi[i - 1] * inv[i] % M;

	int n;
	cin >> n;
	vi a(n * 2);
	for(int i = 0; i < 2 * n; i++) cin >> a[i];
	sort(ALL(a));
	int x = 0;
	for(int i = 0; i < n; i++) x = (x - a[i] % M + M) % M;
	for(int i = n; i < n * 2; i++) x = (x + a[i] % M) % M;
	cout << (ll) x * C(n * 2, n) % M << endl;

}