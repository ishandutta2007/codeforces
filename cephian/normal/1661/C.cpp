#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll min_days(vector<int> &h, int tgt) {
	ll d1 = 0;
	ll d2 = 0;
	for (const int x : h) {
		ll diff = tgt - x;
		d2 += diff / 2;
		if (diff % 2 == 1)
			++d1;
	}
	if(d1 < d2) {
		ll x = (d2 - d1+1)/3;
		d2 -= x;
		d1 += 2*x;
	}
	return max(d1*2-1, d2*2);
}

void solve() {
	int n;
	cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; ++i)
		cin >> h[i];
	int mx = *max_element(h.begin(), h.end());
	cout << min(min_days(h, mx), min_days(h, mx + 1)) << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}