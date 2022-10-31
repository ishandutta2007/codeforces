#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

vector<ll> odd;

int main() {
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	ll l = 0;
	ll ans = 0;
	while(n--) {
		ll a;
		cin >> a;
		if(a&1) {
			odd.push_back(a);
		} else ans += a;
	}
	sort(odd.begin(), odd.end());
	reverse(odd.begin(), odd.end());
	for(int i = 1; i < odd.size(); i += 2)
		ans += odd[i] + odd[i-1];
	cout << ans << "\n";
}