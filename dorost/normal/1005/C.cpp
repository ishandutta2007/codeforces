/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 120000, M = 31;
int a[N], p2[M];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	p2[0] = 1;
	for (int i = 1; i < M; i++) {
		p2[i] = p2[i - 1] * 2;
	}
	int n;
	cin >> n;
	map <int, int> cnt;
	map <int, int> cnt2;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt2[a[i]]++;
		cnt[a[i]]++;
	}
	int ans = n;
	for (auto [x, y] : cnt) {
		for (int i = 0; i < M; i++) {
			int z = p2[i] - x;
			if (z == x && y == 1) 
				continue;
			ans -= cnt2[z];
			cnt2[z] = 0;
		}
	}
	cout << ans;
}