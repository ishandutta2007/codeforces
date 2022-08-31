#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 998244353;

// 1 / C(m, m+i)

int bp(int x, int y) {
	if (y==0) return 1;
	if (y==1) return x%mod;
	if (y%2) return ((ll) x * bp(x, y-1)) % mod;

	int t = bp(x, y/2);
	return ((ll) t * t) % mod;

}

const int N = 4000007;

int fact[N];
int rv[N];

int t[N];

int C(int n, int k) {
	int A = fact[n];
	int B = ((ll) rv[n-k] * rv[k]) % mod;
	return ((ll) A*B) % mod;
}


int RC(int n, int k) {
	int A = rv[n];
	int B = ((ll) fact[n-k] * fact[k]) % mod;
	return ((ll) A*B) % mod;
}

int main(){
#ifdef LOCAL
	freopen("M_input.txt", "r", stdin);
	//freopen("M_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	fact[0] = 1, rv[0] = 1;
	fact[1] = 1, rv[1] = 1, t[1] = 1;

	for (int i = 2; i < N; ++i) {
		fact[i] = ((ll) fact[i-1] * i) % mod;
		t[i] = ((ll) (mod - mod / i) * t[mod % i]) % mod;
		rv[i] = ((ll) rv[i-1] * t[i]) % mod;
	}

	int n, m;
	cin >> n >> m;

	int ans = 0;

	for (int i = 1; i <= n; ++i) {
		int var = ((ll) m * t[m+i]) % mod;

		//cout << var << endl;

		//cout << var << endl;
		var = 1-var;
		if (var < 0) var += mod;

		var = bp(var, mod-2);		

		//cout << var << endl;

		var = ((ll) var * C(n, i)) % mod;

		if (i%2 == 0) {
			var = -var;
			if (var < 0) var += mod;
		}

		ans += var;
		if (ans >= mod) ans -= mod; 
	}

	// n! * (m-i)! 
	// (n-i)!

	int kek = 0;
	for (int i = 0; i <= n; ++i) {
		int a = 1;
		a = ((ll) a * fact[n]) % mod;
		a = ((ll) a * fact[n+m-i]) % mod;
		a = ((ll) a * rv[n-i]) % mod;
		a = ((ll) a * rv[n+m]) % mod;

		kek += a;
		if (kek >= mod) kek -= mod;
	}

	cout << ((ll) ans * kek) % mod;



}