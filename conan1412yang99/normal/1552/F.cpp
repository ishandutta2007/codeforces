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

const int INF = 1e9 + 7, N = 4e5 + 7, M = 998244353;

int jump[N], dp[N], dp2[N], psum[N];

void add(int& a, int b) {
	a += b;
	if(a >= M) a -= M;
}

signed main()
{
	IO_OP;

	memset(jump, -1, sizeof jump);

	int n;
	cin >> n;
	vi x(n), y(n), s(n);
	V<pi> xx;
	for(int i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> s[i];
		xx.EB(x[i], i);
	}
	sort(ALL(xx));

	for(int i = 0; i < n; i++) {
		int j = xx[i].S;
		int it = lower_bound(ALL(xx), MP(y[j], 0)) - xx.begin();
		dp2[i] = (x[j] - y[j]) % M;
		if(i) add(dp2[i], psum[i - 1]);
		if(it) add(dp2[i], M - psum[it - 1]);
		psum[i] = dp2[i];
		if(i) add(psum[i], psum[i - 1]);

		if(s[j])
			dp[i] = dp2[i];
		if(i) {
			add(dp[i], (xx[i].F - xx[i - 1].F) % M);
			add(dp[i], dp[i - 1]);
		}
	}

	int ans = dp[n - 1];
	add(ans, 1);
	add(ans, xx[0].F % M);
	cout << ans << '\n';

}