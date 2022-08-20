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

int n,m,s,d,a[200002];
int lst;
vi v;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m >> s >> d;
	FOR(i,1,n+1) cin >> a[i];
	sort(a+1,a+n+1);
	a[0] = -1;
	a[n+1] = m, lst = n;
	v.pb(lst);
	FORd(i,1,n+1) if (a[i]-a[i-1]-2 >= s && a[lst]-a[i] <= d-2) {
	    lst = i-1;
	    v.pb(lst);
	}
	reverse(v.begin(),v.end());
	if (v[0] != 0) {
	    cout << "IMPOSSIBLE";
	    return 0;
	}
	int cur = 0;
	for (int i: v) if (i != 0) {
	    cout << "RUN " << a[cur+1]-a[cur]-2 << "\n";
	    cout << "JUMP " << a[i]-a[cur+1]+2 << "\n";
	    cur = i;
	}
	if (a[n+1]-a[n]-1 > 0) cout << "RUN " << a[n+1]-a[n]-1;
}

// read!
// ll vs. int!