/*#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
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

map<int,int> num;
vector<pair<ll,ll>> z;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll n; cin >> n;
	vi a(n); F0R(i,n) cin >> a[i];
	sort(a.begin(),a.end());
	F0R(i,a.size()) if (a[i] <= a[2]) num[a[i]] ++;
	
	for (auto a: num) z.pb(a);
	if (num.size() == 1) {
		ll x = z[0].s;
		cout << x*(x-1)*(x-2)/6;
	} else if (num.size() == 2) {
		if (z[0].s == 1) cout << z[1].s*(z[1].s-1)/2;
		else if (z[0].s == 2) cout << z[1].s;
	} else if (z.size() == 3) {
		cout << z[2].s;
	}
}