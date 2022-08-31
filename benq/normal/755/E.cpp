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
	int n,k; cin >> n >> k;
	if (k>3 || k<2 || n<4 || (n == 4 && k == 2)) {
		cout << -1;
		return 0;
	}
	if (k == 2) {
		cout << n-1 << "\n";
		FOR(i,1,n) cout << i << " " << (i+1) << "\n";
		return 0;
	}
	ll ans = 3+(n-4)+(n-4);
	cout << ans << "\n";
	FOR(i,1,4) cout << i << " " << (i+1) << "\n";
	FOR(i,5,n+1) cout << 1 << " " << i << "\n";
	FOR(i,5,n+1) cout << 3 << " " << i << "\n";
}