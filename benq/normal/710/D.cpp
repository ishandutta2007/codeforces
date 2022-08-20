#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair <int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
 
const int MOD = 1000000007;
double PI = 4*atan(1);

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll a1,b1,a2,b2,L,R; cin >> a1 >> b1 >> a2 >> b2 >> L >> R;
	L = max(L,max(b1,b2));
	if (L>R) {
		cout << 0;
		return 0;
	}
	if (a1<a2) swap(a1,a2),swap(b1,b2);
	// correct
	
	ll gcd = __gcd(a1,a2);
	ll lcm = a1*a2/gcd;
	if (lcm > (R-L)) {
		ll ans = 0;
		for (ll i = (ll)((L-b1+a1-1)/a1)*a1+b1; i <= R; i += a1) {
			if ((i-b2) % a2 == 0) ans++;
		}
		cout << ans;
	} else {
		ll sol = -1;
		b1 %= lcm; if (b1<0) b1 += lcm;
		b2 %= lcm; if (b2<0) b2 += lcm;
		for (ll i = b1; i < lcm+b1; i += a1) {
			if ((i-b2) % a2 == 0) {
				sol = i % lcm;
				break;
			}
		}
		if (sol == -1) {
			cout << 0;
			return 0;
		}
		ll a = abs(-L/lcm);
		L += (a+2)*lcm;
		R += (a+2)*lcm;
		ll lo = (L-sol-1)/lcm;
		ll hi = (R-sol)/lcm;
		cout << (hi-lo);
	}
}