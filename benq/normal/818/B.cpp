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

set<int> lef;
int n,m, ans[101];

int main() {
	cin >> n >> m;
	FOR(i,1,n+1) lef.insert(i);
	
	vi leader(m);
	F0R(i,m) cin >> leader[i];
	F0R(i,m-1) {
		int dif = (leader[i+1]-leader[i]+n) % n;
		if (dif == 0) dif += n;
		if (ans[leader[i]] != 0) {
			if(ans[leader[i]] != dif) {
				cout << -1;
				return 0;
			} 
			continue;
		} else {
			if (lef.find(dif) == lef.end()) {
				cout << -1;
				return 0;
			}
			ans[leader[i]] = dif;
			lef.erase(dif);
		}
	}
	FOR(i,1,n+1) if (ans[i] == 0) {
		ans[i] = *lef.begin();
		lef.erase(lef.begin());
	}
	FOR(i,1,n+1) cout << ans[i] << " ";
}