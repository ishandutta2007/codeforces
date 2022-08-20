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

ll n, totaljobs=0, ans=0;
vector<ll> m, asdf;

int main() {
	cin >> n;
	F0R(i,n) {
		ll a;
		cin >> a;
		m.pb(a);
		totaljobs += a;
	}
	
	sort(m.begin(),m.end());
	ll low = totaljobs/n, rem = totaljobs % n;
	FOR(i,rem,n) asdf.pb(low);
	F0R(i,rem) asdf.pb(low+1);
	F0R(i,n) ans += abs(asdf[i]-m[i]);
	ans /= 2;
	cout << ans;
	return 0;
}