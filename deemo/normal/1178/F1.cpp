#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 998244353 ;
const int MAXN = 500 + 10;
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
/*
void plant(int v, int b, int e){
	if (e - b == 1){

		return;
	}

	int mid = b + e >> 1;
	plant(v<<1, b, mid);
}*/

int n, m, a[MAXN], pos[MAXN], mx[MAXN][MAXN];
int dp[MAXN][MAXN];
int go(int l, int r){
	if (r - l <= 1) return 1;
	if (dp[l][r] != -1) return dp[l][r];

	int x = mx[l][r];
	int p = pos[x];
	int tl = 0, tr = 0;
	for (int i = p; i < r; i++)
		add(tr, 1ll*go(p+1, i+1)*go(i+1, r)%MOD);
	for (int i = p; i >= l; i--)
		add(tl, 1ll*go(i, p)*go(l, i)%MOD);

	return dp[l][r] = 1ll*tl*tr%MOD;
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> a[i], pos[a[i]] = i;
	memset(mx, -1, sizeof(mx));
	for (int l = 0; l < m; l++){
		int cur = 1e9;
		for (int r = l; r < m; r++){
			cur = min(cur, a[r]);
			mx[l][r+1] = cur;
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << go(0, n) << "\n";
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