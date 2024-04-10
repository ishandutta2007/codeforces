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
	ll n; cin >> n;
	// k*(m^2-n^2), k*(m^2+n^2), k*2mn
	// m^2-n^2
	if (n == 1 || n == 2) {
		cout << -1;
		return 0;
	}
	if (n % 4 == 0) {
		cout << 3*n/4 << " " << 5*n/4;
	} else {
		// 1,2
		if (n % 2 == 0) {
		    n /= 2;
			cout << (n*n-1) << " " << (n*n+1);
		} else {
			cout << (n*n-1)/2 << " " << (n*n+1)/2;
		}
	}
	return 0;
}