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
	int te;	cin >> te;
	while (te--){
		string s; cin >> s;
		int sm = 0;
		int c0 = 0, c2 = 0;
		for (char c: s) {
			sm += int(c - '0');
			if (c == '0')
				c0++;
			if (int(c - '0')%2 == 0)
				c2++;
		}
		if (sm%3 == 0 && c0 > 0 && c2 >= 2)
			cout << "red\n";
		else
			cout << "cyan\n";
	}
	return 0;
}