#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

const int N = 500005;
int n;
ll a[N];
string s;

ll mx(int st, int e, int c) {
	ll k = 0;
	for(int i = 0; i < n; ++i)
		k += (s[i] == 'B')*a[i];
	ll ans = k;
	for(int i = st; i != e; i += c) {
		if(s[i] == 'B') k -= a[i];
		else {
			k += a[i];
			ans = max(ans, k);
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> a[i];
	cin >> s;
	cout << max(mx(0, n, 1),mx(n-1,-1,-1)) << "\n";
	return 0;
}