#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int N = 3e5+5;
ll x[N];
ll y[N];

ll b[N];
ll b_pref[N] = {};
ll ans[N] = {};

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n, m;
	cin >> n >> m;

	ll sum_y = 0;
	for(int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
		b[i] = x[i] - y[i];

		ans[i] -= x[i] + y[i];
		sum_y += y[i];
	}

	for(int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		ll score = min(x[u] + y[v], x[v] + y[u]);
		ans[u] -= score; ans[v] -= score;
	}

	sort(b, b+n);
	for(int i = 0; i < n; ++i) {
		b_pref[i+1] = b[i];
		b_pref[i+1] += b_pref[i];
	}

	for(int i = 0; i < n; ++i) {
		ans[i] += sum_y;
		ans[i] += n * y[i];

		ll B = x[i] - y[i];
		int lo = -1;
		int hi = n-1;
		while(hi-lo-1) {
			int md = (lo+hi)/2;
			if(b[md] >= B)
				hi = md;
			else lo = md;
		}

		ans[i] += b_pref[hi];
		ans[i] += B * (n-hi);
	}

	for(int i = 0; i < n; ++i)
		cout << ans[i] << " ";
	cout << "\n";
}