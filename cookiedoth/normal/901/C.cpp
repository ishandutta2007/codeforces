#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mx = 5e5;
vector<int> g[mx];
vector<vector<ll> > cycles;
vector<pair<ll, ll> > seg;
ll n, m, used[mx], tin[mx], timer, p[mx], cn, d[mx], q, pref[mx];

void dfs(ll v, ll pv) {
	tin[v] = timer++;
	//cout << "dfsing " << v << " pv " << pv << endl;
	used[v] = 1;
	p[v] = pv;
	for (auto v1 : g[v]) {
		if (used[v1] == 1 && v1 != pv && tin[v1] < tin[v]) {
			cycles.push_back(vector<ll> ());
			ll u = v;
			//cout << "kok " << u << " " << v1 << endl;
			while (u != v1) {
				//cout << "up " << u << endl;
				cycles.back().push_back(u);
				u = p[u];
			}
			cycles.back().push_back(v1);
		}
		else {
			if (used[v1] == 0)
				dfs(v1, v);
		}
	}
}

ll seg_sum(ll l, ll r) {
	if (l > r)
		return 0;
	if (l == 0)
		return pref[r];
	else
		return pref[r] - pref[l - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u - 1].push_back(v - 1);
		g[v - 1].push_back(u - 1);
	}
	//cout << "MEGA KEKTOR" << endl;
	for (ll i = 0; i < n; ++i) {
		if (used[i] == 0)
			dfs(i, -1);
	}
	cn = cycles.size();
	for (ll i = 0; i < cn; ++i) {
		/*for (auto x : cycles[i]) {
			cout << x << " ";
		}
		cout << endl;
		cout << "lol " << i << endl;
		cout << *min_element(cycles[i].begin(), cycles[i].end()) << endl;
		cout << *max_element(cycles[i].begin(), cycles[i].end()) << endl;*/
		seg.push_back({*min_element(cycles[i].begin(), cycles[i].end()), *max_element(cycles[i].begin(), cycles[i].end())});
	}
	//cout << "seg calced" << endl;
	sort(seg.begin(), seg.end());
	ll close = n, ptr = cn - 1;
	/*cout << "keks" << endl;
	for (int i = 0; i < cn; ++i) {
		cout << seg[i].first << " " << seg[i].second << endl;
	}*/
	for (ll i = n - 1; i >= 0; --i) {
		while (ptr >= 0 && seg[ptr].first >= i) {
			close = min(close, seg[ptr].second);
			ptr--;
		}
		d[i] = close;
	}
	/*cout << "d" << endl;
	for (int i = 0; i < n; ++i) {
		cout << d[i] << " ";
	}
	cout << endl;*/
	pref[0] = d[0];
	for (ll i = 1; i < n; ++i) {
		pref[i] = pref[i - 1] + d[i];
	}
	cin >> q;
	for (ll i = 0; i < q; ++i) {
		ll l, r;
		cin >> l >> r;
		l--;
		r--;
		ll mid = lower_bound(d, d + n, r + 1) - d;
		//cout << "mid" << " " << mid << endl;
		if (mid < l)
			mid = l;
		ll sum_d;
		if (mid > r)
			sum_d = seg_sum(l, r);
		else
			sum_d = seg_sum(l, mid - 1) + (r + 1) * (r - mid + 1);
		ll sum_i = r * (r + 1) / 2 - l * (l - 1) / 2;
		//cout << "infa " << sum_d << " " << sum_i << " " << r - l + 1 << endl;
		ll ans = sum_d - sum_i;
		cout << ans << endl;
	}
}