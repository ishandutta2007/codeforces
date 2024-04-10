#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;

int main() {
	ll n, K, ans = 0;
	cin >> n >> K;
	if (K <= 2 || K >= 2 * n)
		return puts("0"), 0;
	
	if (K <= n + 1) {
		ans = (K - 1) / 2;
	}
	else {
		ans = (n - (K - n) + 1) / 2;
	}
	cout << ans;
	
	return 0;
}