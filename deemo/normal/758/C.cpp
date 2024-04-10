#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100 + 4;

ll n, m, k, x, y;

ll get(ll a, ll b, ll k){
	if (n == 1)
		return k/m + int(k%m>=b+1);

	if (a == 0){
		if (b+1 > k)	return 0;
		ll ret = 1;
		k -= m;
		if (k > 0){
			ret += k/((n-1<<1) * m);
			k %= ((n-1<<1) * m);
			if (k- ((n-1<<1)-1) * m >= b+1)
				ret++;
		}
		return ret;
	}
	else if (a == n-1){
		return get(0, b, k-m*(n-1));
	}
	else{
		k -= m;
		ll ret = 0;
		if (k > 0){
			ll temp = k/((n-1)*m);
			ret = temp;
			k %= (n-1)*m;
			if (temp & 1)
				a = n-1-a;

			if (m*(a-1)+b+1 <= k)
				ret++;
		}
		return ret;
	}
}

int main(){
	cin >> n >> m >> k >> x >> y, x--, y--;

	ll ansmax = -1;
	ll ansmin = 2e18;
	ll ansg = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			ll ret = get(i, j, k);

			ansmax = max(ansmax, ret);
			ansmin = min(ansmin, ret);
			if (i == x && j == y)
				ansg = ret;
		}

	cout << ansmax << " " << ansmin << " " << ansg << "\n";
	return 0;
}