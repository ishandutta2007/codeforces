#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll A[50505], B[50505], C[50505];
deque<ll> D;
ll n, x;

void tc() {
	ll i, j;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> A[i]; A[i] += A[i - 1];
	}
	cin >> x;
	for (i = 1; i <= n; i++) {
		B[i] = A[i] - i * x;
	}
	C[0] = 0; C[1] = 1; D.clear();
	for (i = 2, j = 0; i <= n; i++) {
		for (; !D.empty() && B[D.back()] <= B[i - 2]; D.pop_back());
		D.push_back(i - 2);
		for (; !D.empty() && B[D.front()] > B[i]; D.pop_front()) {
			j = D.front() + 1;
		}
		if (j == 0) C[i] = i - j;
		else C[i] = max(C[i - 1], C[j - 1] + i - j);
	}
	cout << C[n] << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

	cin >> t;

	for (; t--; ) {
		tc();
	}

	return 0;
}