#include <iostream>
#include <set>

using namespace std;

void addpow(set<int>& s, int p) {
	if (s.find(p) != s.end()) {
		s.erase(p);
		addpow(s, p + 1);
	} else
		s.insert(p);
}

int main() {
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	set<int> s;

	for (int i = 0; i < n; ++i) {
		int p;
		cin >> p;
		addpow(s, p);
	}

	int prev = -1;
	int add = 0;

	for (auto i : s) {
		add += i - prev - 1;
		prev = i;
	}

	cout << add << "\n";
	return 0;
}