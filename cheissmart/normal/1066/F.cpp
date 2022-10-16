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
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

struct Point {
	int x, y;
	bool operator < (const Point t) const {
		return x < t.x || (x == t.x && y > t.y);
	}
	Point(int _x=0, int _y=0) {
		x = _x, y = _y;
	}
};
int dist(Point A, Point B) {
	return abs(A.x - B.x) + abs(A.y - B.y);
}

map<int, V<Point>> m;

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
 		Point p;
 		cin >> p.x >> p.y;
 		m[max(p.x, p.y)].PB(p);
	}	
	Point c1(0, 0), c2(0, 0);
	int dp1 = 0, dp2 = 0;
	for(auto tt:m) {
		V<Point> v = tt.S;
		sort(ALL(v));
		int len = 0;
		for(int i = 0; i < (int)v.size()-1; i++)
			len += dist(v[i], v[i+1]);
		int new_dp1 = len + min(dp1 + dist(c2, v[0]), dp2 + dist(c1, v[0]));
		int new_dp2 = len + min(dp1 + dist(c2, v.back()), dp2 + dist(c1, v.back()));
		c1 = v[0], c2 = v.back();
		dp1 = new_dp1, dp2 = new_dp2;
	}
	cout << min(dp1, dp2) << endl;
}