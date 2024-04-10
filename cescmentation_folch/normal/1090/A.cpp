#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector <pair <long long, long long> >v(n);
	long long M = 0;
	for (int i = 0; i < n; ++i) {
		cin >> v[i].first;
		cin >> v[i].second;
		for (int j = 1; j < v[i].first; ++j) {
			long long a;
			cin >> a;
			v[i].second = max(v[i].second, a);
		}
		M = max(M, v[i].second);
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += (M-v[i].second)*v[i].first;
	}
	cout << ans << endl;
}