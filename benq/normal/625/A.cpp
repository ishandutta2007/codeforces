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
// #define b begin
#define e end
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;

ll n,a,b,c,ans,v;
	
int main() {
	cin >> n >> a >> b >> c;
	if (a>b) {
		if (n<b) cout << 0;
		else cout << (ll)((n-c)/(b-c));
	} else {
		if (n<b) {
			cout << (ll)(n/a);
			return 0;
		}
		ll x = (ll)(n/a);
		ll y = (ll)((n-c)/(b-c));
		y += (ll)((n-y*(b-c))/a);
		cout << max(x,y);
	}
	return 0;
}