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

const int INF = 1e9 + 7, N = 1003, M = 1e9 + 7;

int a[N];
int f[N], inv[N], fi[N];


signed main()
{
	IO_OP;

	f[0] = 1;
	for(int i = 1; i < N; i++) f[i] = (ll) f[i - 1] * i % M;
	inv[1] = 1;
	for(int i = 2; i < N; i++) inv[i] = M - (ll) M / i * inv[M % i] % M;
	fi[0] = 1;
	for(int i = 1; i < N; i++) fi[i] = (ll) fi[i - 1] * inv[i] % M;

	int n, x, pos;
	cin >> n >> x >> pos;
	int l = 0, r = n;
	int big = 0, small = 0;
	while(l < r) {
		int m = (l + r) / 2;
		if(m == pos) {
			l = m + 1;
			continue;
		}
		if(m > pos) {
			r = m;
			big++;
		} else {
			l = m + 1;
			small++;
		}
	}
	int small_all = x - 1, big_all = n - x, any = n - small - big - 1;
	if(big > big_all || small > small_all) {
		cout << 0 << endl;
		return 0;
	}
	int ans = (ll) f[big_all] * fi[big_all - big] % M * f[small_all] % M * fi[small_all - small] % M * f[any] % M;
	cout << ans << endl;

}