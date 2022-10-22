#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 998244353 ;
const int MAXN = 500 + 4;
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

const int MAXM = 1e6 + 5;
const int LOG = 20;

int n, m, a[LOG][MAXM], sv[MAXM];
vector<int> vec[MAXN];
int dp[MAXN][MAXN];
int go(int l, int r){
	int ln = r-l;
	if (ln <= 0) return 1;
	int mn = min(a[sv[ln]][l], a[sv[ln]][r-(1<<sv[ln])]);
	if (vec[mn][0] < l || vec[mn].back() >= r) return 0;

	int A = a[0][l], B = a[0][r-1];
	if (vec[A][0] < l || vec[B].back() >= r) return 0;
	if (dp[A][B] != -1) return dp[A][B];

	int tl = vec[mn][0], tr = vec[mn].back() + 1;
	if (tl < l || tr > r) return dp[A][B] = 0;

	dp[A][B] = 1;
	for (int i = 0; i+1 < vec[mn].size(); i++)
		dp[A][B] = 1ll*dp[A][B]*go(vec[mn][i]+1, vec[mn][i+1]) % MOD;

	int resL = go(l, tl), resR = go(tr, r);
	if (dp[A][B])
		for (int i = mn+1; i <= n; i++)
			if (vec[i][0] >= tr && vec[i].back() < r)
				add(resR, 1ll*go(tr, vec[i].back()+1)*go(vec[i].back()+1, r)%MOD);
	if (resR)
		for (int i = mn+1; i <= n; i++)
			if (vec[i].back() < tl && vec[i][0] >= l)
				add(resL, 1ll*go(l, vec[i][0])*go(vec[i][0], tl)%MOD);

	return dp[A][B] = 1ll*dp[A][B]*resL%MOD*resR%MOD;
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> a[0][i], vec[a[0][i]].push_back(i);
	for (int w = 1; w < LOG; w++)
		for (int l = 0; l < m; l++)
			if (l + (1<<w-1) >= m)
				a[w][l] = a[w-1][l];
			else
				a[w][l] = min(a[w-1][l], a[w-1][l+(1<<w-1)]);

	sv[1] = 0;
	for (int i = 2; i < MAXM; i++){
		sv[i] = sv[i-1];
		while ((1<<sv[i]+1) < i) sv[i]++;
		assert((1<<sv[i]) <= i);
	}

	memset(dp, -1, sizeof(dp));
	go(0, m);
	cout << dp[a[0][0]][a[0][m-1]] << "\n";
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