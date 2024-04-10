/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 102;
int a[N];

int32_t main() {
	int n;
	cin >> n;
	n *= 2;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int mn = INT_MAX;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			vector <int> v;
			for (int k = 0; k < n; k++) {
				if (k != i && k != j) 
					v.push_back(a[k]);
			}
			sort(v.begin(), v.end());
			int ans = 0;
			for (int i = 0; i < (int) v.size(); i += 2) {
				ans += v[i + 1] - v[i];
			}
			mn = min(mn, ans);
		}
	}
	cout << mn;
}