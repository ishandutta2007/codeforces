#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

typedef deque<int> qi;

struct state {
	qi a, b;
	state(qi _a, qi _b) {
		a = _a;
		b = _b;
	}

	bool operator<(const state &s) const {
		if (a == s.a)
			return b < s.b;
		return a < s.a;
	}

	bool operator==(const state &s) const {
		return a == s.a && b == s.b;
	}
};

set<state> all;

int main() {
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	qi a, b;
	int k1, k2;
	cin >> k1;
	for (int i = 0; i < k1; ++i) {
		int t;
		cin >> t;
		a.push_back(t);
	}
	cin >> k2;
	for (int i = 0; i < k2; ++i) {
		int t;
		cin >> t;
		b.push_back(t);
	}
	int fights = 0;
	while (!a.empty() && !b.empty()) {

		++fights;
		int _a = a.front();
		int _b = b.front();
		a.pop_front();
		b.pop_front();
		if (_a > _b) {
			a.push_back(_b);
			a.push_back(_a);
		} else {
			b.push_back(_a);
			b.push_back(_b);
		}
		state ss = state(a, b);
		if (all.find(ss) != all.end()) {
			cout << "-1\n";
			return 0;
		}
		all.insert(ss);

	}
	if (a.empty())
		cout << fights << " " << 2 << "\n";
	else if (b.empty()) {
		cout << fights << " " << 1 << "\n";
	}

	return 0;
}