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

int main() {
	ll ans = 1,n;
	cin >> n;
	F0R(i,n) ans = 3*ans % MOD;
	if (n % 2 == 0) ans += 3;
	else ans -= 3;
	ans *= (MOD+1)/4;
	ans %= MOD;
	if (ans < 0) ans += MOD;
	cout << ans;
	return 0;
}