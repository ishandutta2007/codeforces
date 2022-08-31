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

int n, a[200000];
ll ans = 0;
set<int> cur;
int nex[200000][30], pre[200000][30];
vector<pii> todo;

void init() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	F0R(i,n) {
	    cin >> a[i];
	    todo.pb({a[i],i});
	    F0R(j,30) {
	        if (i) pre[i][j] = pre[i-1][j];
	        else pre[i][j] = -1;
	    }
	    F0R(j,30) if (a[i]&(1<<j)) pre[i][j] = i;
	}
	F0Rd(i,n) {
	    F0R(j,30) {
	        if (i != n-1) nex[i][j] = nex[i+1][j];
	        else nex[i][j] = n;
	    }
	    F0R(j,30) if (a[i]&(1<<j)) nex[i][j] = i;
	    
	}
	cur.insert(-1), cur.insert(n);
	sort(todo.begin(),todo.end());    
	reverse(todo.begin(),todo.end());
}

int main() {
    init();
    for (auto a: todo) {
        ll l = *prev(cur.lb(a.s)), r = *cur.lb(a.s);
        ans += (a.s-l)*(r-a.s);
        
        ll mn = l+1, mx = r-1;
        F0R(j,30) if (!(a.f&(1<<j))) {
            mn = max((int)mn,pre[a.s][j]+1);
            mx = min((int)mx,nex[a.s][j]-1);
        }
        ans -= (a.s-mn+1)*(mx-a.s+1);
        cur.insert(a.s);
    }
    cout << ans;
}

// read!
// ll vs. int!