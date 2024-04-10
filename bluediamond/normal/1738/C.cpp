#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


#ifdef ONPC
mt19937 rng(228);
#else
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
 
const int N = 100;
int can_make_memo[N][N][2];

int can_make(int even, int odd, int what) {
	if (can_make_memo[even][odd][what] != -1) {
		return can_make_memo[even][odd][what];
	}
	int& sol = can_make_memo[even][odd][what];
	sol = 0;
	int total = odd % 2;
	int want_oth = total ^ what;
	if (even >= 1) {
		if (can_make(even - 1, odd, 1 ^ want_oth) == 0) {
			sol = 1;
		}
	}	
	if (odd >= 1) {
		if (can_make(even, odd - 1, 1 ^ want_oth) == 0) {
			sol = 1;
		}
	}
	
	return sol;
}
 
int main() {
#ifndef ONPC
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif

	{
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				can_make_memo[i][j][0] = can_make_memo[j][i][1] = -1;
			}
		}
		can_make_memo[0][0][0] = 1;
		can_make_memo[0][0][1] = 0;
	}
	

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int n;
		cin >> n;
		vector<int> cnt(2, 0);
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			x %= 2;
			if (x < 0) {
				x += 2;
			}
			assert(0 <= x && x <= 1);
			cnt[x]++;
		}
		if (can_make(cnt[0] % 2, cnt[1] % 4, 0)) {
			cout << "Alice\n";
		} else {
			cout << "Bob\n";
		}
	}
	
	return 0;
}