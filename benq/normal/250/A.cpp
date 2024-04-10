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
	int n, ans = 0, cnum = 0, cneg = 0; cin >> n;
	
	vi z;
	F0R(i,n) {
	    int x; cin >> x;
	    if (x >= 0) cnum++;
	    else {
	        if (cneg == 2) {
	            z.pb(cnum); ans ++;
	            cnum = 1, cneg = 1;
	        } else {
	            cnum ++, cneg++;
	        }
	    }
	}
	if (cnum != 0) z.pb(cnum);
	cout << z.size() << "\n";
	for (int i: z) cout << i << " ";
}