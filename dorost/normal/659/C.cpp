/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N];

int32_t main(){
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	a[n] = -1;
	int it = 0;
	vector <int> v;
	for (int i = 1;; i++) {
		if (a[it] == i) {
			it++;
			continue;
		}
		if (m >= i) {
			m -= i;
			v.push_back(i);
		} else {
			break;
		}
	}
	cout << v.size() << '\n';
	for (auto x : v) {
		cout << x << ' ';
	}
}