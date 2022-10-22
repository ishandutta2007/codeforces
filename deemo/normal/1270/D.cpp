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

const int MAXN = 500 + 10;

int n, k;

pii query(int l, int r, int ex = -1){
	cout << "? ";
	for (int i = l; i <= r; i++)
		if (i != ex)
			cout << i << " ";
	cout << endl;
	pii p; cin >> p.F >> p.S;
	return p;
}

vector<int> vec[3];

void solve() {
	cin >> n >> k;
	if (k == 1){
		cout << "! 1" << endl;
		return;
	}
	pii p = query(1, k);
	int mVal = p.S, mPos = p.F;
	int mask = 0;
	for (int i = 1; i <= k; i++)
		if (i != mPos){
			auto y = query(1, k+1, i);
			if (y.F == mPos){
				vec[2].push_back(i);
			}
			else if (y.S < mVal){
				vec[1].push_back(i);
				mask |= 1;
			}
			else{
				vec[0].push_back(i);
				mask |= 2;
			}
		}
	if (mask == 2)
		cout << "! " << (int)vec[0].size()+1 << endl;
	else if (mask == 1)
		cout << "! " << (int)vec[0].size() + (int)vec[2].size() + 1 << endl;
	else {
		auto y = query(1, k+1, mPos);
		cout << "! " << (y.S > mVal? 1: k) << endl;
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