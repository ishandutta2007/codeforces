#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>
using namespace std;

const int MOD = 1e9 + 9;
const int N = 111111;

map<pair<int, int>, int> ID;

int n;
set<int> upper;
pair<int, int> pos[N];

bool stable(int x, int y) {
	if (!ID.count(make_pair(x, y)) || ID[make_pair(x, y)] == 0) {
		return true;
	}
	if (ID.count(make_pair(x - 1, y - 1)) && ID[make_pair(x - 1, y - 1)] != 0) {
		return true;
	}
	if (ID.count(make_pair(x, y - 1)) && ID[make_pair(x, y - 1)] != 0) {
		return true;
	}
	if (ID.count(make_pair(x + 1, y - 1)) && ID[make_pair(x + 1, y - 1)] != 0) {
		return true;
	}
	return false;
}

bool removable(int id) {
	int x = pos[id].first, y = pos[id].second;
	ID[make_pair(x, y)] = 0;
	bool flag = (stable(x - 1, y + 1) && stable(x, y + 1) && stable(x + 1, y + 1));
	ID[make_pair(x, y)] = id;
	return flag;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		ID[make_pair(x, y)] = i;
		pos[i] = make_pair(x, y);
	}
	for(map<pair<int, int>, int> :: iterator it = ID.begin(); it != ID.end(); ++it) {
		int x = it->first.first;
		int y = it->first.second;
		//cout << x << " " << y << endl;
		if (removable(it->second)) {
			upper.insert(it->second);
		}
	}
	long long answer = 0;
	for(int i = 1; i <= n; i++) {
		int id;
		if (i % 2 == 1) {
			id = *(upper.rbegin());
			upper.erase(*(upper.rbegin()));
		} else {
			id = *(upper.begin());
			upper.erase(upper.begin());
		}
		//cout << id - 1 << endl;
		answer = (answer * n + id - 1) % MOD;
		int x = pos[id].first, y = pos[id].second;
		ID.erase(make_pair(x, y));
		if (ID.count(make_pair(x - 1, y - 1)) && removable(ID[make_pair(x - 1, y - 1)])) {
			upper.insert(ID[make_pair(x - 1, y - 1)]);
		}
		if (ID.count(make_pair(x, y - 1)) && removable(ID[make_pair(x, y - 1)])) {
			upper.insert(ID[make_pair(x, y - 1)]);
		}
		if (ID.count(make_pair(x + 1, y - 1)) && removable(ID[make_pair(x + 1, y - 1)])) {
			upper.insert(ID[make_pair(x + 1, y - 1)]);
		}
		for(int d = 1; d <= 2; d ++) {
			if (ID.count(make_pair(x - d, y)) && !removable(ID[make_pair(x - d, y)])) {
				int record = ID[make_pair(x - d, y)];
				//cout << "!! " << record << endl;
				if (upper.find(record) != upper.end()) {
					upper.erase(record);
				}
			}
			if (ID.count(make_pair(x + d, y)) && !removable(ID[make_pair(x + d, y)])) {
				int record = ID[make_pair(x + d, y)];
				//cout << "!! " << record << endl;
				if (upper.find(record) != upper.end()) {
					upper.erase(record);
				}
			}
		}
	}
	cout << answer << endl;
	return 0;
}