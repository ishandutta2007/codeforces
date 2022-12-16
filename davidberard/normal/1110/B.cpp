#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N, M, K;
	cin >> N >> M >> K;
	vector<int> b(N);
	for(auto& x : b) cin >> x;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	int lst = b[N-1];
	for(int i=N-2;i>=0;--i) {
		pq.emplace(lst-b[i], i);
		lst = b[i];
	}
	ll ans = N;
	for(int s = N;s>K;--s) {
		auto p = pq.top(); pq.pop();
		ans += p.first-1;
	}
	cout << ans << endl;
	
	return 0;
}