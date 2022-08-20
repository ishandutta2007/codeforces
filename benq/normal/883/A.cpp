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

ll n,a,m,d,t[100000];
ll mx = -1e18, nex = 0, lst, ans;
ll cur;

ll numleft() {
    ll c = n-(mx+d)/a;
    c = min(c,n);
    c = max(c,0LL);
    return c;
}

void process(ll x) {
    if (mx+d >= x) return;
    ll nex = max(((mx+d)/a+1)*a,a); ans ++;
    if (nex > n*a || nex > x) {
        mx = x;
        return;
    }
    if (nex+d >= x) {
        mx = nex;
        return;
    }
    ll lst = min((x/a)*a,n*a); // first one <= it 
    ans += (lst-nex)/a/cur;
    nex += ((lst-nex)/a/cur)*cur*a;
    mx = nex;
    
    if (mx+d >= x) return;
    mx = x; ans++;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m >> a >> d;
	F0R(i,m) {
	    cin >> t[i];
	    //t[i] = 999999999999900000LL+i;
	}
	cur = d/a+1;
	lst = max(a*n,t[m-1]);
	
	F0R(i,m) {
	    process(t[i]);
	    //cout << ans << " " << mx << "\n";
	}
	ans += (numleft()+cur-1)/cur;
	cout << ans;
}

// read!
// ll vs. int!