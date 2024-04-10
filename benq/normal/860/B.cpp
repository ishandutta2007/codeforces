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

int n;
string mn[70000];
vector<pair<string,int>> z;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	F0R(i,n) mn[i] = "9999999999";
	F0R(i,n) {
	    vector<string> cur;
	    string s; cin >> s;
	    F0R(j,9) FOR(k,1,10-j) cur.pb(s.substr(j,k));
	    sort(cur.begin(),cur.end());
	    cur.erase(unique(cur.begin(),cur.end()),cur.end());
	    for (auto a: cur) z.pb({a,i});
	}
	sort(z.begin(),z.end());
	for (int i = 0; i < z.size();) {
	    int i1 = i;
	    while (i < z.size() && z[i1].f == z[i].f) i++;
	    if (i1+1 == i) {
	        if (mn[z[i1].s].length() > z[i1].f.length()) mn[z[i1].s] = z[i1].f;
	    } 
	}
	F0R(i,n) cout << mn[i] << "\n";
}

// read!
// ll vs. int!