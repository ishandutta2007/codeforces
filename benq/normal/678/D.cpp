#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define b begin()
#define e end()
#define lb lower_bound
#define ub upper_bound
 
ll MOD = 1000000007;
double PI = 4*atan(1);

ll m(ll base, ll po) {
	ll p = base, ans = 1;
	while (po) {
		if (po & 1 == 1) ans = (ans*p) % MOD;
		p = (p*p) % MOD, po /= 2;
	}
	return ans;
}

ll inv(ll k) {
	return m(k,MOD-2);
}

int main() {
	ios_base::sync_with_stdio(0);
	ll A,B,n,x, ans = 0, ans1;
	cin >> A >> B >> n >> x;
	ans = (m(A,n)*x) % MOD;
	if (A != 1) ans1 = (m(A,n)-1)*inv(A-1) % MOD;
	else ans1 = n % MOD;
	ans1 = (ans1*B) % MOD;
	ans = (ans+ans1) % MOD;
	cout << ans;
	return 0;
}