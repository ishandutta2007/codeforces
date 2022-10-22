#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <cassert>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

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

const int MAXN = 31;

int d, m;
int ans, dp[MAXN][MAXN];

void solve() {
	cin >> d >> m;
	if (m == 1) {
		cout << "0\n";
		return;
	}

	memset(dp, 0, sizeof(dp));
	ans = d % m;
	for (int i = 0; i < 30; i++)
		if ((1<<i) <= d) {
			dp[1][i] = 1;
			if (i)
				dp[1][i] = min<ll>(1ll<<i, d - (1<<i) + 1) % m;
		}

	for (int n = 2; n < MAXN; n++) 
		for (int cur = n-1; cur < 30; cur++) {
			for (int prev = 0; prev < cur; prev++)
				dp[n][cur] = (dp[n][cur] + max<ll>(0ll, min(1ll<<cur, d - (1ll<<cur) + 1)) * dp[n-1][prev]) % m;
			ans = (ans + dp[n][cur]) % m;
		}
	cout << ans << "\n";
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