#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> pii;
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

ll n, k, m;
int lo = 0, hi = 0, sz = 0; // f is type, s is number
vector<pii> a, V1, V2;
deque<pii> a1;

void adjust() {
	// keep cutting a while possible
	while (a1.size() > 1) {
	    if (a1.front().f != a1.back().f) break;
	    if (a1.front().s+a1.back().s < k) break;
	    
	    lo += k-a1.back().s;
	    hi -= a1.back().s;
	    V1.pb({a1.front().f,k-a1.back().s});
	    V2.pb(a1.back());
	    a1.front().s -= (k-a1.back().s);
	    a1.pop_back();
	    
	    if (a1.front().s == 0) a1.pop_front();
	}
}

void ok(vector<pii>& v) {
    while (1) {
        while (v.size() > 1 && v[v.size()-2].f == v[v.size()-1].f) {
            v[v.size()-2].s += v[v.size()-1].s;
            v.pop_back();
        }
        if (v.size() == 0) break;
        while (v.size()) {
            v[v.size()-1].s %= k;
            if (v.back().s == 0) v.pop_back();
            else return;
        }
    }
}

void solve() {
    vector<pii> tmp;
    F0R(i,V1.size()) {
        tmp.pb(V1[i]);
        ok(tmp);
    }
    tmp.pb({a1.front().f,a1.front().s*m});
    ok(tmp);
    F0Rd(i,V2.size()) {
        tmp.pb(V2[i]);
        ok(tmp);
    }
    
    ok(tmp);
    ll ans = 0;
    F0R(i,tmp.size()) ans += tmp[i].s;
    // for (auto a: tmp) cout << a.f << " " << a.s << "\n";
    cout << ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k >> m;
	F0R(i,n) {
	    int x; cin >> x; 
	    if (a.size() && a.back().f == x) a.back().s ++;
	    else a.pb({x,1});
	    if (a.size() && a.back().s == k) a.pop_back();
	}
	
	for (auto x: a) {
	    sz += x.s;
	    a1.pb(x);
	}
	
	hi = sz-1; 
	
	adjust();
	if (a1.size() > 1) cout << (hi-lo+1)*(m-1)+sz;
	else if (a1.size() == 1) solve();
	else cout << 0;
}

// read!
// ll vs. int!