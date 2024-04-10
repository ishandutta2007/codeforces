#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 300007;

int n, mod;

int fact[N];

main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> mod;

	fact[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = ((ll) fact[i-1] * i) % mod;
	}


	int ans = 0;


	for (int len = 1; len < n; ++len) {
		int cnt = n - len + 1;
		cnt = ((ll) cnt * fact[len]) % mod;
		cnt = ((ll) cnt * fact[n-len]) % mod;
		int good = n - len + 1;
		cnt = ((ll) cnt * good) % mod;
		ans = (ans+cnt)%mod;
	}

	ans = (ans + fact[n]) % mod;
	cout << ans;



	

}