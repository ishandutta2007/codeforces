#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e7;

ll pw(ll a, ll b){
	ll ret = 1;
	while (b){
		if (b & 1)
			ret = ret * a % MOD;
		b >>= 1;
		a = a * a % MOD;
	}
	return ret;
}

int main(){
	int n;	cin >> n;
	ll ret = pw(1378, n);
	cout << ret%10 << endl;
	return 0;
}