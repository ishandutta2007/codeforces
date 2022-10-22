/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
ll ps[N];
int a[N], n, s;

pair <bool, pair <int, int>> is_valid(int x) {
	if (x == 0)
		return {true, {0, 0}};
	if (x == n + 1)
		return {false, {0, 0}};
	deque <ll> q;
	vector <ll> v;
	for (int j = 0; j < x; j++) {
		while (!q.empty() && ps[q.back()] >= ps[j]) {
			q.pop_back();
		}
		q.push_back(j);
		while (!q.empty() && q.front() < j - x + 1) {
			q.pop_front();
		}
	}
	v.push_back(ps[q.front()]);
	for (int j = x; j < n; j++) {
		while (!q.empty() && ps[q.back()] >= ps[j]) {
			q.pop_back();
		}
		q.push_back(j);
		while (!q.empty() && q.front() < j - x + 1) {
			q.pop_front();
		}
		v.push_back(ps[q.front()]);
	}
	for (int i = 0; i < v.size(); i++) {
		v[i] -= (i == 0 ? 0 : ps[i - 1]);
		v[i] += s;
		if (v[i] >= 0) {
			return {true, {i + 1, i + x}};
		}
	}
	return {false, {0, 0}};
}

void solve() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i == 0)
			ps[i] = a[i];
		else
			ps[i] = ps[i - 1] + a[i];
	}
	int l = 0, r = n + 1;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (is_valid(mid).F) {
			l = mid;
		} else {
			r = mid;
		}
	}
	if (l == 0) {
		cout << -1 << '\n';
	} else {
		cout << is_valid(l).S.F << ' ' << is_valid(l).S.S << '\n';
	}
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