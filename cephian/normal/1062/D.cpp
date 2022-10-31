#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	ll ans = 0;
	for(int i = 2; i <= n; ++i) {
		if(abs(i) <= 1) continue;
		for(int k = 2; k <= n; ++k) {
			if(n < i*k) break;
			ans += 4*k;
		}
	}
	cout << ans << "\n";

}