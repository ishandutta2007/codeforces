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
 
const int MOD = 1000000009;
double PI = 4*atan(1);

ll rem(ll base, int po) {
	ll ans = 1;
	while (po) {
		if (po&1) ans = (ans*base)%MOD;
		base = (base*base) %MOD;
		po /= 2;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,m,k; cin >> n >> m >> k;
	if (m <= (n-n/k)) cout << m;
	else {
		int minstreak = m-(n-n/k);
		int extra = m-minstreak*k;
		// cout << minstreak << " " << extra << "\n";
		ll ans = ((rem(2,minstreak)-1)*k*2+extra) % MOD;
		while (ans<0) ans += MOD;
		cout << ans;
	}
	return 0;
}