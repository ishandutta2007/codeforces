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

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;

	int a, b, c, d, e, f, ans = 0;
	cin >> a >> b >> c >> d >> e >> f;
	for(int i=0;i<=min(a, d);i++)
		ans = max(ans, i*e + min({b, c, d-i}) * f);
	cout << ans << endl;

}