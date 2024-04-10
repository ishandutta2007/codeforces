#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll F[303030];
ll n, m, ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll i;
	
	cin >> n >> m;
	
	for(i = 1, F[0] = 1; i <= n; i ++){
		F[i] = F[i - 1] * i % m;
	}
	
	for(i = 1; i <= n; i ++){
		ans = (ans + (n - i + 1) * F[i] % m * F[n - i + 1]) % m;
	}
	
	cout << ans << "\n";
	
	return 0;
}