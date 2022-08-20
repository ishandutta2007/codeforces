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

int n,a1,a2,a3,a4,dp[1001][1<<12];
string g[4];

int ans = MOD;

int get(int c) {
    int t = 0;
    F0R(i,3) if (c+i < n) F0R(j,4) 
        if (g[j][c+i] == '.') t ^= 1<<(j+4*i);
    return t;
}

void process(int col, int cur) {
    if (dp[col][cur] == MOD) return;
    if (col == n) {
        ans = min(ans,dp[col][cur]);
        return;
    }
    if ((cur&15) == 15) {
        dp[col+1][(cur/16)|get(col+1)] = min(dp[col+1][(cur/16)|get(col+1)],dp[col][cur]);
        return;
    }
    
    // test 1 
    F0R(i,4) {
        int CUR = cur | (1<<i);
        dp[col][CUR] = min(dp[col][CUR],dp[col][cur]+a1);
    }
    
    // test 2 
    F0R(i,3) {
        int CUR = cur;
        F0R(j,2) F0R(k,2) CUR |= 1<<(i+j+4*k);
        dp[col][CUR] = min(dp[col][CUR],dp[col][cur]+a2);
    }
    
    // test 3 
    F0R(i,2) {
        int CUR = cur;
        F0R(j,3) F0R(k,3) CUR |= 1<<(i+j+4*k);
        dp[col][CUR] = min(dp[col][CUR],dp[col][cur]+a3);
    }
    
    // test 4
    if (col+4 >= n) ans = min(ans,dp[col][cur]+a4);
    else dp[col+4][get(col+4)] = min(dp[col+4][get(col+4)],dp[col][cur]+a4);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> a1 >> a2 >> a3 >> a4;
	F0R(i,4) cin >> g[i];
	
	F0R(i,n+1) F0R(j,1<<12) dp[i][j] = MOD;
	dp[0][get(0)] = 0;
	F0R(i,n+1) F0R(j,1<<12) process(i,j);
	cout << ans;
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!