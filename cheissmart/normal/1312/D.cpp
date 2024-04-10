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

const int INF = 1e9 + 7, M = 998244353, N = 2e5 + 7;

int f[N], inv[N], fi[N], pw[N];

int C(int n, int k) {
	if(n < k) return 0;
	return f[n] * fi[k] % M * fi[n-k] % M;
}

signed main()
{
	IO_OP;
	
	f[0] = 1;
	for(int i=1;i<N;i++)
		f[i] = f[i-1] * i % M;
	inv[1] = 1;
	for(int i=2;i<N;i++)
   		inv[i] = (M - M / i) * inv[M % i] % M;
   	fi[0] = 1;
   	for(int i=1;i<N;i++)
   		fi[i] = fi[i-1] * inv[i] % M;
   	pw[0] = 1;
   	for(int i=1;i<N;i++)
   		pw[i] = pw[i-1] * 2 % M;
	int n, m;
	cin >> n >> m;
	if(n == 2) {
		cout << 0 << endl;
		return 0;
	}
	int ans = 0;
	for(int i=1;i<m;i++) {
		int l = i - 1, r = m - i;
		int all = (C(m-1, n-2) - C(l, n-2) + M) % M;
		all = all * pw[n - 3] % M;
		ans += all;
	}
	cout << ans % M << endl;
}