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

const int MAXN = 100 + 10;

int n;
ll x, a[MAXN], b[MAXN];

void solve() {
	cin >> n >> x;
	ll mxDif = -1e18, mx = -1e18;
	for (int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
		mxDif = max(mxDif, a[i] - b[i]);
		mx = max(mx, a[i]);
	}
	if (mx >= x)
		cout << "1\n";
	else {
		if (mxDif <= 0)
			cout << "-1\n";
		else{
			x -= mx;
			cout << 1 + (x+(mxDif-1))/ mxDif << "\n";
		}
	}
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