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
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const int MX = 200001;

int n;
vi a;
ll ans = 0;

ll po (ll b, ll p) {
    return !p?1:po(b*b%MOD,p/2)*(p&1?b:1)%MOD;
}

ll inv (ll b) { return po(b,MOD-2); }
    
void solve(int lo, int val) {
    ans += val*inv(n-1-lo);
    ans %= MOD;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n; a.resize(n);
	F0R(i,n) cin >> a[i];
	sort(all(a));
	int lo = -1;
	F0R(i,n) {
	    while (a[lo+1] < a[i]) lo ++;
	    solve(lo,a[i]);
	}
	ans = (ans-a[n-1]+MOD)%MOD;
	FOR(i,1,n+1) ans = ans*i % MOD;
	cout << ans;
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!