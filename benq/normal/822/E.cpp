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

int dp[100005][31]; 
ll hsh1[100005], hsh2[100005], inv[100005];
// key: at most nth character from lena, # pieces
// value: max len from noora
int n,m,x;
string s,t;

ll get1(int st, int len) {
    ll ans = hsh1[st+len]-hsh1[st];
    ans = (ans*inv[st]) % MOD;
    return (ans+MOD) % MOD;
}

ll get2(int st, int len) {
    ll ans = hsh2[st+len]-hsh2[st];
    ans = (ans*inv[st]) % MOD;
    return (ans+MOD) % MOD;
}

int binsearch(int x, int y) {
    int lo = 0, hi = min(s.length()-x,t.length()-y);
    while (lo<hi) {
        int mid = (lo+hi+1)/2;
        if (get1(x,mid) == get2(y,mid)) lo = mid;
        else hi = mid-1;
    }
    return lo;
}

void genhsh() {
    ll po = 1;
    F0R(i,s.length()) {
        hsh1[i+1] = (hsh1[i]+po*(s[i]-'a'+1)) % MOD;
        po = (po*241) % MOD;
    }
    po = 1;
    F0R(i,t.length()) {
        hsh2[i+1] = (hsh2[i]+po*(t[i]-'a'+1)) % MOD;
        po = (po*241) % MOD;
    }
    inv[0] = 1;
    FOR(i,1,100005) inv[i] = (406639007*inv[i-1]) % MOD;
}

int main() {
    cin >> n >> s >> m >> t >> x;
    genhsh();
    
    F0R(i,s.length()+1) F0R(j,x+1) {
        if (i) dp[i][j] = max(dp[i][j],dp[i-1][j]);
        if (j) dp[i][j] = max(dp[i][j],dp[i][j-1]);
        
        if (i == s.length() || j == x) continue;
        if (dp[i][j] == m) continue;
        if (s[i] != t[dp[i][j]]) continue;
        
        int z = binsearch(i,dp[i][j]); 
        dp[i+z][j+1] = max(dp[i+z][j+1],dp[i][j]+z);
    }
    
    if (dp[s.length()][x] == m) cout << "YES";
    else cout << "NO";
}