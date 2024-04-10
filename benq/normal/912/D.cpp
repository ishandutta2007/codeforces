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
const int MX = 100000;

int n,m,r,k;
set<pii> done;
set<pair<ll,pii>> todo;
long double ans = 0;
vector<ll> a, b;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m >> r >> k;
	
	FOR(i,1,n+1) {
	    int lo = max(1,i-r+1), hi = min(n-r+1,i);
	    a.pb(hi-lo+1);
	}
	FOR(i,1,m+1) {
	    int lo = max(1,i-r+1), hi = min(m-r+1,i);
	    b.pb(hi-lo+1);
	}
	sort(a.rbegin(),a.rend());
	sort(b.rbegin(),b.rend());
	todo.insert({a[0]*b[0],{0,0}});
	
	int co = 0;
	while (co < k){
	    auto x = *prev(todo.end()); todo.erase(prev(todo.end()));
	    if (done.count(x.s)) continue;
	    done.insert(x.s);
	    
	    co++;
	    ans += x.f;
	    if (x.s.f < sz(a)-1) {
	        todo.insert({a[x.s.f+1]*b[x.s.s],{x.s.f+1,x.s.s}});
	    }
	    if (x.s.s < sz(b)-1) {
	        todo.insert({a[x.s.f]*b[x.s.s+1],{x.s.f,x.s.s+1}});
	    }
	}
	ans /= n-r+1;
	ans /= m-r+1;
	cout << fixed << setprecision(10) << ans;
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!