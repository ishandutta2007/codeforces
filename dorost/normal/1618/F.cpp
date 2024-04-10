/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

bool is_sub(vector <int> s, vector <int> t) {
	int n = t.size(), m = s.size();
	for (int i = 0; i <= n - m; i++) {
		vector <int> s2;
		for (int j = i; j < i + m; j++) 
			s2.push_back(t[j]);
		if (s == s2)
			return true;
	}
	return false;
}

bool check(vector <int> a, vector <int> b) {
	vector <int> b2 = b;
	reverse(b2.begin(), b2.end());
	if (!is_sub(b, a) && !is_sub(b2, a))  
		return false;
	int x = 0;
	for (int i = 0; i < a.size(); i++)
		if (a[i] == 0)
			x++;
	for (int i = 0; i < b.size(); i++) 
		if (b[i] == 0)
			x--;
	return (x == 0);
}

void solve() {
	ll a, b;
	cin >> a >> b;
	if (a == b) {
		cout << "yes";
		return;
	}
	vector <int> s, t;
	while (a) {
		s.push_back(a % 2);
		a /= 2;
	}
	while (b) {
		t.push_back(b % 2);
		b /= 2;
	}
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	s.push_back(1);
	if (check(t, s)) {
		cout << "yes";
		return;
	} else {
		s.pop_back();
		while (s.back() == 0)
			s.pop_back();
		if (check(t, s)) {
			cout << "yes";
			return;
		}
	}
	cout << "no";
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}