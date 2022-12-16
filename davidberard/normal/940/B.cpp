#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n, k, A, B;
	cin >> n;
	cin >> k;
	cin >> A;
	cin >> B;
	int x = n;
	ll cost = 0;
	if(k == 1) {
		cout << (ll) (x-1)*A << endl;
		return 0;
	}
	while(x != 1) {
		if(x%k != 0) {
			cost += (ll) min(x-(x/k)*k, x-1)*A;
			x = max((x/k)*k, 1);
		}
		if(x != 1) {
			ll diff = x-(x/k);
			cost += min(diff*A, (ll) B);
			x/=k;
		}
	}
	cout << cost << endl;
	return 0;
}