#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<ll> p(41);
	p[0] = 1;
	for (int i = 1; i < 41; i++) {
		p[i] = p[i - 1] * 2;
	}
	vector<ll> st(41);
	vector<ll> rest;
	for (int i = 0; i < n; i++) {
		auto it = find(p.begin(), p.end(), a[i]);
		if (it != p.end()) {
			st[it - p.begin()]++;
		}
		else {
			rest.push_back(a[i]);
		}
	}
	ll cnt1 = count(a.begin(), a.end(), 1);
	ll l = 0;
	ll r = cnt1 + 1;
	while (r - l > 1) {
		ll mid = (l + r) / 2;
		vector<ll> cant = rest;
		for (int i = 0; i < cnt1 - mid; i++) {
			cant.push_back(1);
		}
		vector<ll> last(mid, 1);
		ll cnt = mid;
		for (int i = 1; i < 41; i++) {
			for (int j = 0; j < min(st[i], cnt); j++) {
				last[j] = p[i];
			}
			if (st[i] > cnt) {
				for (int j = 0; j < st[i] - cnt; j++) {
					cant.push_back(p[i]);
				}
			}
			else {
				cnt = st[i];
			}
		}
		sort(cant.begin(), cant.end());
		reverse(cant.begin(), cant.end());
		bool f = false;
		if ((int)cant.size() > mid) {
			f = true;
		}
		else {
			for (int i = 0; i < (int)cant.size(); i++) {
				if (cant[i] >= 2 * last[i]) {
					f = true;
					break;
				}
			}
		}
		if (f) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	if (r > cnt1) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = r; i <= cnt1; i++) {
		cout << i << ' ';
	}
	cout << endl;
    return 0;
}