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

char tmp[250][250];
ll dp[1<<15][2], cur[16][1<<15][2][2];
int n,m;
ll ans = 0;

void add(int col, int row) {
    F0R(a,1<<n) F0R(b,2) F0R(c,2) {
        int t = cur[row][a][b][c];
        if (tmp[row][col] == 'x') {
            int a1 = a;
            if (a1&(1<<row)) a1 ^= (1<<row);
            cur[row+1][a1][0][c] = (cur[row+1][a1][0][c]+t) % MOD;
        } else {
            int a1 = a|(1<<row);
            cur[row+1][a1][1][c] = (cur[row+1][a1][1][c]+t) % MOD;

            if ((a&(1<<row)) || b) cur[row+1][a][b][c] = (cur[row+1][a][b][c]+t) % MOD;
            else if (c == 0) cur[row+1][a][0][1] = (cur[row+1][a][0][1]+t) % MOD;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	if (n > m) {
	    F0R(i,n) F0R(j,m) cin >> tmp[j][i];
	    swap(n,m);
	} else F0R(i,n) F0R(j,m) cin >> tmp[i][j];
	
	dp[0][0] = 1;
	F0R(i,m) {
	    memset(cur,0,sizeof cur);
	    F0R(a,1<<n) F0R(b,2) cur[0][a][0][b] = dp[a][b];
	    F0R(j,n) add(i,j);
	    
	    F0R(a,1<<n) F0R(c,2) dp[a][c] = (cur[n][a][0][c]+cur[n][a][1][c]) % MOD;
	}
	F0R(i,1<<n) F0R(j,2) ans = (ans+dp[i][j]) % MOD;
	cout << ans;
}

// read!
// ll vs. int!