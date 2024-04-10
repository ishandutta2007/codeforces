#include <bits/stdc++.h>
#define ll long long
#define null NULL

using namespace std;

int get_p1(int x) {
	if (x % 2 == 0)
		return x / 2;
	else
		return (x - 1) / 2;
}

int get_m1(int x) {
	if (x % 2 == 0)
		return x / 2;
	else
		return (x + 1) / 2;
}

int n;
vector<int> a;

vector<int> solve(vector<int> t, int mult) {
	//int xxx;
	//cout << "debug ";
	//cin >> xxx;
	/*cout << "solving, t:" << endl;
	for (auto x : t) {
		cout << x << " ";
	}
	cout << endl;
	cout << "mult = " << mult << endl;*/
	if (t.empty()) {
		return vector<int> ();
	}
	if (t.size() == 1 && t[0] == 1) {
		return vector<int> (1, mult);
	}
	if (t.size() == 1 && t[0] == -1) {
		return vector<int> (1, -mult);
	}
	bool m1 = 0;
	for (auto x : t) {
		if (x % 2 != 0) {
			m1 = 1;
			break;
		}
	}
	if (!m1) {
		vector<int> t1;
		for (int i = 0; i < t.size(); ++i) {
			if (t[i] / 2 != 0) {
				t1.push_back(t[i] / 2);
			}
		}
		t1.erase(unique(t1.begin(), t1.end()), t1.end());
		vector<int> r1 = solve(t1, mult * 2);
		return r1;
	}
	else {
		vector<int> t1;
		for (int i = 0; i < t.size(); ++i) {
			int c = get_p1(t[i]);
			if (c != 0) {
				t1.push_back(c);
			}
		}
		t1.erase(unique(t1.begin(), t1.end()), t1.end());
		vector<int> r1 = solve(t1, mult * 2);
		vector<int> t2;
		for (int i = 0; i < t.size(); ++i) {
			int c = get_m1(t[i]);
			if (c != 0) {
				t2.push_back(c);
			}
		}
		t2.erase(unique(t2.begin(), t2.end()), t2.end());
		vector<int> r2 = solve(t2, mult * 2);
		//cout << "returning from " << mult << endl;
		if (r1.size() < r2.size()) {
			r1.push_back(mult);
			return r1;
		}
		else {
			r2.push_back(-mult);
			return r2;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (x != 0) {
			a.push_back(x);
		}
	}
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	vector<int> ans = solve(a, 1);
	cout << ans.size() << endl;
	for (auto x : ans) {
		cout << x << " ";
	}
	cout << endl;
}