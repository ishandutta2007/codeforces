/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1000;
int mp[N];

void solve() {
	vector <int> v;
	set <int> st = {4, 8, 15, 16, 23, 42};
	cout << "? 1 1" << endl;
	int x;
	cin >> x;
	x = sqrt(x);
	st.erase(x);
	v.push_back(x);
	cout << "? 2 2" << endl;
	cin >> x;
	x = sqrt(x);
	st.erase(x);
	v.push_back(x);
	cout << "? 3 4" << endl;
	cin >> x;
	bool f = false;
	for (auto a : st) {
		for (auto b : st) {
			if (a * b == x) {
				st.erase(a);
				st.erase(b);
				v.push_back(a);
				v.push_back(b);
				f = true;
				break;
			}
		}
		if (f)
			break;
	}
	cout << "? 3 5" << endl;
	cin >> x;
	if (x % v[3] == 0 && st.count(x / v[3])) {
		st.erase(x / v[3]);
		v.push_back(x / v[3]);
		swap(v[2], v[3]);
	} else {
		st.erase(x / v[2]);
		v.push_back(x / v[2]);
	}
	v.push_back(*st.begin());
	cout << "! ";
	for (auto a : v) {
		cout << a << ' ';
	}
	cout << endl;
}

int32_t main() {
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}