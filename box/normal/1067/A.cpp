// writer: piggydan
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using ordered_set=tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 998244353;
/*
ifstream fin("x.in");
ofstream fout("x.out");
#define cin fin
#define cout fout
*/

int DP[100005][3][205]; // [i][< = >][#]
int ar[100005];

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	iter(i, 1, n+1) cin >> ar[i];
	DP[0][1][1] = 1; iter(x, 2, 201) DP[0][1][x] = 0;
	int ans = 0;
	iter(i, 1, n+1) {
	    iter(x, 1, 201) {
	        DP[i][0][x] = DP[i][0][x-1];
	        rep(c, 3) DP[i][0][x] = (DP[i][0][x] + DP[i-1][c][x-1]) % MOD;
	    }
	    iter(x, 1, 201) rep(c, 3) DP[i][1][x] = (DP[i][1][x] + DP[i-1][c][x]) % MOD;
	    for(int x=200; x>=1; x--) {
	        DP[i][2][x] = DP[i][2][x+1];
	        rep(c, 2) DP[i][2][x] = (DP[i][2][x] + DP[i-1][1+c][x+1]) % MOD;
	    }
	    iter(x, 1, 201) {
	        if(ar[i] != -1 && ar[i] != x) rep(c, 3) DP[i][c][x] = 0;
	        if(i == n) rep(c, 2) ans = (ans + DP[i][1+c][x]) % MOD;
	    }
	}
	cout << ans << endl;
}