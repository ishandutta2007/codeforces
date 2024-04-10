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

const int MAXN = 1e3 + 10;

int n, x[MAXN], y[MAXN];
vector<int> vec;
ll dd[MAXN];

bool go(int cur){
	for (int i = 0; i < n; i++)
		if (dd[i] % cur == 0)
			vec.push_back(i);
	if (vec.size() == 0 || vec.size() == n){
		vec.clear();
		return false;
	}
	return true;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	for (int i = 0; i < n; i++)
		dd[i] = 1ll*(x[i]-x[0])*(x[i]-x[0]) + 1ll*(y[i]-y[0])*(y[i]-y[0]);

	ll cur = 2;
	while (!go(cur)) cur <<= 1;

	cout << vec.size() << "\n";
	for (auto x: vec)
		cout << x +1<< " ";
	cout << "\n";
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