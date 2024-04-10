/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int b[N], d[N];

int32_t main() {
	int n;
	cin >> n;
	vector <pair <int, int>> v;
	for (int i = 0; i < n; i++) {
		cin >> b[i] >> d[i];
		d[i]--;
		v.push_back({b[i], 0});
		v.push_back({d[i], 1});
	}
	sort(v.begin(), v.end());
	int mx = INT_MIN, sol = -1, cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		cnt += (v[i].S == 0 ? +1 : -1);
		if (cnt > mx) {
			mx = cnt;
			sol = v[i].F;
		}
	}
	cout << sol << ' ' << mx;
}