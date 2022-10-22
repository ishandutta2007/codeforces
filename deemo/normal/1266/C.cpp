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

int n, m, a[MAXN][MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	cin >> n >> m;
	if (n+m == 2)
		cout << "0\n";
	else{
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (m > 1)
					a[i][j] = (j+1+n)*(i+1);
				else
					a[i][j] = i+2;
				cout << a[i][j] << " ";
			}
			cout << "\n";
		}

	}
	return 0;
}