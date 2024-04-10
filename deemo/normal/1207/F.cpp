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

const int MAXN = 5e5 + 5;
const int SQ = 400;

int a[MAXN], sv[SQ][SQ];

void solve() {
	int q;
	cin >> q;
	while (q--){
		int type, x, y; cin >> type >> x >> y;
		if (type == 1){
			a[x] += y;
			for (int i = 1; i < SQ; i++)
				sv[i][x%i] += y;
		}
		else{
			int ans = 0;
			if (x >= SQ){
				int cur = y;
				while (cur < MAXN)
					ans += a[cur], cur += x;
			}
			else{
				ans = sv[x][y];
			}
			cout << ans << "\n";
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