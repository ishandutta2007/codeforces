#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 998244353 ;
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

const int MAXN = 100 + 3;

int n, ans;
string s, dv[10];
int dp[MAXN][2][1<<4][1<<4][10][10];
int mod10[100], r10[100];

int mp[2][10];
int get(int a, int b){
	int mx = max(a, b);
	vector<int> vec[2];
	for (int i = 1; i*mx < 10; i++){
		vec[0].push_back(a*i);
		vec[1].push_back(b*i);
	}
	memset(mp, -1, sizeof(mp));
	for (int i = 0; i < vec[0].size(); i++)
		mp[0][vec[0][i]] = i, mp[1][vec[1][i]] = i;

	int sz[2] = {(int)vec[0].size(), (int)vec[1].size()};
	
	memset(dp, 0, sizeof(dp));
	dp[0][0][0][0][0][0] = 1;
	for (int i = 0; i < (int)dv[mx].size(); i++)
		for (int status = 0; status < 2; status++)
			for (int m0 = 0; m0 < (1<<sz[0]); m0++)
				for (int m1 = 0; m1 < (1<<sz[1]); m1++)
					for (int c0 = 0; c0 < 10; c0++)
						for (int c1 = 0; c1 < 10; c1++)
							if (dp[i][status][m0][m1][c0][c1])
								for (int dig = 0; dig < 10; dig++){
									int hi = dig * a + c0, lo = dig*b + c1;
									int newStatus;
									if (dig == dv[mx][i]-'0')
										newStatus = status;
									else if (dig < dv[mx][i] - '0')
										newStatus = 0;
									else
										newStatus = 1;
									int nm0 = m0 | (mp[0][mod10[hi]] != -1? 1<<mp[0][mod10[hi]]: 0);
									int nm1 = m1 | (mp[1][mod10[lo]] != -1? 1<<mp[1][mod10[lo]]: 0);
									add(dp[i+1][newStatus][nm0][nm1][r10[hi]][r10[lo]], dp[i][status][m0][m1][c0][c1]);
								}

	int ret = 0;
	for (int m0 = 0; m0 < 1<<sz[0]; m0++)
		for (int m1 = 0; m1 < 1<<sz[1]; m1++) {
			bool good = false;
			for (int i = 0; i < vec[0].size(); i++)
				good |= (m0>>mp[0][vec[0][i]]&1) && (m1>>mp[1][vec[1][i]]&1);
			if (good)
				add(ret, dp[(int)dv[mx].size()][0][m0][m1][0][0]);
		}
	return ret;
}

void solve() {
	for (int i = 0; i < 100; i++)
		mod10[i] = i % 10, r10[i] = i/ 10;
	cin >> s; n = s.size();
	for (int i = 1; i < 10; i++) {
		int cur = 0, pt = 0;
		while (pt < s.size() || cur >= i){
			if (cur >= i) {
				dv[i] += char('0' + cur/ i);
				cur %= i;
			}
			else {
				cur = cur * 10 + int(s[pt++] - '0');
				if (cur < i)
					dv[i] += "0";
			}
		}
		dv[i] = "0" + dv[i];
		reverse(dv[i].begin(), dv[i].end());
	}


	for (int i = 0; i < n; i++)
		ans = (10ll*ans + int(s[i] - '0')) % MOD;

	for (int i = 1; i < 10; i++)
		for (int j = 1; j < 10; j++)
			if (i!=j && __gcd(i, j) == 1)
				add(ans, get(i, j));

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