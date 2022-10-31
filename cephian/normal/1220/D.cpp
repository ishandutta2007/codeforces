#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<ll, vector<ll>> p2;

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		ll a;
		cin >> a;
		ll b = a;
		int p = 0;
		while(a%2 == 0) {
			++p;
			a /= 2;
		}
		p2[p].push_back(b);
	}
	int sz = -1, w = 0;
	for(const auto& x : p2) {
		if((int)x.second.size() > sz) {
			sz = x.second.size();
			w = x.first;
		}
	}

	cout << n-sz << '\n';

	for(const auto& x : p2) {
		if(w == x.first) continue;
		for(auto y : x.second) {
			cout << y << ' ';
		}
	}
	if(n-sz > 0) cout << '\n';
}