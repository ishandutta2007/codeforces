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

const int M = 1e9 + 7, N = 2048;

int f[N], inv[N], fi[N];

int C(int n, int k) {
	if(n < 0) return 0;
	if(n-k < 0) return 0;
	return f[n] * fi[k] % M * fi[n-k] % M;
}

int H(int n, int m) {
	if(n == 0 && m == 0) return 1;
	return C(n + m - 1, m);
}

signed main()
{
	IO_OP;
	inv[1] = 1;
	for(int i=2;i<N;i++)
	    inv[i] = (M - M / i) * inv[M % i] % M;
	f[0] = 1;
	for(int i=1;i<N;i++)
		f[i] = (f[i-1] * i) % M;
	fi[0] = 1;
	for(int i=1;i<N;i++)
		fi[i] = fi[i-1] * inv[i] % M;
	int n, m;
	cin >> n >> m;
	int ans = 0;	
	for(int i=1;i<=n;i++) {
		for(int k=1;k<=m;k++){
			int c = H(i-1, m-k);
			for(int j=0;j<=m;j++) {
				ans += c * H(n-i, m-j) % M;
			}
		}
	}
	cout << ans % M << endl;
}