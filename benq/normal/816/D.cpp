/*#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

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

const int MOD = 1000000007;
double PI = 4*atan(1);

int n; 
ll fac[200001], invfac[200001];

ll inv(ll a) {
	ll po = MOD-2, ans = 1;
	while (po) {
		if (po & 1) ans = (ans*a) % MOD;
		a = (a*a) % MOD;
		po /= 2;
	}
	return ans;
}

void gen() {
	fac[0] = invfac[0] = 1;
	FOR(i,1,200001) {
		fac[i] = (i*fac[i-1]) % MOD;
		invfac[i] = inv(fac[i]);
		// cout << fac[i] << " " << invfac[i] << "\n";
	}
}

ll combo(int a, int b) {
	ll ret = (fac[a+b]*invfac[a]) % MOD;
	ret = (ret*invfac[b]) % MOD;
	return ret;
}

ll get(vector<ll> x) {
	int num = x.size()-1;
	ll ans = 0;
	F0R(i,x.size()) {
		ans = (ans+combo(num-i,i)*x[i]) % MOD;
	}
	return ans;
}

int main() {
	gen();
	vector<ll> a;
	cin >> n; a.resize(n);
	F0R(i,n) cin >> a[i];
	
	if (n % 4 == 1) {
		vector<ll> x;
		F0R(i,n) if (i % 2 == 0) x.pb(a[i]);
		cout << get(x);
	} else if (n % 4 == 2) {
		vector<ll> x1, x2;
		F0R(i,n) if (i % 2 == 0) x1.pb(a[i]);
		else x2.pb(a[i]);
		
		ll ans = (get(x1)+get(x2)) % MOD;
		cout << ans;
		return 0;
	} else if (n % 4 == 3) {
		vector<ll> x1, x2, x3;
		F0R(i,n-1) if (i % 2 == 0) x1.pb(a[i]);
			else x2.pb(a[i]);
		FOR(i,1,n) if (i % 2 == 0) x3.pb(a[i]);
		ll ans = get(x1)+2*get(x2)-get(x3);
		ans = (ans+MOD) % MOD;
		cout << ans;
		return 0;
	} else {
		vector<ll> x1, x2;
		F0R(i,n) if (i % 2 == 0) x1.pb(a[i]);
		else x2.pb(a[i]);
		
		ll ans = get(x1)-get(x2);
		ans = (ans+MOD) % MOD;
		cout << ans;
	}
}