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

const int MAXN = 3e5 + 10;

int n, a[MAXN], b[MAXN];
ll dp[MAXN][3];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i], memset(dp[i], 63, sizeof(dp[i]));

	for (int w = 0; w < 3; w++)
		dp[0][w] = 1ll*w*b[0];
	for (int i = 1; i < n; i++)
		for (int w = 0; w < 3; w++){
			ll temp = 1ll*w*b[i];
			for (int t = 0; t < 3; t++)
				if (a[i] + w != a[i-1] + t)
					dp[i][w] = min(dp[i][w], dp[i-1][t] + temp);
		}
	
	n--;
	cout << min({dp[n][0], dp[n][1], dp[n][2]}) << "\n";
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