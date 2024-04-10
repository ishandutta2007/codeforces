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

const int INF = 1e9 + 7, N = 2e5 + 7, M = 1e9 + 7;

int a[N], w[N];

struct {
	ll bit[N];
	void add(int i, ll val = 1) {
		for(; i < N; i += i & -i)
	        bit[i] += val;
	}
	ll qry(int i) {
		ll res = 0;
	    for(; i; i -= i & -i)
	        res += bit[i];
	    return res;
	}
} b1;


struct {
	int bit[N];
	void add(int i, int val = 1) {
		for(; i < N; i += i & -i)
	        bit[i] = (bit[i] + val) % M;
	}
	int qry(int i) {
		int res = 0;
	    for(; i; i -= i & -i)
	        res = (res +  bit[i]) % M;
	    return res;
	}
} b2;

signed main()
{
	IO_OP;

	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] -= i;
	}
	for(int i = 1; i <= n; i++) {
		cin >> w[i];
		b1.add(i, w[i]);
		b2.add(i, (ll) a[i] * w[i] % M);
	}

	while(q--) {
		int x, y;
		cin >> x >> y;
		if(x < 0) {
			int i = -x, nw = y;
			b1.add(i, -w[i]);
			b2.add(i, (M - (ll) a[i] * w[i] % M) % M);
			w[i] = nw;
			b1.add(i, w[i]);
			b2.add(i, (ll) a[i] * w[i] % M);
		} else {
			int l = x, r = y;
			if(l == r) {
				cout << 0 << endl;
				continue;
			}
			int cur = 0;
			ll tot = b1.qry(r) - b1.qry(l - 1), sum = 0, tt = b1.qry(l - 1);
			for(int j = 19; j >= 0; j--) {
				if(cur + (1 << j) <= r) {
					int tmp = cur + (1 << j);
					ll summ = b1.bit[tmp] + sum;
					if((summ - tt) * 2 < tot) {
						sum = summ;
						cur = tmp;
					}
				}
			}
			int to = cur + 1;
			assert(to <= r);
			ll ans = (b1.qry(to - 1) - b1.qry(l - 1)) % M * a[to] % M;
			ans = (ans + -(b1.qry(r) - b1.qry(to)) % M * a[to] % M % M + M) % M;
			ans = (ans - b2.qry(to - 1) + b2.qry(l - 1) + M) % M;
			ans = (ans + b2.qry(r) - b2.qry(to) + M) % M;
			cout << ans << endl;
		}
	}

}