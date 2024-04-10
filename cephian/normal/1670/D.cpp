#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> f = {0};

void solve() {
	ll n;
	cin >> n;
	int hi = f.size()-1, lo = 0;
	while(hi-1 > lo) {
		ll md = (lo+hi)/2;
		if(f[md] >= n)
			hi = md;
		else lo = md;
	}
	cout << hi << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll amt[3] = {0, 0, 0};
	for (int i = 1; f.back() <= 1e9; ++i) {
		ll intersect = amt[0] + amt[1] + amt[2] - amt[i % 3];
		f.push_back(f.back() + intersect * 2);
		++amt[i%3];
	}

	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}