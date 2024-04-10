#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

vector<ll> ed,vt;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	for(ll a = 0; a*(a+1)/2 <= 2e9; ++a) {
		ed.pb(a*(a-1));
		vt.pb(a*(a+1)/2);
	}
	int T;
	cin >> T;
	while(T--) {
		ll n;
		cin >> n;
		if(n == 1) {
			cout << "0\n";
			continue;
		} else if(n == 2) {
			cout << "1\n";
			continue;
		}
		int lo = 0, hi = vt.size();
		while(hi-lo>1) {
			int md = (lo+hi)/2;
			if(vt[md] <= n)
				lo = md;
			else hi = md;
		}
		ll ans = ed[lo];
		ll lf = n-vt[lo];
		if(lf == 1) ++ans;
		else if(lf > 1) ans += 2*(lf-1);
		cout << ans << "\n";
	}
}