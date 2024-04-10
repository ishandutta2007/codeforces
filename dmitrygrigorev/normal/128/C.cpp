#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

int C[2007][2007];

int solve(int n, int k) {

	int ans = 0;

	for (int a = k; a < n; ++a) {
		for (int b = k; a+b < n; ++b) {
			ans += (((ll) C[a-1][k-1] * C[b-1][k-1]) % mod);
			if (ans >= mod) ans -= mod;
		} 
	}

	return ans;

}

int main(){
#ifdef LOCAL
	freopen("N_input.txt", "r", stdin);
	//freopen("N_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 2007; ++i) {
		C[i][0] = 1;
		C[i][i] = 1;
		for (int j  = 1; j < i; ++j) {
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
		}
	}

	int n, m, k;
	cin >> n >> m >> k;

	int a = solve(n, k), b = solve(m, k);
	cout << (((ll) a * b) % mod);

}