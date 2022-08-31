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
	ll n, ans = 0; cin >> n;
	vi a;
	unordered_map<ll,ll> k;
		
	F0R(i,n) {
		int x; cin >> x;
		a.pb(x);
		k[x] ++;
	}
	
	ll po = 1;
	F0R(i,30) {
		po *= 2;
		F0R(j,n) {
			if (po>a[j]) ans += k[po-a[j]];
			if (2*a[j] == po) ans --;
		}
	}
	cout << ans/2;
	return 0;
}