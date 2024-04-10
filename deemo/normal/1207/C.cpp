#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 1e9 + 7;//XXX
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

const int MAXN = 2e5 + 10;

int n, A, B;
string s;
ll dp[MAXN][2];

void solve() {
	cin >> n >> A >> B;
	cin >> s;
	memset(dp, 63, sizeof(dp));
	dp[0][0] = B;
	for (int i = 1; i <= n; i++){
		if (s[i-1] != '1' && (i == n || s[i] != '1')){
			dp[i][0] = min(dp[i-1][0] + A + B, dp[i-1][1] + A*2 + B);
		}
		if (i != n)
			dp[i][1] = min(dp[i-1][0] + A*2 + B*2, dp[i-1][1] + A + B*2);
		//cout << dp[i][0] << "   " << dp[i][1] << endl;
	}
	cout << min(dp[n][0], dp[n][1]) << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}