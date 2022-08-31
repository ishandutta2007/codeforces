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

ll n, num[4001], bell[4001][4001], fac[4001], faci[4001];


ll inv(ll k) {
	k = fac[k];
	ll power = MOD-2, p = k, ans=1;
	while (power) {
		if (power & 1) ans = ans*p % MOD;
		p = p*p % MOD, power /= 2;
	}
	return ans;
}
 
ll combo(ll a, ll b) {
	ll ans = fac[a]*faci[b] % MOD;
	return (ans*faci[a-b]) % MOD;
}
 
int main() {
	fac[0] = 1;
	
	F0R(i,4000) fac[i+1] = (i+1)*fac[i] % MOD;
	F0R(i,4001) faci[i] = inv(i);
	bell[0][0] = 1;
	
	FOR(i,1,4001) {
		bell[i][0] = bell[i-1][i-1];
		FOR(j,1,i+1) bell[i][j] = bell[i][j-1]+bell[i-1][j-1] % MOD;
	}
	
	num[1] = 1;
	
	FOR(i,2,4001) {
		num[i] = (num[i-1]+bell[i-1][i-1]) % MOD;
		FOR(j,1,i) num[i] = (num[i]+combo(i-1,j)*num[i-j-1]) % MOD;
	}
	
	cin >> n;
	cout << num[n];
	return 0;
}