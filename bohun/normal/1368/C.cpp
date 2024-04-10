#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()

using namespace std;

int n;

int main() {
	scanf ("%d", &n);
	vector <pair<int, int>> points;
	rep(i, 0, n - 1) {
		points.pb({i, i});
		points.pb({i + 1, i});
		points.pb({i - 1, i});
	}
	points.pb({-1, -1});
	points.pb({0, -1});
	points.pb({n - 1, n});
	points.pb({n, n});
	printf ("%d\n", ss(points));
	for (auto it : points)
		printf ("%d %d\n", it.fi, it.se);
	return 0;
}