#include <bits/stdc++.h>
#define int long long 

using namespace std;

map<int, map<int, int, greater<int>>> comp;
map<int, int, greater<int>> Add(int x) {
	if (x == 0) return {};
	if (comp.count(x)) return comp[x];
	
	int choose = (x - 1) / 2;
	int diff = min(choose + 1, x - choose);
	
	map<int, int, greater<int>> ret = {{diff, 1}};
	for (int xp : {choose, x - choose - 1})
	for (auto p : Add(xp))
		ret[p.first] += p.second;
	return comp[x] = ret;
}

int Solve(int x, int seek, int& cnt) {
	int choose = (x - 1) / 2;
	int diff = min(choose + 1, x - choose);
	if (diff == seek) {
		return choose + cnt;
	}
	int ret = 0;
	for (int xp : {choose, x - choose - 1}) {
		int now = Add(xp)[seek];
		if (now > cnt) {
			return ret + Solve(xp, seek, cnt); 
		}
		cnt -= now;
		ret += choose + 1;
	}
	assert(false);
}

int32_t main() {
	int n, k; cin >> n >> k;
	
	if (k == 1) { cout << 1 << endl; return 0; }
	if (k == 2) { cout << n << endl; return 0; }
	n -= 2;
	k -= 3;
	
	for (auto p : Add(n)) {
		if (p.second > k) {
			cout << 2 + Solve(n, p.first, k) << endl;	
			return 0;
		}
		k -= p.second;
	}
	assert(false);
	return 0;
}