#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;

int n, m, d[2], _d[2], ar[2][MAXN];

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

int equalChance(int a, int b){
	if (a && b)
		return a == b;
	return pw(m, MOD-2);
}

int greaterChance(int a, int b){
	if (a && b)
		return int(a > b);
	if (a)
		return 1ll*(a-1)*pw(m, MOD-2)%MOD;
	if (b)
		return 1ll*(m - b)*pw(m, MOD-2)%MOD;
	return 1ll*(m-1)*pw(2*m, MOD-2)%MOD;
}

int main(){
	cin >> n >> m;
	d[0] = 1;
	for (int w = 0; w < 2; w++)
		for (int i = 0; i < n; i++)
			cin >> ar[w][i];

	for (int i = 0; i < n; i++){
		int a = ar[0][i], b = ar[1][i];

		memset(_d, 0, sizeof(_d));
		//0
		_d[0] = 1ll*d[0]*equalChance(a, b)%MOD;

		//1
		_d[1] = (d[1] + 1ll*d[0]*greaterChance(a, b))%MOD;
		memcpy(d, _d, sizeof(d));
	}

	cout << d[1] << "\n";
	return 0;
}