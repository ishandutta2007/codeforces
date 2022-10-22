#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 998244353;
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

int n, a[MAXN], cnt[12];

int countDig(int x){
	int ret = 0;
	while (x){
		ret++;
		x /= 10;
	}
	return ret;
}

int getSum(int x, int t){
	int ret = 0, cur = 1;
	while (x){
		ret = (ret + 1ll*cur*(x%10)) % MOD;
		cur = 10ll*cur%MOD;
		if (t){
			t--;
			cur = 10ll*cur%MOD;
		}
		x /= 10;
	}
	return ret;
}

int get(int x){
	int ret = 0;
	for (int t = 1; t <= 10; t++) { 
		add(ret, 1ll*getSum(x, t)*cnt[t] % MOD);
		if (t)
			add(ret, 10ll*getSum(x, t-1)*cnt[t] % MOD);
	}
	return ret;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		cnt[countDig(a[i])]++;
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
		add(ans, get(a[i]));
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