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
const ll INF = (ll)MOD*MOD;

int n;
queue<ll> todo[8];
ll k;
vi p1, p2;
vector<ll> P1, P2;

ll lo = 1, hi = INF;

vector<ll> gen(vi p) {
    F0R(i,sz(p)) while (sz(todo[i])) todo[i].pop();
	todo[0].push(1);
	
	if (sz(p) == 0) return {1};
	vector<ll> ret;
	while (1) {
	    pair<ll,int> mn = {INF,0};
	    
	    F0R(j,sz(p)) if (sz(todo[j])) mn = min(mn,{todo[j].front(),j});
	    if (mn.f == INF) break;
	    ret.pb(mn.f); todo[mn.s].pop();
	    FOR(j,mn.s,sz(p)) if (mn.f <= INF/p[j]) todo[j].push(mn.f*p[j]);
	}
	return ret;
}

ll get(ll cur) {
    ll mx = sz(P2)-1, ret = 0;
    F0R(i,sz(P1)) {
        while (mx >= 0 && P1[i] > cur/P2[mx]) mx --;
        ret += mx+1;
    }
    return ret;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	F0R(i,n) {
	    int x; cin >> x;
	    if (i&1) p1.pb(x);
	    else p2.pb(x);
	}
	cin >> k;
	P1 = gen(p1);
	P2 = gen(p2);
	while (lo < hi) {
	    ll mid = (lo+hi)/2;
	    if (get(mid) >= k) hi = mid;
	    else lo = mid+1;
	}
	cout << lo;
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!