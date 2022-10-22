#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

ll f[500];

int main(){
	ll x, y, n;	cin >> x >> y >> n;
	f[0] = x;
	f[1] = y;
	n--;
	n %= 6;
	for (int i = 2; i < 100; i++)
		f[i] = f[i - 1] - f[i - 2];
	cout << (f[n] + MOD * 3) % MOD << endl;
	return	0;	
}