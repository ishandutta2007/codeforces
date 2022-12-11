#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	ll p, q, t;
	cin >> n >> p >> q >> t;
	ll TM[n], Tm[n];
	ll SM[n], Sm[n];
	ll a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];
	SM[n - 1] = Sm[n - 1] = a[n - 1];
	TM[0] = Tm[0] = a[0];
	for (int i = n - 2; i >= 0; --i) {
		Sm[i] = min(Sm[i + 1], a[i]);
		SM[i] = max(SM[i + 1], a[i]);
	}
	ll res = -3e18 - 1;
	for (int i = 0; i < n; ++i) {
		if (i) {
		Tm[i] = min(Tm[i - 1], a[i]);
		TM[i] = max(TM[i - 1], a[i]);
	}
		ll s = a[i]*q;
		if (p > 0) s += p*TM[i];
		else s += p*Tm[i];
		if (t > 0) s += t*SM[i];
		else s += t*Sm[i];
		res = max(res, s);
	}
	cout << res << endl;
}