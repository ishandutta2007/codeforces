#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#pragma GCC optimize("Ofast", "no-stack-protector")
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define double long double

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 2505;
const double TT = acosl(-1);

struct Point{
	int x, y;
	double arg;
	Point(int _x=0, int _y=0) {
		x = _x, y = _y;
	}
} points[N];

int n;
ll pre[N];

ll C(int n, int k) {
	ll ret = 1;
	for(int i=1;i<=k;i++) {
		ret *= n--;
		ret /= i;
	}
	return ret;
}

ll go(int s, ll ans) {
	V<double> v;
	for(int i=0;i<n;i++)
		if(i != s)
			v.PB(atan2(points[i].y-points[s].y, points[i].x-points[s].x));
	sort(ALL(v));
	for(int i=0;i<n-1;i++) v.PB(v[i]+2*TT);
	for(int i=0, j=0;i<n-1;i++) {
		double want = v[i] + TT;
		while(v[j] < want) j++;
		ans -= pre[(j-i-1+v.size())%v.size()];
	}

	return ans;
}

signed main()
{
	IO_OP;
	cin >> n;
	for(int i=0;i<=n;i++)
		pre[i] = C(i, 3);
	for(int i=0;i<n;i++)
		cin >> points[i].x >> points[i].y;
	ll ans = 0;
	ll all = C(n-1, 4);
	for(int i=0;i<n;i++)
		ans += go(i, all);
	cout << ans << endl;
}