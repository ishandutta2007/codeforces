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

int n,t,ind;
string g;

void rou(int pos) {
    if (g[pos-1] == '.') {
        g[pos-2] ++;
        g.erase(g.begin()+pos-1,g.end());
    } else {
        g[pos-1] ++;
        g.erase(g.begin()+pos,g.end());
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> t;
	cin >> g;
	F0R(i,g.length()) if (g[i] == '.') {
	    FOR(j,i+1,g.length()) if (t > 0 && g[j] >= '5') {
	        rou(j), t--;
	        for (int j1 = j-1; j1 > i; --j1) if (j1 < (int)g.length() && t > 0 && g[j1] >= '5') {
	            rou(j1), t--;
	        }
	        break;
	    }
	    break;
	}
	FORd(i,1,g.length()) {
	    if (g[i] == ':') g[i] = '0', g[i-1] ++;
	}
	if (g[0] == ':') g = "10"+g.substr(1,g.length()-1);
	cout << g;
}

// read!
// ll vs. int!