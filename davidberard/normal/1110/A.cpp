#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	ll b, k;
	cin >> b >> k;
	vector<ll> a(k);
	for(auto& x : a) cin >> x;
	if(b%2 == 0) {
		cout << (a[k-1]%2 ? "odd" : "even") << endl;
		return 0;
	}
	ll sum = 0;
	for(auto& x : a) {
		sum += x;
	}
	cout << (sum%2 ? "odd" : "even") << endl;
	return 0;
}