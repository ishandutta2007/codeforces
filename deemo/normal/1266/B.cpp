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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	//
	

	int sm = 21;

	int te;	cin >> te;
	while (te--){
		ll x; cin >> x;
		bool found = false;
		for (int i = 1; !found && i <= 6; i++) {
			ll rem = x - (sm - i);
			if (rem < 0) continue;
			if (rem % 14 == 0) {
				cout << "YES\n";
				found = true;
				break;
			}
		}
		if (!found)
			cout << "NO\n";
	}
	return 0;
}