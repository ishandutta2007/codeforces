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

int n, k, n4, n2, n1, l4, l2, l1;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k; 
	l4 = n, l2 = 2*n;
	
	F0R(i,k) {
	    int a; cin >> a;
	    n4 += a/4;
	    a %= 4;
	    if (a >= 2) n2++;
	    if (a % 2 == 1) n1++;
	} 
	if (n4 > l4) {
	    n4 -= l4; l4 = 0;
	    l2 -= 2*n4; n4 = 0;
	} else {
	    l4 -= n4; n4 = 0;
	}
	if (n2 > l2) {
	    n2 -= l2; l2 = 0;
	    while (n2 > n1) n2 --, n1 += 2;
	    if (n2+(n1-n2+1)/2 <= l4) cout << "YES";
	    else cout << "NO";
	} else {
	    l2 -= n2; n2 = 0;
	    // n1, l4, l2 left
	    if (2*l4+l2 >= n1) cout << "YES";
	    else cout << "NO";
	}
}