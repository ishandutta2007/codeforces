#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef map<int,int> mii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = b-1; i >= a; i--)
#define F0Rd(i,a) for (int i = a-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;
double PI = 4*atan(1);

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n;
	ll ans = 1;
	vi crush(n+1);
	FOR(i,1,n+1) cin >> crush[i];
	FOR(i,1,n+1) {
		int c1 = 0, c2 = i;
		F0R(j,100) {
			c1++, c2 = crush[c2];
			if (c2 == i) break;
		}
		if (c2 != i) {
			cout << -1;
			return 0;
		}
		if (c1 % 2 == 1) ans = ans*c1/__gcd(ans,(ll)c1);
		else ans = ans*c1/2/__gcd(ans,(ll)c1/2);
	}
	cout << ans;
}