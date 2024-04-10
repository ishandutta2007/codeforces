/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
#define F first
#define S second
#define mkp make_pair
const int K = 82, N = 101234;

bool ask (vector <int> v) {
	cout << "? " << v.size() << ' ';
	for (int i : v)
		cout << i << ' ';
	cout << endl;
	string s;
	cin >> s;
	return (s == "YES");
}

void solve() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int n;
	cin >> n;
	vector <int> v;
	for (int i = 1; i <= n; i++)
		v.push_back(i);
	while (v.size() > 2) {
		vector <int> a, b, c;
		int x = (int)v.size();
		int sz1 = x / 3, sz2 = x / 3, sz3 = x / 3;
		if (x % 3 == 1) {
			sz1++;
		} else if (x % 3 == 2) {
			sz1++;
			sz2++;
		}
		for (int j = 0; j < sz1; j++) {
			a.push_back(v[j]);
		}
		for (int j = sz1; j < sz1 + sz2; j++)
			b.push_back(v[j]);
		for (int j = sz1 + sz2; j < sz1 + sz2 + sz3; j++)
			c.push_back(v[j]);
		bool f = ask(a);
		int del = 0;
		if (f) {
			bool h = ask(b);
			if (h) {
				del = 3;
			} else {
				del = 2;
			}
		} else {
			bool h = ask(a);
			if (!h) {
				del = 1;
			} else {
				bool l = ask(b);
				if (l) {
					del = 3;
				} else {
					del = 2;
				}
			}
		}
		v.clear();
		if (del != 1)
			for (int i : a)
				v.push_back(i);
		if (del != 2)
			for (int i : b)
				v.push_back(i);
		if (del != 3)
			for (int i : c)
				v.push_back(i);
	}
	for (int i : v) {
		cout << "! " << i << endl;
		string s;
		cin >> s;
		if (s == ":)")
			return;
	}
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