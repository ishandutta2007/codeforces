/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 19;
int dp[(1 << N)];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	vector <vector <int>> v = {
		{0, 1, 2},
		{3, 4, 5, 6},
		{7, 8, 9, 10, 11},
		{12, 13, 14, 15},
		{16, 17, 18},
		{0, 3, 7},
		{1, 4, 8, 12},
		{2, 5, 9, 13, 16},
		{6, 10, 14, 17},
		{11, 15, 18},
		{2, 6, 11},
		{1, 5, 10, 15},
		{0, 4, 9, 14, 18},
		{3, 8, 13, 17},
		{7, 12, 16}
	};
	vector <int> a;
	for (vector <int> w : v) {
		int n = w.size();
		for (int l = 0; l < n; l++) {
			int mask = 0;
			for (int r = l; r < n; r++) {
				mask ^= (1 << w[r]);
				a.push_back(mask);
			}
		}
	}
	for (int i = 0; i < (1 << 19); i++) {
		if (i == 0) {
			dp[i] = 1;
		} else {
			for (int j : a) {
				if ((i & j) == j) {
					dp[i] |= dp[i - j];
				}
			}
			dp[i] = !dp[i];
		}
	}
	int mask = 0;
	for (int i = 0; i < 19; i++) {
		char c;
		cin >> c;
		if (c == 'O')
			mask += (1 << i);
	}
	cout << (dp[mask] == 1 ? "Lillebror" : "Karlsson");
}