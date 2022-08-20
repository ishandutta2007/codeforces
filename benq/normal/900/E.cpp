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
const int MX = 100001;

int n, len;
int a[MX], b[MX], q[MX];
pii dp[MX], bes[MX];
string s;

int getq(int x) {
    if (x < 0) return 0;
    return q[x];
}

int geta(int x) {
    if (x < 0) return 0;
    return a[x];
}

int getb(int x) {
    if (x < 0) return 0;
    return b[x];
}

int ok(int ind) {
    if (ind+len > n) return -1;
    
    int t = ind+len-1, t1 = t-1;
    if ((t-ind) % 2 != 0) swap(t1,t);
    if (geta(t)-geta(ind-2)+getq(t)-getq(ind-2) != (t-ind)/2+1) return -1;
    if (getb(t1)-getb(ind-1)+getq(t1)-getq(ind-1) != (t1-ind-1)/2+1) return -1;
    
    return getq(t)-getq(ind-2)+getq(t1)-getq(ind-1);
}

void gen(int ind) {
    int t = ok(ind);
    if (t != -1) {
        pii x = (ind+len < MX) ? bes[ind+len] : mp(0,0);
        x.f ++; x.s -= t;
        dp[ind] = x;
    }
    bes[ind] = max(dp[ind], bes[ind+1]);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> s >> len;
	F0R(i,n) {
	    if (s[i] == 'a') a[i] = 1;
	    else if (s[i] == 'b') b[i] = 1;
	    else q[i] = 1;
	    
	    if (i > 1) {
	        a[i] += a[i-2];
	        b[i] += b[i-2];
	        q[i] += q[i-2];
	    }
	}
	F0Rd(i,s.length()) gen(i);
	cout << -bes[0].s;
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!