#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 100 + 5;

pii p[3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<pair<pii, pii>> ans;
	for (int i = 0; i < 3; i++)
		cin >> p[i].F >> p[i].S;
	sort(p, p + 3);
	if (min(p[0].S, p[2].S) <= p[1].S && max(p[0].S, p[2].S) >= p[1].S) {
		ans.push_back({p[0], {p[0].F, p[1].S}});
		ans.push_back({{p[0].F, p[1].S}, {p[2].F, p[1].S}});
		ans.push_back({{p[2].F, p[1].S}, p[2]});
	} else {
		if (abs(p[0].S - p[1].S) <= abs(p[2].S - p[1].S)) {
			ans.push_back({p[0], {p[2].F, p[0].S}});
			ans.push_back({{p[2].F, p[0].S}, p[2]});
			ans.push_back({p[1], {p[1].F, p[0].S}});
		} else {
			ans.push_back({p[0], {p[0].F, p[2].S}});
			ans.push_back({{p[0].F, p[2].S}, p[2]});
			ans.push_back({p[1], {p[1].F, p[2].S}});
		}
	}

	cout << ans.size() << "\n";
	for (auto x: ans)
		cout << x.F.F << " " << x.F.S << " " << x.S.F << " " << x.S.S << "\n";
	return 0;
}