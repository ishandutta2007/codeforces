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

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	ll ans = 0;
	V<pi> v;
	int mna = INF, pos = -1, mxS = -1;
	for(int i = 0; i < n; i++) {
		int a, c, s;
		cin >> a >> c;
		s = a + c;
		v.EB(s, a);
		ans += c;
		if(a < mna) {
			mna = a;
			pos = i;
		}
		mxS = max(mxS, s);
	}
	int S = v[pos].F;
	V<pi> tt;
	for(auto p:v) if(p.F > S) tt.EB(p.S, p.F);
	sort(ALL(tt), greater<pi>());
	while(S != mxS) {
		assert(tt.size());
		pi p = tt.back(); tt.pop_back();
		ans += max(0LL, (ll) p.F - S);
		S = max(S, p.S);
	}
	cout << ans << '\n';

}