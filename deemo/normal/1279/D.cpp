#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int C = 26;//XXX
const int MOD = 998244353 ;

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

const int MAXN = 1e6 + 10;

int n, cnt[MAXN];
vector<int> vec[MAXN];

void solve() {
	cin >> n;
	int sz = 0;
	for (int i = 0; i < n; i++){
		int t; cin >> t;
		vec[i].resize(t);
		for (int j = 0; j < t; j++)
			cin >> vec[i][j], vec[i][j]--, cnt[vec[i][j]]++;
		sz += t;
	}

	int ans = 0;
	int temp2 = pw(n, MOD-2);
	for (int i = 0; i < n; i++) {
		int temp = pw((int)vec[i].size(), MOD-2);
		for (auto x: vec[i])
			ans = (ans + 1ll*temp2*temp%MOD*temp2%MOD*cnt[x])%MOD;
	}
	cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	
	int te = 1;	
	//cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}