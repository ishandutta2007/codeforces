#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> rest(n);
	iota(rest.begin(), rest.end(), 1);

	while ((int) rest.size() >= 3) {
		vector<int> a[3];
		for (int i = 0; i < (int) rest.size(); ++i) {
			a[i % 3].push_back(rest[i]);
		}
		int banned = 0;

		cout << "? " << a[0].size();
		for (auto x : a[0]) {
			cout << " " << x;
		}
		cout << endl;
		string s;
		cin >> s;

		if (s == "NO") {
			cout << "? " << a[0].size();
			for (auto x : a[0]) {
				cout << " " << x;
			}
			cout << endl;
			cin >> s;
			if (s == "NO") {
				banned = 1;
			} else {
				cout << "? " << a[1].size();
				for (auto x : a[1]) {
					cout << " " << x;
				}
				cout << endl;
				cin >> s;
				if (s == "YES") {
					banned = 4;
				} else {
					banned = 2;
				}
			}
		} else {
			cout << "? " << a[1].size();
			for (auto x : a[1]) {
				cout << " " << x;
			}
			cout << endl;
			cin >> s;
			if (s == "YES") {
				banned = 4;
			} else {
				banned = 2;
			}
		}

		rest.clear();
		for (int i = 0; i < 3; ++i) {
			if (!(banned >> i & 1)) {
				for (auto x : a[i]) {
					rest.push_back(x);
				}
			}
		}
	}

	for (auto x : rest) {
		cout << "! " << x << endl;
		string s;
		cin >> s;
		if (s == ":)") {
			return 0;
		}
	}
	
	return 0;
}