#include <iostream>
#include <iterator>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	multiset<string> s;
	while (n--) {
		string str;
		cin >> str;
		s.insert(str);
	}
	int mx = 0;
	for (auto a : s) {
		auto p = s.equal_range(a);
		mx = max(mx, distance(p.first, p.second));
	}
	cout << mx << "\n";

	return 0;
}