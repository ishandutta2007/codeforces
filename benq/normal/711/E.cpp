#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef map<int,int> mii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = b-1; i >= a; i--)
#define F0Rd(i,a) for (int i = a-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000003;
double PI = 4*atan(1);

ll po2(ll x) {
	if (x <= 1) return 0;
	return x/2+po2(x/2);
}

ll po(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans*a % MOD;
		a = a*a % MOD;
		b /= 2;
	}
	return ans;
}

ll inv(ll a) {
	return po(a, MOD-2);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll n,k; cin >> n >> k;
	if (k == 1) {
		cout << "0 1";
		return 0;
	}
	if (64-__builtin_clzll(k) > (n+1) || (64-__builtin_clzll(k) == (n+1) && k > pow(2,n))) {
		cout << "1 1";
		return 0;
	} 
	ll z = po(2,n);
	ll x = po(z,k-1), y = po2(k-1);
	if (k > MOD) {
		x = x*inv(po(2,y)) % MOD;
		cout << x << " " << x << "\n";
		return 0;
	}
	ll fac = 1;
	for (ll i = z-1; i >= z-k+1; --i) fac = fac*i % MOD;
	ll x1 = x-fac;
	while (x1<0) x1 += MOD;
	x1 = x1*inv(po(2,y)) % MOD;
	x = x*inv(po(2,y)) % MOD;
	cout << x1 << " " << x << "\n";
}