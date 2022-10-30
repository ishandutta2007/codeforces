#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
typedef long double ld;
 
ll a[100010];
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	ll n;
	cin>>n;
	for (ll i=0; i<n; ++i) cin>>a[i];
	vector<ll> one, two;
	set<pair<ll, ll>> ans;
	for( ll i=n-1; i>=0; --i) {
		if (a[i]==0) continue;
		else if (a[i]==1) {
			ans.insert({i, i});
			one.push_back(i);
		} else if (a[i]==2) {
			if (one.empty()) {
				cout<<-1<<endl;
				return 0;
			}
			ll u = one.back();
			one.pop_back();
			ans.insert({i, i});
			ans.erase({u, u});
			ans.insert({i, u});
			two.push_back(i);
		} else {
			if (one.empty() && two.empty()) {
				cout<<-1<<endl;
				return 0;
			}
			ll u;
			if (two.empty()) {
				u = one.back();
				one.pop_back();
			} else {
				u = two.back();
				two.pop_back();
			}
			ans.insert({i, i});
			ans.insert({i, u});
			two.push_back(i);
		}
	}
	cout<<ans.size()<<'\n';
	for (auto o:ans)cout<<o.first+1<<' '<<o.second+1<<'\n';
}