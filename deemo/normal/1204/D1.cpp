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

const int MAXN = 1e5 + 10;

int n;
string s;
pair<int, char> sec[MAXN]; int sz;
int dp[MAXN][2];

void solve() {
	cin >> s; n = s.size();
	string t;
	for (int l = 0; l < n;){
		int r = l;

		while (r < n && s[l] == s[r]) r++;

		sec[sz++] = {r-l, s[l]};

		l = r;
	}

	int c1 = 0;

	for (int i = sz-1; ~i; i--) {
		if (sec[i].S == '1')
			c1 += sec[i].F;
		dp[i][1] = c1;
		dp[i][0] = max(dp[i][1], (sec[i].S == '0'? sec[i].F: 0) + max(dp[i+1][0], dp[i+1][1]));

		if (sec[i].S == '0'){
			for (int j = 0; j < sec[i].F; j++)
				t += "0";
		}
		else{
			int cur = 0;
			while (cur + 1 <= sec[i].F && dp[i][0] >= cur + 1 + dp[i+1][0]) cur++;
			int rem = sec[i].F - cur;
			while (rem--) t += "1";
			while (cur--) t += "0";
		}
	}
	//cout << dp[sz-1][0] << endl;
	//cout << dp[0][0] << "  " << dp[0][1] << endl;
	reverse(t.begin(), t.end());

	cout << t << "\n";
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