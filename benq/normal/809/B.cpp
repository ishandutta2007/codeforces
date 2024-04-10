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

vector<ll> x;
ll sum = 0, po2[400000];

int fin(int lo, int hi) { // after you know where one is ...
    if (lo == hi) return lo;
    
    int a = (lo+hi)/2;
    int b = a+1;
    cout << "1 " << a << " " << b << endl;
    string r; cin >> r;
    
    if (r == "TAK") return fin(lo,a);
    else return fin(b,hi);
} // correct

int main() {
	int n,k; cin >> n >> k;
	int z = fin(1,n);
	int lo = 1, hi = n;
	
	while (lo < z) {
	    int mid = (lo+z-1)/2;
	    cout << "1 " << mid << " " << mid+1 << endl;
	    string r; cin >> r;
	    if (r == "TAK") {
	        int z1 = fin(lo,mid);
	        cout << "2 " << z << " " << z1 << endl;
	        return 0;
	    } else lo = mid+1;
	}
	
	while (hi > z) {
	    int mid = (z+hi)/2+1;
	    cout << "1 " << mid << " " << mid-1 << endl;
	    string r; cin >> r;
	    if (r == "TAK") {
	        int z1 = fin(mid,hi);
	        cout << "2 " << z << " " << z1 << endl;
	        return 0;
	    } else hi = mid-1;
	}
}