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

int n,A,B,k,f;
map<string,int> val;
vector<pair<string,string>> trip;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> A >> B >> k >> f;
	F0R(i,n) {
	    string a, b, c; cin >> a >> b; 
	    if (a < b) c = a+" "+b;
	    else c = b+" "+a;
	    if (i && a == trip[i-1].s) val[c] += B;
	    else val[c] += A;
	    trip.pb({a,b});
	}
	vector<pair<int,string>> bes;
	for (auto a: val) bes.pb({a.s,a.f});
	sort(bes.begin(),bes.end()); reverse(bes.begin(),bes.end());
	ll ans = 0;
	F0R(i,bes.size()) {
	    if (i < k) ans += min(f,bes[i].f);
	    else ans += bes[i].f;
	}
	cout << ans;
}

// read!
// ll vs. int!