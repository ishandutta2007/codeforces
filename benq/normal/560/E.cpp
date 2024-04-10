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
 
const int MOD = 1000000007;
double PI = 4*atan(1);

ll h,w,n, fac[200001], dp1[2000], done[2000], final = 0;
pii pairs[2000];

ll inv(int k) {
	k = fac[k];
	ll power = MOD-2, p = k, ans=1;
	while (power) {
		if (power & 1) ans = ans*p % MOD;
		p = p*p % MOD, power /= 2;
	}
	return ans;
}

ll combo(ll a, ll b) {
	ll x = a+b;
	ll ans = fac[x]*inv(a) % MOD;
	return (ans*inv(b)) % MOD;
}

ll dp (int k) {
	if (done[k]) return dp1[k];
	ll x = combo(pairs[k].f-1,pairs[k].s-1);
	F0R(i,n) if (i != k && pairs[i].f <= pairs[k].f && pairs[i].s <= pairs[k].s) {
		x = (x-combo(pairs[k].f-pairs[i].f, pairs[k].s-pairs[i].s)*dp(i)) % MOD;
	}
	done[k] = 1;
	dp1[k] = x;
	return x;
}

int main() {
	fac[0] = 1;
	F0R(i,200000) fac[i+1] = fac[i]*(i+1) % MOD;
	cin >> h >> w >> n;
	F0R(i,n) cin >> pairs[i].f >> pairs[i].s;
	final = combo(h-1,w-1);
	// cout << final << endl;
	F0R(i,n) final = (final-combo(h-pairs[i].f,w-pairs[i].s)*dp(i)) % MOD;
	if (final < 0) final += MOD;
	cout << final;
	return 0;
}