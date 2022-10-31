#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<int,vector<int>> all;
int a[200005];

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i) {
		int b;
		cin >> b;
		all[a[i]].push_back(b);
	}
	int at = 0;
	ll sum = 0;
	priority_queue<ll> Q;
	ll ans = 0;
	while(all.size() || sum > 0) {
		if(all.count(at)) {
			auto& v = all[at];
			sort(v.begin(), v.end());
			for(int i = 0; i < v.size(); ++i) {
				sum += v[i];
				Q.push(v[i]);
			}
			all.erase(at);
		}
		if(sum > 0) {
			sum -= Q.top();
			Q.pop();
			ans += sum;
			++at;
		} else {
			at = all.begin()->first;
		}
	}
	cout << ans << '\n';
}