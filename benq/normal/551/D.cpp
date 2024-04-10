/*#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

ll n,k,l,MOD;
ll ans = 1, a, b, a1, b1;

struct mat {
	ll d[2][2];
	mat() {
		d[0][0] = d[0][1] = d[1][0] = d[1][1] = 0;
	}
	void init(int a, int b, int c, int D) {
		d[0][0] = a, d[0][1] = b;
		d[1][0] = c, d[1][1] = D;
	}
	mat operator* (const mat& B) {
		mat C;
		F0R(i,2) F0R(j,2) F0R(k,2)
			C.d[i][j] = (C.d[i][j]+d[i][k]*B.d[k][j]) % MOD;
		return C;
	}
};

ll po(ll base, ll p) {
	ll ans = 1; 
	while (p) {
		if (p&1) ans = (ans*base) % MOD;
		base = (base*base) % MOD;
		p /= 2;
	}
	return ans;
}

mat mpo(mat base, ll p) {
	mat ans; ans.init(1,0,0,1);
	while (p) {
		if (p&1) ans = ans*base;
		base = base*base;
		p /= 2;
	}
	return ans;
}

void gen() {
	mat A; A.init(0,0,1,0);
	mat base; base.init(1,1,1,0);
	A = mpo(base,n+2)*A;
	a = A.d[0][0];
	b = (po(2,n)-a+MOD) % MOD;
}

// answer 472514342
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k >> l >> MOD;
	if (l < 63 && (1LL<<l) <= k) {
		cout << 0;
		return 0;
	}
	F0R(i,l) if (k & (1LL<<i)) b1++;
	else a1 ++;
	
	gen();
	F0R(i,a1) ans = (ans*a) % MOD;
	F0R(i,b1) ans = (ans*b) % MOD;
	cout << ans % MOD;
}