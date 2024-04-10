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

const int INF = 1e9 + 7, N = 1002, C = 1e6 + 7;

bitset<C> dp[N];

pair<vi, vi> split(vi v) {
	int sum = accumulate(ALL(v), 0);
	if(sum & 1) return {{},{}};
	dp[0] = 0;
	dp[0][0] = 1;
	for(int i = 0; i < v.size(); i++)
		dp[i + 1] = dp[i] | (dp[i] << v[i]);
	if(dp[v.size()][sum / 2] == 0) return {{},{}};
	vi x, y;
	int cur = sum / 2;
	for(int i = v.size(); i >= 1; i--) {
		int tt = v[i - 1];
		if(cur - tt >= 0 && dp[i - 1][cur - tt]) {
			x.PB(tt);
			cur -= tt;
		} else {
			y.PB(tt);
		}
	}
	assert(accumulate(ALL(x), 0) == sum / 2);
	if(x.size() < y.size()) swap(x, y);
	return {x, y};
}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int h; cin >> h;
		vi a(h);
		for(int i = 0; i < h; i++) cin >> a[i];
		
		int v; cin >> v;
		vi b(v);
		for(int i = 0; i < v; i++) cin >> b[i];
		
		if(h != v) {
			cout << "NO" << endl;
			continue;
		}
		
		vi l, r, u, d;
		tie(l, r) = split(a);
		tie(u, d) = split(b);
		
		if(l.empty() || u.empty()) {
			cout << "NO" << endl;
			continue;
		}
		
		for(int& i:l) i *= -1;
		for(int& i:d) i *= -1;
		
		int asz = r.size(), bsz = u.size() - r.size(), csz = d.size();
		V<pi> va, vb, vc;
		for(int i:l) r.PB(i);
		for(int i:d) u.PB(i);
		
		for(int i = 0; i < asz; i++) va.EB(r[i], u[i]);
		for(int i = asz; i < asz + bsz; i++) vb.EB(r[i], u[i]);
		for(int i = asz + bsz; i < asz + bsz + csz; i++) vc.EB(r[i], u[i]);
		
		auto cmp = [&](pi a, pi b) {
			return (ll) a.F * b.S - (ll) a.S * b.F > 0;
		};
		
		sort(ALL(va), cmp);
		sort(ALL(vc), cmp);
		
		cout << "Yes" << endl;
		
		int x = 0, y = 0;
		for(pi p:va) {
			x += p.F;
			cout << x << " " << y << endl;
			y += p.S;
			cout << x << " " << y << endl;
		}
		for(pi p:vb) {
			x += p.F;
			cout << x << " " << y << endl;
			y += p.S;
			cout << x << " " << y << endl;
		}
		for(pi p:vc) {
			x += p.F;
			cout << x << " " << y << endl;
			y += p.S;
			cout << x << " " << y << endl;
		}
	}

}