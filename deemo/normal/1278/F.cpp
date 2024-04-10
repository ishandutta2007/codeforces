#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 998244353;//XXX
const int C = 26;//XXX

void add(int &x, int y){
	x += y;
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
}

int fix(int x){
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
	return x;
}

int pw(int a, int b){
	int ret = 1;
	while (b){
		if (b & 1)
			ret = 1ll*ret*a%MOD;
		b >>= 1;
		a = 1ll*a*a%MOD;
	}
	return ret;
}

const int MAXK = 5e3 + 10;

int n, m, k, p, q;
int dp[MAXK][MAXK];

void solve() {
	cin >> n >> m >> k;
	p = pw(m, MOD-2);
	q = 1ll*(m-1)*p % MOD;
	dp[0][0] = 1;
	for (int i = 1; i <= k; i++)
		for (int j = 0; j < i; j++){
			add(dp[i][j], 1ll*dp[i-1][j]*j%MOD);
			add(dp[i][j+1], 1ll*dp[i-1][j]*(n-j)%MOD);
		}

	int ans = 0;
	for (int i = 1; i <= k && i <= n; i++)
		add(ans, 1ll*dp[k][i]*pw(p, i)%MOD);
	cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	//cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}