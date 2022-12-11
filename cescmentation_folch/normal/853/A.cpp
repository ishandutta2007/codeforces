#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<vi> vvi;

int main() {
	int k,n;
	cin >> n >> k;
	vi V(n);
	vi R(n);
	for (int i = 0; i < n; ++i) cin >> V[i];
	priority_queue<pi> Q;
	ll S  = 0;
	ll res = 0;
	for (int i = 0; i < n +k; ++i) {
		if (i < n) {
			S += V[i];
			Q.push(pi(V[i], i));
		}
		if (i >= k) {
			S -= Q.top().first;
			R[Q.top().second] = i + 1;
			Q.pop();
		}
		res += S;
	}
	cout << res << '\n';
	for (int i = 0; i < n; ++i) {
		if (i) cout << ' ';
		cout << R[i];
	}
	cout << '\n';
}