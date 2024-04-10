#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int C = 26;//XXX
const int MOD = 998244353;

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

const int MAXN = 4e5 + 10;

int n;
int ss[MAXN], tt[MAXN];
ll k;

int choose(int a, int b){
	if (a < b) return 0;
	return 1ll*ss[a]*tt[b]%MOD*tt[a-b]%MOD;
}

void solve() {
	cin >> n >> k;
	if (k > n-1)
		cout << "0\n";
	else {
		ss[0] = 1;
		for (int i = 1; i < MAXN; i++)
			ss[i] = 1ll*i*ss[i-1]%MOD;
		tt[0] = 1;
		for (int i = 1; i < MAXN; i++)
			tt[i] = pw(ss[i], MOD-2);
		if (k == 0)
			cout << ss[n] << "\n";
		else {
			int temp = pw(n-k, n);
			for (int t = 1; t <= n-k; t++) {
				int temp2 = 1ll*choose(n-k, t) * pw(n-k-t, n) % MOD;
				if (t&1)
					add(temp, -temp2);
				else
					add(temp, temp2);
			}
			int ans = 1ll*choose(n, k)*temp % MOD;
			
			cout << ans*2%MOD << "\n";
		}
	}
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