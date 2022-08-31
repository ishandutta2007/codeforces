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

int n,x,y; 

bool ask(vi k) {
    if (k.size() == 0) return 0;
    cout << "? " << k.size() << " ";
    for (int i: k) cout << i << " ";
    cout << endl;

    int t; cin >> t;
    if (k.size() % 2 == 1) {
        if (t == x) return 0;
    } else {
        if (t == 0) return 0;
    }
    return 1;
}

bool test(int z) {
    int mod = 1<<z;
    vi tmp;
    FOR(i,1,n+1) if (i % (2*mod) < mod) tmp.pb(i);
    if (ask(tmp)) return 1;
    return 0;
}

vi cand;

bool ok (int mid) {
    vi tmp;
    F0R(i,mid+1) tmp.pb(cand[i]);
    if (ask(tmp)) return 1;
    return 0;
}

int main() {
	cin >> n >> x >> y;
	int z = 0;
	F0R(i,10) if (test(i)) z |= (1<<i);
	
	FOR(i,1,n+1) {
	    int i1 = i^z;
	    if (i < i1 && i1 <= n) cand.pb(i);
	}
	int lo = 0, hi = cand.size()-1; // first one such that
	while (lo<hi) {
	    int mid = (lo+hi)/2;
	    if (ok(mid)) hi = mid;
	    else lo = mid+1;
	}
	cout << "! " << cand[lo] << " " << (cand[lo]^z) << endl;
}