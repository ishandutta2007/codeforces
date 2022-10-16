#pragma comment(linker, "/STACK:512000111")
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cassert>

using namespace std; 


bool solve() {
	int n; if (!(cin >> n)) return false;
	
	long long result = 1;
	const long long MOD = 1000000000 + 7;
	
	vector<int> values;
	set<int> L, R;
	bool first = true;
	L.insert(0);
	R.insert(1 << 30);

	for (int i = 0; i < n; ++i) {
		string c; int v;
		cin >> c >> v;

		assert(*L.rbegin() < *R.begin());

		if (c == "ADD") {
			if (*L.rbegin() < v && v < *R.begin()) {
				values.push_back(v);
			} else {
				if (*L.rbegin() > v) {
					L.insert(v);
				} else {
					R.insert(v);
				}
			}
		} else {
			if (*L.rbegin() < v && v < *R.begin()) {
				result = result * 2 % MOD;
				for (int j = 0; j < values.size(); ++j) {
					if (values[j] == v) continue;
					if (values[j] < v) L.insert(values[j]);
					else R.insert(values[j]);
				}
				values.clear();
			} else {
				if (*L.rbegin() > v || *R.begin() < v) {
					result = 0;
					break;
				}
				if (*L.rbegin() == v) {
					L.erase(v);
					for (int j = 0; j < values.size(); ++j)
						R.insert(values[j]);
					values.clear();
				} else {
					R.erase(v);
					for (int j = 0; j < values.size(); ++j)
						L.insert(values[j]);
					values.clear();
				}
			}			
		}
	}
	result = result * (values.size() + 1) % MOD;
	cout << result << endl;
	return true;
}

int main() {
	int t; //cin >> t;
    t = 1;
	while ( solve() );
	return 0;
}