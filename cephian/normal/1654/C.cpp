#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	ll w = 0;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		w += a[i];
	}
	sort(a.begin(), a.end());
	priority_queue<ll> pq;
	pq.push(w);
	while(pq.size() && a.size()) {
		if(pq.top() == a.back())
			pq.pop(), a.pop_back();
		else if(pq.top() > a.back()) {
			ll x = pq.top();
			pq.pop();
			pq.push(x/2);
			pq.push(x-x/2);
		} else {
			cout << "No\n";
			return;
		}
	}
	if(a.empty() && pq.empty())
		cout << "Yes\n";
	else
		cout << "No\n";
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}