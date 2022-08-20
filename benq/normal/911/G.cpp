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

int n, q;
int a[200001], ans[1<<19][101];
vector<array<int,3>> todo[200002];

void recalc(int ind) {
    FOR(i,1,101) ans[ind][i] = ans[2*ind+1][ans[2*ind][i]];
}

void upd(array<int,3> b) {
    int ind = b[0]+(1<<18);
    ans[ind][b[1]] = b[2];
    for (ind /= 2; ind > 0; ind /= 2) recalc(ind);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n; 
	FOR(i,1,n+1) cin >> a[i];
	
	F0R(i,1<<19) FOR(j,1,101) ans[i][j] = j;
	cin >> q;
	F0R(i,q) {
	    int l,r,x,y; cin >> l >> r >> x >> y;
	    todo[l].pb({i,x,y});
	    todo[r+1].pb({i,x,x});
	}
	FOR(i,1,n+1) {
	    for (auto b: todo[i]) upd(b);
	    cout << ans[1][a[i]] << " ";
	}
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!