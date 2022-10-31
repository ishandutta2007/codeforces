#include <iostream>

using namespace std;
typedef long long ll;

ll a,b,n;
ll ans[64];

bool bit(ll m, int b) {
	return (m&(1LL<<b)) > 0;
}

int solve(int d) {
	if(d == -1) return 0;
	if(bit(a,d) == bit(b,d)) {
		ans[d] = bit(a,d);
		return solve(d-1) + ans[d];
	}
	if(bit(b,d) < bit(a,d)) {
		ans[d] = 0;
		return solve(d-1);
	}
	int k = 1+solve(d-1);
	if(k > d) {
		ans[d] = 1;
		return k;
	}
	for(int i = 0; i < d; ++i)
		ans[i] = 1;
	return d;
}

int main() {
	cin >> n;
	for(int i = 0; i < n; ++i) {
		fill(ans,ans+64,0);
		cin >> a >> b;
		solve(63);
		ll q = 0;
		for(int i = 63; i >= 0; --i) {
			q *= 2;
			q += ans[i];
		}
		cout << q << "\n";
	}

}