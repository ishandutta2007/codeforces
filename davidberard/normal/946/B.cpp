#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	ll a, b;
	cin >> a >> b;

	while(true) {
		if(a == 0 || b == 0) break;
		else if(a >= 2*b) {
			ll mult = (a/b)/2;
			a -= mult*2*b;
		} else if( b >= 2*a ) {
			ll mult = (b/a)/2;
			b -= mult*2*a;
		} else {
			break;
		}
	}
	cout << a << " " << b << endl;

	return 0;
}