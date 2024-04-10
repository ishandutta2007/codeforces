#include <bits/stdc++.h>
#define ll long long
#define int long long
#define null NULL

using namespace std;

const int mx = 3e5;
int n, m, p, ans;
vector<pair<int, int> > v;

void go() {
	int sum = 0;
	/*cout << "v" << endl;
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i].first << " " << v[i].second << endl;
	}*/
	for (int i = 0; i < v.size(); ++i) {
		//cout << "i = " << i << endl;
		if (i > 0)
			sum -= p * (v[i].first - v[i - 1].first);
		sum += v[i].second;
		//cout << "sum = " << sum << endl;
		if (i < v.size() - 1) {
			int days = v[i + 1].first - v[i].first;
			//cout << "days " << days << endl;
			if (sum < 0) {
				//cout << "ans += days" << endl;
				ans += days;
			}
			else {
				int positive_days = (sum + 1 + p - 1) / p;
				ans += max(days - positive_days + 1, (ll)0);
				//cout << "positive_days " << positive_days << endl;
				//cout << "ans += " << max(days - positive_days + 1, (ll)0) << endl;
			}
		}
	}
}

signed main() {
	cin >> n >> p >> m;
	for (int i = 0; i < n; ++i) {
		int d, t;
		cin >> d >> t;
		d--;
		v.push_back({d, t});
	}
	v.push_back({0, 0});
	v.push_back({m, 0});
	sort(v.begin(), v.end());
	go();
	cout << ans << endl;
}