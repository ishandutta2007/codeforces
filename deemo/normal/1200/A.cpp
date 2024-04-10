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

int q;
string s;

void solve() {
	cin >> q >> s;
	int mask = 0;
	for (int i = 0; i < q; i++){
		if (s[i] == 'L') {
			for (int j = 0; j < 10; j++)
				if (!(mask>>j&1)) {
					mask |= 1<<j;
					break;
				}
		}
		else if (s[i] == 'R'){
			for (int j = 9; ~j; j--)
				if (!(mask>>j&1)) {
					mask |= 1<<j;
					break;
				}
		}
		else{
			int t = s[i]-'0';
			mask ^= 1<<t;
		}
	}
	for (int i = 0; i < 10; i++)
		cout << (mask>>i&1);
	cout << endl;
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