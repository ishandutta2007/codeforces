#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>
 
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORd(i, a, b) for (int i=a-1; i>=b; i--)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define b begin
#define e end
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;
 
ll t,n,sum, findp;
 
void findpow(ll x) {
	findp=0;
	while (x>0) {
		findp++;
		x >>= 1;
	}
	findp--;
}
 
ll asdf(ll x) {
	return x*(x+1)/2;
}
 
int main() {
	cin >> t;
	F0R(i,t) {
		cin >> n;
		// cout << asdf(n);
 
		sum = asdf(n);
		findpow(n);
		sum -= 2*((ll)pow(2,findp+1)-1);
		cout << sum << endl;
	}
	return 0;
}