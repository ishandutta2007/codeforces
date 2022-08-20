#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

vector<pair<ll,ll>> device;
ll n,p,s=0,s1=0; 

double test(double tim) {
	double ans = 0;
	for (auto a: device) {
		if ((double)a.s/a.f < tim) ans += ((double)a.f-(double)a.s/tim);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> p;
	F0R(i,n) {
		ll a,b; cin >> a >> b; // use, store
		s += a; s1 += b;
		device.pb(mp(a,b));
	}
	if (p >= s) {
		cout << -1;
		return 0;
	}
	double low = 0, high = 1e12;
	while (high-low > 0.000000001) {
		double mid = (low+high)/2;
		double temp = test(mid);
		if (temp <= p) low = mid;
		else high = mid;
	}
	cout << fixed << setprecision(9) << (low+high)/2;
}