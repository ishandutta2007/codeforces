#include<iostream>
#include<set>
#include<algorithm>
#include<map>
using namespace std;
set<int> x[1048576];
map<int, int>M;
int q;
void add(int p) {
	int ret = 1;
	for (int i = 0; i < 20; i++) {
		x[ret].insert(p);
		if ((p / (1 << (30 - i))) % 2 == 0)ret = ret * 2;
		if ((p / (1 << (30 - i))) % 2 == 1)ret = ret * 2 + 1;
	}
}
void sakujyo(int p) {
	int ret = 1;
	for (int i = 0; i < 20; i++) {
		x[ret].erase(p);
		if ((p / (1 << (30 - i))) % 2 == 0)ret = ret * 2;
		if ((p / (1 << (30 - i))) % 2 == 1)ret = ret * 2 + 1;
	}
}
int max_value(int p) {
	int ret = 1;
	for (int i = 0; i < 19; i++) {
		int bit = 0;
		if ((p / (1 << (30 - i))) % 2 == 0)bit = 0;
		if ((p / (1 << (30 - i))) % 2 == 1)bit = 1;
		if (bit == 0) {
			if (x[2 * ret + 1].size() >= 1)ret = ret * 2 + 1;
			else { ret = ret * 2; }
		}
		if (bit == 1) {
			if (x[2 * ret].size() >= 1)ret = ret * 2;
			else { ret = ret * 2 + 1; }
		}
	}
	int maxn = 0;
	for (auto itr = x[ret].begin(); itr != x[ret].end(); itr++) {
		int c = *itr;
		maxn = max(maxn, c^p);
	}
	return maxn;
}
int main() {
	cin >> q; add(0); M[0]++;
	for (int i = 0; i < q; i++) {
		char op; int p; cin >> op >> p;
		if (op == '+') { add(p); M[p]++; }
		if (op == '-') { if (M[p] == 1)sakujyo(p); M[p]--; }
		if (op == '?') { cout << max_value(p) << endl; }
	}
	return 0;
}