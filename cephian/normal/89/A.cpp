#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n,m,k;
ll dim = 0x7fffffffffffffff;

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m >> k;
	if(n%2 == 0) {
		cout << "0\n";
		return 0;
	}
	for(int i = 0; i < n; ++i) {
		ll t;
		cin >> t;
		if(i&1) continue;
		dim = min(dim, t);
	}
	cout << min(dim, k*(m/((n+1)/2))) << "\n";
	return 0;
}