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

const int INF = 1e9 + 7;

int qpow(int a, int b) {
	if(b == 0) return 1;
	ll t = qpow(a, b / 2);
	if(t == INF) return INF;
	t = t * t;
	if(t >= INF) return INF;
	if(b & 1) return min(t * a, (ll)INF);
	else return t;
}

signed main()
{
	IO_OP;

	int n, l, r;
	cin >> n >> l >> r;
	if(n == 1) {
		cout << r - l + 1 << endl;
	} else if(n == 2)  {
		cout << (ll) (r - l + 1) * (r - l) << endl;
	} else {
		ll ans = 0;
		for(int x = 2; qpow(x, n - 1) <= r; x++) {
			for(int y = 1; y < x; y++) {
				if(__gcd(x, y) != 1) continue;
 				int yy = qpow(y, n - 1), xx = qpow(x, n - 1);
				int lb = (l + yy - 1) / yy, rb = r / xx;
				if(lb <= rb)
					ans += rb - lb + 1;
			}
		}
		cout << ans * 2 << endl;
	}


}