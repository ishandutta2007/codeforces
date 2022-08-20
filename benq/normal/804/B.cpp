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

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	string s; cin >> s;
	ll ans = 0;
	vi x,y;
	F0R(i,s.length()) if (s[i] == 'a') x.pb(i);
	FOR(i,s.length()-x.size(),s.length()) y.pb(i);
	ll po2 = 1;
	F0R(i,x.size()) {
		ans = (ans+(y[i]-x[i])*po2) % MOD;
		po2 = (2*po2) % MOD;
	}
	cout << ans;
}