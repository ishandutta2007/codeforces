#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> pii;
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

ll n;
ll ans = 0;
vector<pii> v;

ll get(string s) {
    ll a = 0;
    ll t = 0;
	for (char c: s) if (c == 's') a ++;
	else t += a;
    return t;
}

bool cmp(pii a, pii b) {
    return a.f*b.s > a.s*b.f;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	F0R(i,n) {
	    string s; cin >> s;
	    ans += get(s);
	    ll a = 0;
	    for (char c: s) if (c == 's') a ++;
	    v.pb({a,sz(s)-a});
	}
	sort(all(v),cmp);
	ll t = 0;
	F0R(i,sz(v)) {
	    ans += t*v[i].s;
	    t += v[i].f;
	}
	cout << ans;
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!