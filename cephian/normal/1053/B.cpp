#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int bits(ll a) {
	int p = 0;
	while(a) {
		p += 1;
		a ^= a&-a;
	}
	return p;
}

const int N = 3 * 1e5 + 5;
int bsum[N] = {};
int seen[N][2] = {};

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	
	seen[0][0] = 1;
	for(int i = 1; i <= n; ++i) {
		ll a;
		cin >> a;
		bsum[i] = bsum[i-1] + bits(a);
		const bool b = bsum[i]&1;
		seen[i][b] = seen[i-1][b] + 1;
		seen[i][!b] = seen[i-1][!b];
	}

	const int LOOK = 62;
	ll ans = 0;
	for(int i = 1; i <= n; ++i) {
		int mx = 0;
		int sum = 0;
		for(int l = 1; l <= 62 && l <= i; ++l) {
			const int val = bsum[i-l+1]-bsum[i-l];
			mx = max(mx, val);
			sum += val;
			if(sum%2 == 0 && (bsum[i] - bsum[i-l]) >= 2 * mx) {
				++ans;
			}
		}
		if(i-LOOK-1 >= 0)
		ans += seen[i-LOOK-1][bsum[i]&1];
	}
	cout << ans << "\n";
}