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

int q;
ll b,l,r,ans=0; 
ll dp[11][11][61]; // base, how many appear odd # of times, # of digits
ll po[11][61];
ll combo[61][61];

void gen() {
    combo[0][0] = 1;
    FOR(i,1,61) F0R(j,i+1) {
        combo[i][j] = combo[i-1][j];
        if (j) combo[i][j] += combo[i-1][j-1];
    } 
    
    F0R(i,11) dp[i][0][0] = 1;
    FOR(b,1,11) F0R(j,b+1) FOR(k,1,61) {
        FOR(k1,0,k+1) {
            if (k1 % 2 == 0 && j == 0) {
                dp[b][j][k] += combo[k][k1]*dp[b-1][j][k-k1];
            } else if (k1 % 2 == 1 && j > 0) {
                dp[b][j][k] += combo[k][k1]*dp[b-1][j-1][k-k1];
            }
        }
    }
    
	FOR(i,1,11) {
	    po[i][0] = 1;
	    FOR(j,1,61) po[i][j] = i*po[i][j-1];
	}
}

ll solve(int num, int clen, ll l) {
    ll ret = 0;
    while (1) {
        if (clen == 0) {
            ret += (num == 0);
            break;
        }
        ll t = po[b][clen-1];
        int hi = l/t, c0 = 0, c1 = 0;
        if ((hi+1)*t == l+1) hi++;
        F0R(i,hi) {
            if (num&(1<<i)) c0++;
            else c1++;
        }
        
        int z = __builtin_popcount(num);
        ret += c0*dp[b][z-1][clen-1];
        ret += c1*dp[b][z+1][clen-1];
        
        if (hi*t > l) break;
        num ^= (1<<hi), clen --, l %= t;
    }
    return ret;
}

int getlen(ll x) {
    int z = 0;
    while (x) x /= b, z++;
    return z;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	gen();
	cin >> q;
	F0R(i,q) {
	    cin >> b >> l >> r; 
	    ans = 0;
	    FOR(j,getlen(l),getlen(r)+1) if (j % 2 == 0) 
	        ans += solve(0,j,min(r,po[b][j]-1))-solve(0,j,max(l,po[b][j-1])-1); 
	    cout << ans << "\n";
	}
}

// read!
// ll vs. int!