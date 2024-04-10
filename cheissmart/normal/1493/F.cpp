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

vi getps(int n) {
	vi ps;
	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0) {
			ps.PB(i);
			while(n % i == 0) {
				n /= i;
			}
		}
	}
	if(n != 1) ps.PB(n);
	return ps;
}

int n, m;

int ask(int h, int w, int i1, int j1, int i2, int j2) {
	cout << "? " << h << " " << w << " " << i1 << " " << j1 << " " << i2 << " " << j2 << endl;
	int res;
	cin >> res;
	return res;
}

signed main()
{
	// IO_OP;

	cin >> n >> m;
	int r = n, c = m;
	{ // find r
		vi ps = getps(n);
		auto ok = [&] (int r, int n) {
			assert(n % r == 0);
			int b = n / r;
			int len = 1;
			while(len * 2 <= b) {
				if(!ask(r * len, m, 1, 1, r * len + 1, 1)) return false;
				len *= 2;
			}
			int rem = n - len * r;
			if(rem) {
				if(!ask(rem, m, 1, 1, n - rem + 1, 1)) return false;
			}
			return true;
		};
		for(int p:ps) {
			while(r % p == 0 && ok(r / p, r))
				r /= p;
		}
	}

	{ // find c
		vi ps = getps(m);
		auto ok = [&] (int c, int m) {
			assert(m % c == 0);
			int b = m / c;
			int len = 1;
			while(len * 2 <= b) {
				if(!ask(n, c * len, 1, 1, 1, c * len + 1)) return false;
				len *= 2;
			}
			int rem = m - len * c;
			if(rem) {
				if(!ask(n, rem, 1, 1, 1, m - rem + 1)) return false;
			}
			return true;
		};
		for(int p:ps) {
			while(c % p == 0 && ok(c / p, c))
				c /= p;
		}
	}
	int cnt_n = 0, cnt_m = 0;
	for(int i = r; i <= n; i += r)
		if(n % i == 0)
			cnt_n++;
	for(int i = c; i <= m; i += c)
		if(m % i == 0)
			cnt_m++;
	cout << "! " << cnt_n * cnt_m << endl;
}