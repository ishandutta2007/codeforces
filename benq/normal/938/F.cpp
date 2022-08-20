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
const int MX = 200001;

string s, ans;
int rec[5001];
char trans[5001];
int dp[5001][5001], mx;

// cpos, cused 
// cpos+1, cused (add one character)
// cpos+(1<<i), cused+(1<<i)
// just ignore all of those which are smaller than current min for that size

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	int t = 0;
	while ((1<<(t+1)) <= sz(s)) t ++;
	
	FOR(i,1,sz(s)+1) trans[i] = '{';
	
	int cti = 0;
	F0R(i,sz(s)) F0R(j,min(i+1,1<<t)) {
	    if (rec[i-j] != dp[i][j] || i-j > mx) continue;
	    F0R(k,t) if ((i+(1<<k) <= sz(s)) && !(j&(1<<k))) dp[i+(1<<k)][j^(1<<k)] = rec[i-j];
	    
	    if (s[i] < trans[i-j+1]) {
	        FOR(k,i-j+2,mx+1) trans[k] = '{';
	        mx = i-j+1;
	        cti ++;
	        trans[i-j+1] = s[i];
	        rec[i-j+1] = cti;
	    } 
	    
	    if (s[i] == trans[i-j+1]) dp[i+1][j] = rec[i-j+1];
	}
	
	FOR(i,1,sz(s)-(1<<t)+2) cout << trans[i];
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!