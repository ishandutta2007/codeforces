#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	ll n, I;
	cin >> n >> I;
	ll k = (I*8) / n;
	ll K = 1LL<< min(k, 40LL);
	map<int,int> m;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		++m[a];
	}
	vector<int> v = {0};
	for(auto x : m) {
		v.push_back(x.second);
	}
	for(int i = 1; i < (int)v.size(); ++i) {
		v[i] += v[i-1];
	}
	ll best = n;
	for(int i = 1; i < v.size(); ++i) {
		ll j = min((ll)v.size(), i+K);
		ll poss = ll(n)-ll(v[j-1] - v[i-1]);
		best = min(best, poss);
	}
	cout << best << endl;
}