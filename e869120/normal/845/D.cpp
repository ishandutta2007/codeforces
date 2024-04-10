#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<functional>
#include<algorithm>
#include<queue>
using namespace std;
int n, a[500000], b[500000], d[500000], c[7] = { 0,0,1,0,2,0,3 }; vector<int>O, C; int cnt = 0;
pair<int, int>F[500000]; int sz = 0, sp = 0;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 2 || a[i] == 4 || a[i] == 6) {
			O.push_back(c[a[i]]);
		}
		else {
			if (a[i] == 5)C.push_back(1000000007);
			if (a[i] == 1) { cin >> b[i]; C.push_back(-b[i]); sp = b[i]; }
			if (a[i] == 3) { cin >> b[i]; C.push_back(b[i]); C.push_back(-sp); }
		}
	}
	for (int i = 0; i < O.size(); i++) {
		if (O[i] == 1 && (i == 0 || O[i] != O[i - 1])) {
			for (int j = i - 1; j >= 0; j--) {
				if (O[j] == 3)cnt++; else break;
			}
		}
	}
	F[0] = make_pair(-1000000007, -1); sz = 1;
	for (int i = 0; i < C.size(); i++) {
		if (C[i] < 0) {
			int pos = lower_bound(F, F + 499999, make_pair(C[i], 1000000007)) - F;
			if (pos < sz) { d[F[pos - 1].second + 1]++; d[i]--; }
		}
		else {
			while (sz > 0 && F[sz - 1].first > (-C[i])) { F[sz - 1] = make_pair(0, 0); sz--; }
			F[sz] = make_pair(-C[i], i); sz++;
		}
	}
	for (int i = 1; i < 499999; i++)d[i] += d[i - 1];
	for (int i = 0; i < C.size(); i++) {
		if (C[i] > 0 && d[i] >= 1) { cnt++; }
	}
	cout << cnt << endl;
	return 0;
}