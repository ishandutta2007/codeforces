#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	ll ans = 0;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if(pq.size() && pq.top() < a) {
			ans += a - pq.top();
			pq.pop();
			pq.emplace(a);
		}
		pq.emplace(a);
	}
	cout << ans << "\n";
}