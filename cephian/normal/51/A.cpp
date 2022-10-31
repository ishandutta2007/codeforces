#include <iostream>
#include <set>

using namespace std;

struct am {
	string a, b;

	bool operator<(const am& c) const {
		if (a[0] == c.a[0]) {
			if (a[1] == c.a[1]) {
				if (b[0] == c.b[0]) {
					return b[1] < c.b[1];
				}
				return b[0] < c.b[0];
			}
			return a[1] < c.a[1];
		}
		return a[0] < c.a[0];
	}

};

am rot(am a) {
	am b;
	b.a = "qq";
	b.b = "qq";
	b.a[1] = a.a[0];
	b.b[1] = a.a[1];
	b.b[0] = a.b[1];
	b.a[0] = a.b[0];
	return b;
}

string tmp;

set<am> s;

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		am a;
		cin >> a.a;
		cin >> a.b;

		if (i != n - 1)
			cin >> tmp;
		bool fnd = false;
		for (int i = 0; i < 4; ++i) {
			if (s.find(a) != s.end()) {
				fnd = true;
				break;
			}
			a = rot(a);
		}

		if (!fnd)
			s.insert(a);
	}

	cout << s.size() << "\n";

	return 0;
}