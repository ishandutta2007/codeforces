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

ll m, MOD = 1000000007, n = 1, primes[200001], p, power=1, ans=1;
ll tempmod = 2*MOD-2;

bool is_square = true;

void computeans() {
	ll currentmult = n;
	ll x = power;
	while (x) {
		if (x & 1 == 1) ans = (ans*currentmult) % MOD;
		currentmult = (currentmult*currentmult) % MOD;
		x /= 2;
	}
	cout << ans;
}

int main() {
	cin >> m;
	F0R(i,m) {
		cin >> p;
		primes[p] ++;
		n = n*p % MOD;
	}
	
	F0R(i,200001) {
		power = power*(primes[i]+1) % tempmod;
		if (primes[i] % 2 != 0) is_square = false;
	}
	
	if (is_square) {
		n = 1;
		F0R(i,200001) {
			F0R(j,primes[i]/2) n = (n*i) % MOD;
		}
		computeans();
		return 0;
	}
	power /= 2;
	computeans();
	return 0;
}