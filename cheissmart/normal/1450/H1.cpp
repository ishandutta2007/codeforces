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

const int INF = 1e9 + 7, N = 2e5 + 7, M = 998244353;

int f[N], inv[N], fi[N];

int C(int n, int k) {
	assert(n < N);
	assert(k <= n);
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

	int n, m;
	string s;
	cin >> n >> m >> s;
	int tt = 0, A = 0, B = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == 'b') tt += ((i & 1) ? -1 : 1);
		else if(s[i] == '?') ((i & 1) ? B : A)++;
	}
	int ans = 0;
	for(int i = 0; i <= A + B; i++) {
		int a_b = i - B;
		if(abs(tt + a_b) % 2 == 0) {
			ans = (ans + (ll) abs(tt + a_b) / 2 * C(A + B, i) % M) % M;
		}
	}
	for(int i = 0; i < A + B - 1; i++) ans = (ll) ans * inv[2] % M;
	cout << ans << endl;

}