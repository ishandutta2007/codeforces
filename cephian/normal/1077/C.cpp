#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	map<ll, vector<int>> m;
	int n;
	cin >> n;
	ll s = 0;
	vector<ll> a(n);
	for(int i = 0; i < n;++i) {
		cin >> a[i];
		s += a[i];
		m[a[i]].push_back(i);
	}
	vector<int> ans;
	for(int i = 0; i < n; ++i) {
		ll ns = s - a[i];
		if(ns%2 == 1) continue;
		for(int x : m[ns/2]) {
			if(x != i) {
				ans.push_back(i+1);
				break;
			}
		}
	}

	cout << ans.size() << "\n";
	for(int x : ans)
		cout << x << " ";
	cout << "\n";
}