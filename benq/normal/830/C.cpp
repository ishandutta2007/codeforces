/*#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

int n, a[100]; 
ll k, ans = 1;

bool ok(int d) {
    ll cur = 0;
    F0R(i,n) cur += ((a[i]+d-1)/d)*(ll)d-a[i];
    if (cur > k) return 0;
    return 1;
}

vector<pair<ll,pii>> tocheck; 
ll cval = 0, lastd = 0, slope = 0; 
int o;
// initialize cval correctly

void check(pair<ll,pii> t) {
    cval += slope*(t.f-lastd);
    
    if (t.s.s == 9999) o--;
    slope --, cval -= t.f, lastd = t.f; // fix this
    
    if (cval <= k && o == 0) ans = max(ans,t.f+(k-cval)/slope);
}

void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	F0R(i,n) cin >> a[i];
}

void solve() {
	F0R(i,n) FOR(j,1,10000) tocheck.pb({(a[i]+j-1)/j,{i,j}});
	sort(tocheck.begin(),tocheck.end());
	
	F0R(i,n) cval -= a[i];
	slope = 10000*n; o = n;
	
	F0R(i,tocheck.size()) check(tocheck[i]);
}

int main() {
    init();
	FOR(i,2,110000) if (ok(i)) ans = i;
	solve();
	cout << ans;
}