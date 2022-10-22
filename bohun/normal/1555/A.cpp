#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
typedef long long ll;
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		cout << 5 * max(6ll, n + n % 2) / 2 << "\n";
	}
	return 0;
}