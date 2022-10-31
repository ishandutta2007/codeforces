#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

int a[N];
int gt[N] = {};
long long ans = 0;

map<pair<int,int>,int> prv;

inline void edit(int to, int amt) {
	ans -= max(0, a[to] - gt[to]);
	gt[to] += amt;
	ans += max(0, a[to] - gt[to]);
}


int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, q;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		ans += a[i];
	}
	cin >> q;
	while(q--) {
		int s, t, u;
		cin >> s >> t >> u;
		pair<int,int> p(s,t);
		if(prv.count(p)) {
			edit(prv[p], -1);
			prv.erase(p);
		}
		if(u != 0) {
			prv[p] = u;
			edit(u, 1);
		}
		cout << ans << '\n';
	}
}