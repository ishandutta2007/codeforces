/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N], b[N], v[N * 2], h = 0, te[N * 2];

ll mergeSort(int l, int r) {
	if (r - l <= 1)
		return 0;
	int mid = (l + r) / 2;
	ll ans = mergeSort(l, mid) + mergeSort(mid, r);
	int pb = l, pr = mid;
	for (int i = 0; i < r - l; i++) {
		bool f;
		if (pb == mid)
			f = false;
		else if (pr == r)
			f = true;
		else if (v[pb] < v[pr])
			f = true;
		else
			f = false;
		if (f) {
			te[i] = v[pb];
			ans += pr - mid;
//			cout << v[pb] << '\n';
			pb++;
		} else {
			te[i] = v[pr];
//			cout << v[pr] << '\n';
			pr++;
		}
	}
	for (int i = 0; i < r - l; i++) {
		v[i + l] = te[i];
	}
	return ans;
}

int32_t main() {
	int n;
	cin >> n;
	map <int, int> mp, mp2;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		if (mp[a[i]] == 0)
			mp[a[i]] = a[i];
		if (mp[b[i]] == 0)
			mp[b[i]] = b[i];
		swap(mp[a[i]], mp[b[i]]);
	}
	int cnt = 0;
	for (auto [x, y] : mp) {
		mp2[x] = cnt;
		cnt++;
		v[h] = y;
		h++;
	}
	ll ans = mergeSort(0, h);
	for (auto [x, y] : mp) {
		ans += (abs(x - y) - abs(mp2[x] - mp2[y]));
	}
	cout << ans;
}