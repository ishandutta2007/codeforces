/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 27, M = 201234;
int cnt[N], cnt2[N];
int n, k;
string s;

bool is_valid(int q) {
	if (q < 1)
		return true;
	else if (q > (n + k - 1) / k)
		return false;
	for (int i = 0; i < 26; i++) {
		cnt2[i] = cnt[i];
	}
	for (int i = 0; i < k; i++) {
		int x = q;
		for (int j = 0; j < 26; j++) {
			if (cnt2[j] >= x / 2 * 2) {
				cnt2[j] -= x / 2 * 2;
				x %= 2;
			} else {
				x -= cnt2[j] / 2 * 2;
				cnt2[j] %= 2;
			}
		}
		if (x == 0)
			continue;
		if (x > 1) {
//			cout << i << endl;
			return false;
		}
		bool f = false, h = false;
		for (int i = 0; i < 26; i++) {
			if (cnt2[i] % 2 == 1) {
				cnt2[i]--;
				f = true;
				break;
			}
		}
		if (f)
			continue;
		for (int i = 0; i < 26; i++) {
			if (cnt2[i]) {
				cnt2[i]--;
				h = true;
				break;
			}
		}
		if (!h) {
			return false;
		}
	}
	return true;
}

void solve() {
	cin >> n >> k >> s;
	for (int i = 0; i < 26; i++)
		cnt[i] = 0;
	for (auto c : s) {
		cnt[c - 'a']++;
	}
	int l = 0, r = n + 1;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (is_valid(mid)) {
			l = mid;
		} else {
			r = mid;
		}
	}
	cout << l << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}