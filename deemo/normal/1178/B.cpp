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
/*
void plant(int v, int b, int e){
	if (e - b == 1){

		return;
	}

	int mid = b + e >> 1;
	plant(v<<1, b, mid);
}*/

const int MAXN = 1e6 + 10;

int n;
string s;

void solve() {
	cin >> s;
	n = s.size();
	ll ans = 0, cW = 0, cO = 0;
	for (int l = 0; l < n;){
		if (s[l] == 'o'){
			l++;
			cO += cW;
			continue;
		}

		int r = l;
		while (r < n && s[r] == 'v') r++;

		ll temp = r-l-1;
		ans += temp*cO;
		cW += temp;

		l = r;
	}
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