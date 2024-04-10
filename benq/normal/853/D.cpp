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
const int MX = 300005;

int n, a[MX], nex[MX][3], sum[MX];
int one[MX];
int maxdis = 0;

void init() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	FOR(i,1,n+1) {
	    cin >> a[i];
	    sum[i] = sum[i-1]+a[i];
	    one[i] = one[i-1];
	    if (a[i] == 1000) one[i] = i;
	}
	nex[n+1][1] = nex[n+1][2] = n+1;
	
	FORd(i,1,n+1) {
	    nex[i][1] = nex[i+1][1];
	    nex[i][2] = nex[i+1][2];
	    if (a[i] == 1000) nex[i][1] = i;
	    else if (a[i] == 2000) nex[i][2] = i;
	}
}

int main() {
    init();
	F0R(i,n+1) {
	    // let's pay cash for the first i 
	    maxdis = max(maxdis,min(sum[n]-sum[i],sum[i]/10));
	    if (one[i]) {
	        int cbal = sum[one[i]-1]/10, cdis = 0;
	        int z = min(cbal,1000);
	        cbal -= z, cdis += z;
	        cbal += (sum[i]-sum[one[i]])/10;
	        z = min(cbal,sum[n]-sum[i]);
	        cdis += z;
	        maxdis = max(maxdis,cdis);
	    }
	    
	    // then consider nex[i+1][1]
	    int co = nex[i+1][1];
	    if (co != n+1 && co != i+1) {
	        int cbal = sum[i]/10, cdis = 0;
	        int z = min(cbal,sum[co-1]-sum[i]);
	        cbal -= z, cdis += z;
	        cbal += 100;
	        z = min(cbal,sum[n]-sum[co]);
	        cdis += z;
	        maxdis = max(maxdis,cdis);
	    }
	    
	    // nex[i+1][2]
	    co = nex[i+1][2];
	    if (co != n+1 && co != i+1) {
	        int cbal = sum[i]/10, cdis = 0;
	        int z = min(cbal,sum[co-1]-sum[i]);
	        cbal -= z, cdis += z;
	        cbal += 200;
	        z = min(cbal,sum[n]-sum[co]);
	        cdis += z;
	        maxdis = max(maxdis,cdis);
	    }
	}
	cout << sum[n]-maxdis;
}

// read!
// ll vs. int!