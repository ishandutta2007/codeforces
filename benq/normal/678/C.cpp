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
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;
double PI = 4*atan(1);

ll gcd(ll x, ll y) {
	if (y == 0) return x;
	return gcd(y,x%y);
}

int main() {
	ios_base::sync_with_stdio(0);
	ll n,a,b,p,q,s=0;
	cin >> n >> a >> b >> p >> q;
	ll lcm = a*b/gcd(a,b);
	ll x1 = n/a, x2 = n/b, x3 = n/lcm;
	x1 -= x3, x2 -= x3;
	s += x1*p+x2*q+x3*max(p,q);
	cout << s;
	return 0;
}