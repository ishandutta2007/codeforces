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

int n,k,z;
ll adj[40];

void clique(ll x, int sz) {
    if (x == 0) {
        z = max(z,sz);
        return;
    }
    while (x) {
        if (__builtin_popcountll(x)+sz <= z) return;
        ll i = __builtin_ffsll(x)-1;
        x ^= (1LL<<i);
        clique(x&adj[i],sz+1);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k;
	F0R(i,n) F0R(j,n) {
	    int z; cin >> z;
	    if (z) adj[i] ^= (1LL<<j);
	}
	clique((1LL<<n)-1,0);
	cout << fixed << setprecision(9) << (double)k*k*(z-1)/(2*z);
}