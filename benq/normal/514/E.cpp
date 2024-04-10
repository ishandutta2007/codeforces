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

ll n,x, cnt[101], dp[101];
ll init[101], init1[101];

struct mat {
	ll d[101][101];	
	mat () {
		F0R(i,101) F0R(j,101) d[i][j] = 0;
	}
	mat operator*(const mat& B) {
		mat C;
		F0R(i,101) F0R(j,101) F0R(k,101) 
			C.d[i][j] = (C.d[i][j]+d[i][k]*B.d[k][j]) % MOD;
		return C;
	}
};

mat po(mat b, ll p) {
	mat ans; F0R(i,101) ans.d[i][i] = 1;
	while (p) {
		if (p&1) ans = ans*b;
		b = b*b;
		p /= 2;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> x;
	F0R(i,n) {
		int y; cin >> y;
		cnt[y] ++;
	}
	dp[0] = 1;
	FOR(i,1,101) FOR(j,1,i+1) dp[i] = (dp[i]+cnt[j]*dp[i-j]) % MOD;
	if (x < 100) {
		F0R(j,x) dp[x] += dp[j];
		dp[x] %= MOD;
		cout << dp[x];
		return 0;
	}
	F0R(i,100) init[i] = dp[i+1];
	F0R(i,101) init[100] += dp[i];
	
	mat trans;
	F0R(i,100) {
		if (i) trans.d[i][i-1] = 1;
		trans.d[i][99] = trans.d[i][100] = cnt[100-i];
	}
	trans.d[100][100] = 1;
	trans = po(trans,x-100);
	F0R(i,101) F0R(j,101) init1[j] = (init1[j]+init[i]*trans.d[i][j]) % MOD;
	cout << init1[100];
}