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

	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	ll sum = 0;
	vi a(n1), b(n2), c(n3);
	vi v;
	for(int i = 0; i < n1; i++) {
		cin >> a[i];
		sum += a[i];
	}
	for(int i = 0; i < n2; i++) {
		cin >> b[i];
		sum += b[i];
	}
	for(int i = 0; i < n3; i++) {
		cin >> c[i];
		sum += c[i];
	}
	ll ans = -1e18;
	if(n1 == 1) ans = max(ans, sum - 2 * a[0]);
	if(n2 == 1) ans = max(ans, sum - 2 * b[0]);
	if(n3 == 1) ans = max(ans, sum - 2 * c[0]);
	sort(ALL(a));
	sort(ALL(b));
	sort(ALL(c));
	v.PB(a[0]);
	v.PB(b[0]);
	v.PB(c[0]);
	sort(ALL(v));
	ans = max(ans, sum - (v[0] + v[1]) * 2);
	ans = max(ans, sum - accumulate(ALL(a), 0LL) * 2);
	ans = max(ans, sum - accumulate(ALL(b), 0LL) * 2);
	ans = max(ans, sum - accumulate(ALL(c), 0LL) * 2);
	cout << ans << endl;
}