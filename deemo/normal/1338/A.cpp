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

ll n, a[MAXN], b[MAXN];

bool check(int mid) {
	ll cur = 1ll<<mid; cur--;
	b[n-1] = a[n-1] + cur;
	for (int i = n-2; ~i; i--) {
		ll dif = b[i+1] - a[i];
		if (dif < 0) return false;
		b[i] = min(a[i] + cur, b[i+1]);
	}
	return true;
}

void solve() {
	cin >> n;
	bool fl = 0;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i + 1 < n; i++)
		fl |= a[i+1] < a[i];
	if (!fl){
		cout << "0\n";
		return;
	}

	int lo = 0, hi = 33;
	while (hi-lo>1) {
		int mid = hi+lo>>1;
		if (check(mid))
			hi = mid;
		else
			lo = mid;
	}
	cout << hi << "\n";
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