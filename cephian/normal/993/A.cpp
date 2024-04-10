#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> pii;

pii transform(pii p) {
	return pii(p.first + p.second, p.first - p.second);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	vector<pii> s1, s2;

	pii x1(0, 0), x2(0, 0);

	for(int i = 0; i < 4; ++i) {
		int a, b;
		cin >> a >> b;
		s1.emplace_back(a, b);
		x1.first += a / 4.0;
		x1.second += b / 4.0;
	}

	for(int i = 0; i < 4; ++i) {
		int a, b;
		cin >> a >> b;
		s2.emplace_back(a, b);
		x2.first += a / 4.0;
		x2.second += b / 4.0;
	}
	s1.push_back(x1);
	s2.push_back(x2);

	sort(s1.begin(), s1.end());

	bool inter = false;
	for(auto x : s2) {
		if(s1[0].first <= x.first && x.first <= s1[4].first &&
				s1[0].second <= x.second && x.second <= s1[4].second)
			inter = true;
	}

	for(int i = 0; i < 5; ++i) {
		s1[i] = transform(s1[i]);
		s2[i] = transform(s2[i]);
	}
	swap(s1, s2);
	sort(s1.begin(), s1.end());

	for(auto x : s2) {
		if(s1[0].first <= x.first && x.first <= s1[4].first &&
				s1[0].second <= x.second && x.second <= s1[4].second)
			inter = true;
	}

	if(inter) cout << "YES\n";
	else cout << "NO\n";
}