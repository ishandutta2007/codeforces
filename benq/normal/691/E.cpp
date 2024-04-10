#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define F0R(i, a) for (long long i=0; i<a; i++)
 
ll n,k, a[100], **m,**p, MOD = 1000000007;

ll** make() {
	ll **res = new ll*[n];
	F0R(i,n) {
		res[i] = new ll[n];
		F0R(j,n) res[i][j] = 0;
	}
	return res;
}

ll** mult (ll** x, ll ** y) {
	ll **ans = make();
	F0R(i,n) F0R(j,n) F0R(k,n) ans[i][j] = (ans[i][j]+x[i][k]*y[k][j]) % MOD;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k;
	p = make(), m = make();
	F0R(i,n) cin >> a[i];
	F0R(i,n) F0R(j,n) if (__builtin_popcountll(a[i]^a[j]) % 3 == 0) p[i][j] = 1;
	F0R(i,n) m[i][i] = 1;

	F0R(i,60) {
		if (((k-1) & ((ll)1<<i)) != (ll)0) m = mult(m,p);
		p = mult(p,p);
	}
	
	ll ans = 0;
	F0R(i,n) F0R(j,n) ans = (ans+m[i][j]) % MOD;
	cout << ans;
}