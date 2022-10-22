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

const int MAXN = 11;

int a[MAXN][MAXN];
ld d[MAXN * MAXN];

int conv(int r, int c){
	return r*10 + (r&1? 9-c: c); 
}

pii convBack(int x){
	int r = x/ 10;
	x -= r*10;
	int c = r&1? 9-x: x;
	return {r, c};
}

void solve() {
	d[0] = 0;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			cin >> a[i][j];

	for (int i = 1; i < 10*10; i++){
		pii v = convBack(i);
		int rem = 6;
		ld sm = 0;
		for (int j = 1; j <= 6; j++)
			if (i - j >= 0){
				ld temp = d[i-j];
				pii u = convBack(i-j);
				if (a[u.F][u.S])
					temp = min(temp, d[conv(u.F-a[u.F][u.S], u.S)]);
				sm += 1.l/6 * temp;
				rem--;
			}
		d[i] = (sm+1)/ (1.L - ld(rem)/ 6);
	}
	cout << fixed << setprecision(12);
	cout << d[99] << "\n";
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