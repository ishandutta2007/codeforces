#include<bits/stdc++.h>
 
#define ll long long int
using namespace std;
 
vector<pair<int,int>>a[200001];
 
int main() {
	ios::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL);
 
	ll fib[100001] = { 0 };
	fib[0] = 1, fib[1] = 1;
	for (int i = 2; i <= 56; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
 
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<ll>v(n);
		priority_queue<ll>pq;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i]; sum += v[i];
			pq.push(v[i]);
		}
		++sum;
 
		int idx = -1;
		for (int i = 0; i < 57; i++) {
			if (sum == fib[i]) {
				idx = i - 2;
			}
		}
 
		if (idx == -1) {
			cout << "NO" << "\n"; continue;
		}
		bool error = 0;
		ll rem = 0;
		for (int i = idx; i > -1; i--) {
			if (pq.empty()) {
				error = 1; break;
			}
			ll cur = pq.top();
			pq.pop();
			if (rem != 0)pq.push(rem);
			rem = cur - fib[i];
			if (rem < 0) { error = 1; break; }
		}
		if (error)cout << "NO" << "\n";
		else cout << "YES" << "\n";
 
 
	}
 
 
	return 0;
}