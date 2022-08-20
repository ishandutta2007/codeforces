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
	ll d,k,a,b,t; cin >> d >> k >> a >> b >> t;
	if (b <= a) {
		cout << d*b;
		return 0;
	}
	if (k >= d) {
		cout << d*a;
		return 0;
	}
	// drive then ditch
	ll ans = k*a+b*(d-k);
	// drive all the way
	ans = min(ans,((d-1)/k)*t+d*a);
	
	ll T = d/k;
	// drive almost all the day then walk
	ans = min(ans,T*k*a+(T-1)*t+b*(d-k*T));
	cout << ans;
	return 0;
}