/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
map <int, int> cnt;
int a[N];
bool f[N];

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i <= n; i++)
		f[i] = false;
	cnt.clear();
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
		if (a[i] < n)
			f[a[i]] = true;
	}
	int diff = n;
	for (pair <int, int> p : cnt)
		diff -= (p.S - 1);
	int cnt2 = 0, mex = n;
	for (int i = 0; i <= n; i++) {
		if (!f[i]) {
			if (cnt2 == k) {
				mex = i;
				break;
			}
			cnt2++;
		}
	}
	if (mex == n) {
		cout << 0 << '\n';
		return;
	}
	int x = 0;
	vector <int> v;
	for (pair <int, int> p : cnt) {
		if (p.F >= mex) {
			v.push_back(p.S);
		}
	}
	sort(v.begin(), v.end());
	int ps = 0;
	for (int i : v) {
		ps += i;
		if (ps > k)
			break;
		x++;
	}
	diff += max(0, (k - x));
	cout << diff - mex << '\n';
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