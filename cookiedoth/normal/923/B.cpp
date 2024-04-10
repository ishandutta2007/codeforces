#include <bits/stdc++.h>
#define ll long long
#define null NULL

using namespace std;

const ll MOD = 1e9 + 7;

const ll mx = 3e5;
ll n, v[mx], t[mx], kek_pref[mx], rpos[mx], ans[mx];
ll *pref;
vector<pair<ll, ll> > ev;

ll get_sum_on_seg(ll l, ll r) {
	//cout << "getting_sum on " << l << " " << r << endl;
	if (l > r)
		return 0;
	return pref[r] - pref[l - 1];
}

ll binsearch(ll pos, ll sum, ll l, ll r) {
	//cout << "binsearching " << pos << " " << sum << " " << l << " " << r << endl;
	if (l == r)
		return l;
	ll mid = (l + r) >> 1;
	if (get_sum_on_seg(pos, mid + 1) <= sum)
		return binsearch(pos, sum, mid + 1, r);
	else
		return binsearch(pos, sum, l, mid);
}

int main() {
	ios_base::sync_with_stdio(false);
	pref = kek_pref + 1;
	cin >> n;
	for (ll i = 0; i < n; ++i) {
		cin >> v[i];
	}
	for (ll i = 0; i < n; ++i) {
		cin >> t[i];
	}
	for (ll i = 0; i < n; ++i) {
		pref[i] = pref[i - 1] + t[i];
	}
	for (ll i = 0; i < n; ++i) {
		rpos[i] = binsearch(i, v[i], i - 1, n - 1);
		ev.push_back({i, 1});
		ev.push_back({rpos[i] + 1, -1});
		if (rpos[i] < n - 1) {
			ans[rpos[i] + 1] += (v[i] - get_sum_on_seg(i, rpos[i]));
		}
	}
	/*cout << "rpos" << endl;
	for (ll i = 0; i < n; ++i) {
		cout << rpos[i] << " ";
	}
	cout << endl;
	cout << "ans" << endl;
	for (ll i = 0; i < n; ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;*/
	sort(ev.begin(), ev.end());
	/*for (ll i = 0; i < ev.size(); ++i) {
		cout << ev[i].first << " " << ev[i].second << endl;
	}
	cout << endl;*/
	ll ptr = 0, cnt = 0;
	for (ll i = 0; i < n; ++i) {
		while (ptr < ev.size() && ev[ptr].first == i) {
			cnt += ev[ptr].second;
			ptr++;
		}
		//cout << "i = " << i << endl;
		//cout << "cnt = " << cnt << endl;
		ans[i] += cnt * (t[i]);
	}
	for (ll i = 0; i < n; ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;
}