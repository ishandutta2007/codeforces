/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
ll a[N];

int32_t main() {
	multiset <ll> st, st2;
	ll sum = 0, ps = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		st2.insert(a[i]);
		sum += a[i];
	}
	if (sum % 2) {
		cout << "NO\n";
		return 0;
	}
	if (st2.count(sum / 2)) {
		cout << "YES\n";
		return 0;
	}
	for (int i = 0; i < n; i++) {
		ps += a[i];
		ll ps2 = sum - ps;
		st.insert(a[i]);
		st2.erase(st2.find(a[i]));
		ll x = ps - ps2;
		if (x < 0) {
			if (st2.count((-x) / 2)) {
				cout << "YES";
				return 0;
			}
		} else {
			if (st.count(x / 2)) {
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
}