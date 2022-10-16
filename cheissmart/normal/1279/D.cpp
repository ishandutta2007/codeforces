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

const int INF = 1e9 + 7, M = 998244353, N = 1000006;

vi a[N];
int p[N], inv[N];

signed main()
{
	IO_OP;
	inv[1] = 1;
	for(int i=2;i<N;i++)
	    inv[i] = (M - M / i) * inv[M % i] % M;

	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		a[i].resize(t);
		for(int j=0;j<a[i].size();j++) {
			cin >> a[i][j];
			int tt = a[i][j];
			p[tt] += inv[n] * inv[a[i].size()] % M;
			p[tt] %= M;
		}
	}
	int ans = 0;
	for(int i=0;i<n;i++) {
		for(int j:a[i]) {
			ans += p[j] * inv[n] % M;
			ans %= M;
		}
	}
	cout << ans << endl;
	
}