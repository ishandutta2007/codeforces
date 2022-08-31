#include <bits/stdc++.h>
using namespace std;

int main() {
	int N; cin >> N;
	priority_queue<int,vector<int>,greater<int>> pq;
	long long ans = 0;
	for (int i = 0; i < N; ++i) {
		int p; cin >> p; ans -= p;
		pq.push(p); pq.push(p); pq.pop();
	}
	for (int i = 0; i < N; ++i) {
		ans += pq.top();
		pq.pop();
	}
	cout << ans << "\n";
}