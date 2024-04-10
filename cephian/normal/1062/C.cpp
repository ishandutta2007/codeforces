#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef long long ll;

const ll M = 1e9+7;

ll pw(ll a, ll b) {
	if(b == 0) return 1;
	if(b % 2 == 1) return a * pw(a, b-1) % M;
	ll t = pw(a, b/2);
	return t * t % M;
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> p(n+1);
	string s;
	cin >> s;
	for(int i = 1; i <= n; ++i) {
		p[i] = s[i-1] == '1';
		p[i] += p[i-1];
	}
	for(int i = 1; i <= q; ++i) {
		int l, r;
		cin >> l >> r;
		ll len = r-l+1;
		ll ones = p[r] - p[l-1];
		ll zeroes = len - ones;
		ll ans = pw(2, zeroes) * (pw(2, ones)-1) % M;
		cout << ans << "\n";
	}
}