#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	#define ll long long 
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += (ll) i * (n - i);
	}
	ans += n;
	cout << ans;
	return 0;
}