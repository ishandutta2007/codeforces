#include<bits/stdc++.h>
#define rep(i,a,b) for (ll i=(a); i<=(b); i++)
#define per(i,a,b) for (ll i=(a); i>=(b); i--)
#define p first
#define v second
using namespace std;
typedef long long ll;
 
const int maxn = 200005;
map<ll,ll>::iterator it;
map<ll,ll> f;
ll n, m, ans;
 
int main() {
	cin >> n >> m;
	f[m-1] = 0;
	rep (i, 2, n) {
		cin >> m;
		it = f.lower_bound(m);
		while (it != f.end()) {
			f[it->p%m] = max(f[it->p%m], it->v + 
							 (i - 1) * (it->p - it->p % m));
			f[m-1] = max(f[m-1], it->v +
						 (i - 1) * ((it->p + 1) / m * m - m));
			f.erase(it++);
		}
	}
	for (auto x : f) 
		ans = max(ans, n * x.p + x.v);
	cout << ans << endl;
	return 0;
}