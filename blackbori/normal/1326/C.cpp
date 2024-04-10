#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 998244353;

ll P[202020];
ll n, k, ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll p, i;

	cin >> n >> k;

	cout << (n + n - k + 1) * k / 2 << " ";

	ans = 1;
	for(p = 0, i = 1; i <= n; i ++){
		cin >> P[i];
		if(P[i] > n - k){
			if(p != 0){
				ans = ans * (i - p) % mod;
			}
			p = i;
		}
	}

	cout << ans << "\n";
	
	return 0;
}