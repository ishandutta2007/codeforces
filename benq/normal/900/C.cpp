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

int n, p[100000], ok[100000], co[100000];
set<pii> a;
pii bes = {-MOD,-MOD};

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	F0R(i,n) cin >> p[i];
	F0R(i,n) {
	    if (!sz(a) || a.rbegin()->f < p[i]) {
	        ok[i] = -1;
	    } else if (sz(a) < 2 || next(a.rbegin())->f < p[i]) {
	        co[a.rbegin()->s] ++;
	    }
	    a.insert({p[i],i});
	}
	F0R(i,n) bes = max(bes,mp(co[i]+ok[i],-p[i]));
	cout << -bes.s;
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!