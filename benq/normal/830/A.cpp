#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
int n,k,p,a[2000],b[2000];

bool ok(ll mid) {
    int co = 0;
    F0R(i,n) {
        while (abs(a[i]-b[co])+abs(b[co]-p) > mid && co < k) co++;
        if (co == k) return 0;
        co++;
    }
    return 1;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k >> p;
	
	F0R(i,n) cin >> a[i];
	F0R(i,k) cin >> b[i];
	
	sort(a,a+n);
	sort(b,b+k);
	
	ll mn = 0, mx = 2000000000;
	while (mn<mx) {
	    ll mid = (mn+mx)/2;
	    if (ok(mid)) mx = mid;
	    else mn = mid+1;
	}
	
	cout << mn;
}

// read!
// ll vs. int!