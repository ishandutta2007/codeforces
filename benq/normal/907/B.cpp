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
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;

char g[9][9];
pii p, P;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	F0R(i,9) F0R(j,9) cin >> g[i][j];
	cin >> p.f >> p.s; p.f --, p.s --;
	P = {p.f%3, p.s%3};
	
	bool ok = 0;
	FOR(i,3*P.f,3*P.f+3) FOR(j,3*P.s,3*P.s+3) {
	    if (g[i][j] == '.') {
	        g[i][j] = '!';
	        ok = 1;
	    }
	}
	if (!ok) {
	    F0R(i,9) F0R(j,9) if (g[i][j] == '.') g[i][j] = '!';
	}
	F0R(i,9) {
	    F0R(j,9) {
	        cout << g[i][j];
	        if (j%3 == 2) cout << " ";
	    }
	    cout << "\n";
	    if (i%3 == 2) cout << "\n";
	}
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!