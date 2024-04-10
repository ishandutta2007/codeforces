#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 1e9 + 7;//XXX

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

const int C = 60;
const ll MAXN = 1e16;

ll go(int dig, ll rem) {
	if (dig == 0) 
		return 0;

	ll each = 1ll<<dig-2, res = 0;
	switch (rem/each) {
		case 0:
			res = 0;
			break;
		case 1:
			res = 2;
			break;
		case 2:
			res = 3;
			break;
		case 3:
			res = 1;
			break;
	}
	res <<= dig-2;
	res += go(dig-2, rem % each);

	return res;
}

vector<ll> get(ll t) {
	vector<ll> res;

	int dig = 1;
	while (true) {
		if (1ll<<dig-1 >= t) break;
		t -= 1ll<<dig-1;
		dig += 2;
	}
	res.push_back((1ll<<dig-1) + t - 1);

	res.push_back((1ll<<dig) + go(dig-1, t - 1));
	
	res.push_back(res[0] ^ res[1]);
	return res;
}

void solve() {
	ll n; cin >> n;
	vector<ll> ans = get((n+2)/3);
	cout << ans[(n-1)%3] << "\n";
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