#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, k;	cin >> n >> k;
	k = k+1>>1;
	while (k--){
		if (n == 1) break;
		ll cur = 1;
		for (ll i = 2; i * i <= n; i++)
			if (n % i == 0){
				ll ret = i-1;
				n /= i;
				while (n % i == 0)
					n /= i, ret *= i;
				cur *= ret;
			}
		if (n > 1)
			cur *= n-1;
		n = cur;
	}
	cout << n%MOD << "\n";
	return 0;
}