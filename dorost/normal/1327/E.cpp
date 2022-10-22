#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first 
#define S second
#define int long long 
const int maxn = 3 * 1000 * 100;
const int mod = 998244353;

int tav10[maxn] = {1,1,1,1};

int tav(int n){
	if (n < 0)
		return 0ll;
	return tav10[n];
}

int32_t main(){
	 ios::sync_with_stdio(false);
	 cin.tie(0);
	 cout.tie(0);
	 for (int i = 1; i < maxn; i++){
		 tav10[i] = (tav10[i - 1] * 10 % mod);
	 }
	 int n;
	 cin >> n;
	 for (int i = 1; i < n; i++){
		 cout << ((180 * tav(n - i - 1) % mod) + (810 * tav(n - i - 2) * (n - 2 - i + 1) % mod)) % mod << ' ';
	 }
	 cout << 10 << ' ';
}