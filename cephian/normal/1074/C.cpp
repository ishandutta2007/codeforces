#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int n;
vector<pair<ll,ll>> pts;

int solve(int a, int b) {
	if(a == b) {
		b = (b+1) % n;
	}

	const ll mn_x = min(pts[a].first, pts[b].first);
	const ll mx_x = max(pts[a].first, pts[b].first);
	const ll mn_y = min(pts[a].second, pts[b].second);
	const ll mx_y = max(pts[a].second, pts[b].second);

	ll best = 0;
	for(int i = 0; i < n; ++i) {
		const ll mn_x2 = min(mn_x, pts[i].first);
		const ll mx_x2 = max(mx_x, pts[i].first);
		const ll mn_y2 = min(mn_y, pts[i].second);
		const ll mx_y2 = max(mx_y, pts[i].second);

		best = max(best, 2*(mx_x2 - mn_x2 + mx_y2 - mn_y2));
	}
	return best;
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n;
	pts.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> pts[i].first >> pts[i].second;
	}

	int max_x = 0, max_y = 0, min_x = 0, min_y = 0;
	for(int i = 0; i < (int)pts.size(); ++i) {
		if(pts[i].first > pts[max_x].first) max_x = i;
		if(pts[i].first < pts[min_x].first) min_x = i;
		if(pts[i].second > pts[max_y].second) max_y = i;
		if(pts[i].second < pts[min_y].second) min_y = i;
	}

	ll ans_ge4 = 2*(pts[max_x].first-pts[min_x].first + pts[max_y].second-pts[min_y].second);
	
	//find ans for 3, fixing two of the points
	int best = 0;
	best = max(best, solve(max_x, max_y));
	best = max(best, solve(max_x, min_y));
	best = max(best, solve(max_x, min_x));

	best = max(best, solve(max_y, max_x));
	best = max(best, solve(max_y, min_x));
	best = max(best, solve(max_y, min_y));

	best = max(best, solve(min_x, max_y));
	best = max(best, solve(min_x, min_y));
	best = max(best, solve(min_x, max_x));

	best = max(best, solve(min_y, max_x));
	best = max(best, solve(min_y, min_x));
	best = max(best, solve(min_y, max_y));

	cout << best;
	for(int i = 4; i <= n; ++i) {
		cout << " " << ans_ge4;
	}
	cout << "\n";
}