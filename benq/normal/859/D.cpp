#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long double ld;
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

int N, beat[64][64];
ld prob[7][64][64], dp[7][64][64];

void solve(int rou, int num) {
    F0R(i,1<<N) F0R(j,1<<N) {
        prob[rou][num][i] += beat[i][j]*prob[rou-1][2*num][i]*prob[rou-1][2*num+1][j]/100;
        prob[rou][num][j] += beat[j][i]*prob[rou-1][2*num][i]*prob[rou-1][2*num+1][j]/100;
    }
    F0R(i,1<<N) {
        // predict i to be the winner
        ld a = (1<<(rou-1))*prob[rou][num][i]+dp[rou-1][2*num][i]; // come from left bracket 
        ld mx = 0; F0R(j,1<<N) mx = max(mx,dp[rou-1][2*num+1][j]);
        a += mx;
        
        ld b = (1<<(rou-1))*prob[rou][num][i]+dp[rou-1][2*num+1][i]; // come from right bracket 
        mx = 0; F0R(j,1<<N) mx = max(mx,dp[rou-1][2*num][j]);
        b += mx;
        
        dp[rou][num][i] = max(a,b);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> N;
	F0R(i,1<<N) F0R(j,1<<N) cin >> beat[i][j];
	F0R(i,1<<N) prob[0][i][i] = 1;
	
	ld ans = 0;
	FOR(i,1,N+1) F0R(j,1<<(N-i)) solve(i,j);
	F0R(i,1<<N) ans = max(ans,dp[N][0][i]);
	cout << fixed << setprecision(11) << ans;
}

// read!
// ll vs. int!