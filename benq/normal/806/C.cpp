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

int n, co[50], left1[50], cur=0;

bool ok (int sz) {
    if (sz>co[0]) return 0;
    
    ll temp = 0, cnum = sz, tot = sz, lef = co[0]-sz;
    
    while (cnum) {
        if (co[temp+1] >= cnum) {
            lef += (co[temp+1]-cnum);
            lef += left1[temp+1];
            tot += cnum;
            temp++;
        } else {
            ll dif = min(lef,cnum-co[temp+1]);
            tot += dif; lef -= dif;
            tot += co[temp+1];
            cnum = co[temp+1];
            lef += left1[temp+1];
            temp++;
        }
    }
    if (tot != n) return 0;
    return 1;
}

void ins(ll num) {
    ll num1 = num, c = 0;
    bool z = 1;
    while (num1 > 1) {
        if (num1 & 1) z = 0;
        num1 /= 2;
        c++;
    }
    if (z) co[c] ++;
    else left1[c] ++;
}

int main() {
    cin >> n;
    F0R(i,n) {
        ll x; cin >> x;
        ins(x);
    }
	FOR(i,1,n+1) if (ok(i)) {
	    cur ++;
	    cout << i << " ";
	}
	if (cur == 0) cout << -1;
}