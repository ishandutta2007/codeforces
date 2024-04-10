#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORd(i, a, b) for (int i=a-1; i>=b; i--)
#define F0Rd(i, a) for (int i=a-1; i>=0; i--)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define b begin
#define e end
#define lb lower_bound
#define ub upper_bound
#define sz size
 
ll MOD = 1000000007;
double PI = 4*atan(1);

vector<ll> h;
ll ans = 0, n,m, last;

ll inv(int a) {
    ll ans = 1, mult = a, ind = MOD-2;
    while (ind > 0) {
    	if (ind % 2 == 1) {
    		ans = ans*mult % MOD;
    	}
    	mult = (mult*mult) % MOD;
    	ind /= 2;
    }
    return ans;
}

void dp(int k) {
	if (k >= 2) {
		if (h[k-2] <= h[k-1]) {
			if (h[k-1] <= h[k]) last = last*(h[k-1]-1) % MOD;
			else {
				if (h[k-2]<=h[k]) {
					last -= (h[k-1]-h[k]);
					if (last < 0) last += MOD;
					last = last*(h[k]-1) % MOD;
				} else {
					last -= (h[k-1]-h[k-2]);
					if (last < 0) last += MOD;
					last = last*(h[k]-1) % MOD;
					last = last*(h[k]-1) % MOD;
					last = last*inv(h[k-2]-1) % MOD;
				}
			}
		} else {
			if (h[k-1] <= h[k]) last = last*(h[k-1]-1) % MOD;
			else {
				last = last*(h[k]-1) % MOD;
				last = last*(h[k]-1) % MOD;
				last = last*inv(h[k-1]-1) % MOD;
			}
		}
	} else if (k == 1) {
		last = 0;
		if (h[0] <= h[1]) {
			last += (h[0]-1)*(h[0]-1) % MOD;
		} else {
			last += (h[1]-1)*(h[1]-1) % MOD;
		}
	}
	last = last+(h[k]-1) % MOD;
	ans = (ans+last) % MOD;
	// cout << last << " " << ans << endl;
}

int main() {
	cin >> n;
	F0R(i,n) {
		scanf("%I64d",&m);
		h.pb(m);
	}
	F0R(i,n) dp(i);
	cout << ans;
	return 0;
}