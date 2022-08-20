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

int t1, t20, t21;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n, ans = 0; cin >> n >> t1 >> t20;
	
	F0R(i,n) {
	    int t; cin >> t;
	    if (t == 1) {
	        if (t1 > 0) t1--;
	        else if (t20 > 0) t20 --, t21 ++;
	        else if (t21 > 0) t21 --;
	        else ans++;
	    } else {
	        if (t20 > 0) t20--;
	        else ans += 2;
	    }
	}
	cout << ans;
}