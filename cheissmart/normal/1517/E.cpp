#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << _yellow << _bold << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7, M = 998244353;

/*
 [c]
 [p]
 [p][c]
 [c](pc)[p](c)
 p[c](pc)[p](c)
*/

void add(int& a, int b) {
	a += b;
	if(a >= M) a -= M;
}

void solve() {
	int n;
	cin >> n;
	vi a(n);
	V<ll> p(n), p0(n), p1(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		p[i] = a[i] + (i ? p[i - 1] : 0LL);
		p0[i] = a[i] * (i & 1 ? -1 : 1) + (i ? p0[i - 1] : 0LL);
		p1[i] = a[i] * (i & 1 ? 1 : -1) + (i ? p1[i - 1] : 0LL);
	}
	ll tot = accumulate(ALL(a), 0LL);
	int ans = 0;
	add(ans, 0); // case 0
	add(ans, 1); // case 1
	{ // case 2
		ll psum = 0;
		for(int i = 0; i < n - 1; i++) {
			psum += a[i];
			if(psum > tot - psum)
				add(ans, 1);
		}
	}

	// bal = psum - csum

	auto qry = [&] (int l, int r) {
		if(l & 1) return p1[r - 1] - p1[l - 1];
		else return p0[r - 1] - p0[l - 1];
	};

	auto go_cnt = [&] (ll bal, int l, int r) {
		assert(l > 0);
		int len = r - l;
		auto ok = [&] (int k) {
			int m = l + k * 2;
			ll bal2 = bal;
			bal2 += p[r - 1] - p[m - 1];
			bal2 += qry(l, m);
			return bal2 > 0;
		};
		int lb = 0, rb = (len - 1) / 2;
		while(lb <= rb) {
			int mb = (lb + rb) / 2;
			if(ok(mb)) lb = mb + 1;
			else rb = mb - 1;
		}
		add(ans, rb + 1);
	};

	{ // case 3
		{
			// don't take the last
			ll bal = 0;
			for(int i = 0; i < n - 1; i++) {
				bal -= a[i];
				go_cnt(bal, i + 1, n);
			}
		}
		{
			// take the last
			ll bal = -a[n - 1];
			for(int i = 0; i < n - 2; i++) {
				bal -= a[i];
				go_cnt(bal, i + 1, n - 1);
			}
		}
	}
	{ // case 4
		{
			// don't take the last
			ll bal = a[0];
			for(int i = 1; i < n - 1; i++) {
				bal -= a[i];
				go_cnt(bal, i + 1, n);
			}
		}
		{
			// take the last
			ll bal = a[0] -a[n - 1];
			for(int i = 1; i < n - 2; i++) {
				bal -= a[i];
				go_cnt(bal, i + 1, n - 1);
			}
		}
	}
	cout << ans << '\n';
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--)
		solve();
}