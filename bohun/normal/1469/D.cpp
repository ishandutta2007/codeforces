#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
 
using ll = long long;
using namespace std;	

void solve() {
	int n;
	scanf("%d", &n);
	vector <pair<int, int>> res;
	int x = n;
	while (x > 2) {
		int y = sqrt(x);
		while (y * y < x) y++;
		for (int i = y + 1; i < x; ++i)
			res.push_back({i, x});
		res.push_back({x, y});
		res.push_back({x, y});
		x = y;
	}
	assert(res.size() <= n + 5);
	printf("%d\n", (int)res.size());
	for (auto [x, y] : res)
		printf("%d %d\n", x, y);
}			

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}