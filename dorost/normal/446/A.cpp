/* 	* In the name of GOD 
	* Thanks God */
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N];

int32_t main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	a[n] = -1;
	vector <pair <int, int>> v;
	for (int i = 0; i < n; i++) {
		int x = i;
		while (a[i + 1] > a[i]) {
			i++;
		}
		v.push_back({x, i - x + 1});
	}
	if (v.size() == 1) {
		cout << n;
		return 0;
	}
	int mx = 0;
	for (int i = 0; i < v.size(); i++) {
		mx = max(mx, v[i].S + 1);
	}
	for (int i = (v[0].S == 1); i < v.size() - 1; i++) {
		if (v[i + 1].F - v[i].F == v[i].S && (a[v[i].F + v[i].S - 2] < a[v[i + 1].F] - 1 || a[v[i].F + v[i].S - 1] < a[v[i + 1].F + 1] - 1)) {
			mx = max(mx, v[i].S + v[i + 1].S);
		}
	}
	cout << mx;
}