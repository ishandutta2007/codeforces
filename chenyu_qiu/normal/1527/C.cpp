#include<bits/stdc++.h>
using namespace std;
#define cerr if(false)	cerr
#define ll long long
const int MOD = 1e9 + 7;
void solve();
int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
void solve() {
	int n;
	cin>>n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin>>v[i];
	}
	map<ll, ll> mp;
	ll sum = 0;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans += mp[v[i]];
		sum += ans;
		mp[v[i]] += i+1;
	}
	cout<<sum<<endl;
}