#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n; string s;
	cin >> n >> s;
	int cnt = 0;
	vector<pii> pts;
	pts.push_back(pii(0, 0));
	for(int i=0;i<n;++i) {
		pts.push_back(pts.back());
		if(s[i] == 'U')
			pts.back().second++;
		if(s[i] == 'R')
			pts.back().first++;
	}
	for(int i=2;i<n+1;++i) {
		if(pts[i].first > pts[i].second != pts[i-2].first > pts[i-2].second &&
				pts[i].first != pts[i].second && pts[i-2].first != pts[i-2].second) {
			++cnt;
		}
	}
	cout << cnt << endl;
	return 0;
}