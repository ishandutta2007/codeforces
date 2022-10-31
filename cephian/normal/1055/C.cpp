#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll l, r, t;
	ll L, R, T;
	cin >> l >> r >> t;
	cin >> L >> R >> T;
	if(T > t) {
		swap(l, L);
		swap(r, R);
		swap(t, T);
	}

	ll g = gcd(T, t);
	ll k = ceil(double(l-L) / g);

	ll ans = min(R+k*g, r) - max(L+k*g, l)+1;

	--k;
	ans = max(ans, min(R+k*g, r) - max(L+k*g, l)+1);

	if(ans < 0) ans = 0;

	cout << ans << "\n";
}