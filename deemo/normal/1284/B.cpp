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

int n, mn[MAXN], mx[MAXN];
vector<int> vec[MAXN];

int sec[MAXN], sz;
void solve() {
	cin >> n;
	ll ans = 0;
	for (int i= 0; i < n; i++){
		int t; cin >> t;
		vec[i].resize(t);
		mx[i] = -1, mn[i] = 1e9;
		bool fl = false;
		for (int j = 0; j < t; j++) {
			cin >> vec[i][j];
			mx[i] = max(mx[i], vec[i][j]);
			if (vec[i][j] > mn[i])
				fl = true;
			mn[i] = min(mn[i], vec[i][j]);
		}
		if (fl){
			mx[i] = 1e9;
			ans += n;
		}
		else
			sec[sz++] = mn[i];
	}
	sort(mx, mx + n);
	for (int i = 0; i < sz; i++) {
		ans += (mx+n) - lower_bound(mx, mx + n, sec[i]+1);
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