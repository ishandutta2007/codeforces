#include <bits/stdc++.h>
using namespace std;

const int N = 220000;

map<int, pair<long long, long long>> M;
map<int, int> H;

long long get(int x) {
	auto it = M.upper_bound(x);
	if (it == M.begin()) return 0;
	it--;
	long long a = it->second.first, b = it->second.second;
	return a * x + b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n; long long s; cin >> n >> s;
	for (int i = 0; i < n; i++) {
		int v, c; cin >> v >> c;
		auto it = H.upper_bound(c);
		if (it != H.begin()) {
			--it;
			if (it->second >= v) continue;
			it++;
		}
		vector<int> era;
		while (it != H.end()) {
			if (it->second <= v) era.push_back(it->first), it++;
			else break;
		}
		for (int x : era) H.erase(x);
		H[c] = v;
	}
	for (auto t : H) {
		int x = t.first, y = t.second;
		int st = 0, en = 1e8+10;
		while (st < en) {
			int md = (st + en) / 2;
			long long val = get(md);
			if (val >= x) en = md;
			else st = md + 1;
		}
		long long a = y;
		long long b = get(st) - x - a * st;
		en = 1e8 + 10;
		while (st < en) {
			int md = (st + en) / 2;
			long long val = get(md);
			if (val <= 1ll * a * md + b) en = md;
			else st = md + 1;
		}
		while (M.size() && M.rbegin()->first >= st) M.erase(M.rbegin()->first);
		M[st] = make_pair(a, b);
	}
	int st = 0, en = 1e8 + 10;
	while (st < en) {
		int md = st + en >> 1;
		long long val = get(md);
		if (val >= s) en = md;
		else st = md + 1;
	}
	if (get(st) >= s) return cout << st << endl, 0;
	auto la = M.rbegin()->second;
	cout << (s - la.second + la.first - 1) / la.first << endl;
}