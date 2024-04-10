#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <string>
#include <map>
using namespace std;

int n, m;
vector<string> people;
map<string, int> invPeople;

bool bad[20][20];

bool ok(int mask) {
	for (int i = 0; i < n; i++) {
		if (!(mask & (1 << i))) continue;
		for (int j = 0; j < n; j++) {
			if (!(mask & (1 << j))) continue;

			if (bad[i][j]) return false;
		}
	}
	return true;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;

		people.push_back(name);
		invPeople[name] = i;
	}

	for (int i = 0; i < m; i++) {
		string a, b;
		cin >> a >> b;
		int i1 = invPeople[a];
		int i2 = invPeople[b];
		bad[i1][i2] = true;
		bad[i2][i1] = true;
	}

	int best = 0;
	for (int mask = 0; mask < (1 << n); mask++) {
		if (__builtin_popcount(mask) > __builtin_popcount(best) && ok(mask)) {
			best = mask;
		}
	}

	vector<string> answer;
	for (int i = 0; i < n; i++) {
		if (best & (1 << i)) answer.push_back(people[i]);
	}

	sort(answer.begin(), answer.end());

	assert(answer.size() == __builtin_popcount(best));
	cout << answer.size() << "\n";
	for (string& s : answer) cout << s << "\n";
}