#include <bits/stdc++.h>


using namespace std;

#define re return
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;
typedef unsigned long long ull;
const ll ma = 128;

int seg2[2 * 128];
int n, k, p, dp[2][500001];
int gm[ma], gm2[ma], ak[ma];
vector<int> a;

void upd(int nu, int c) {
	ak[nu] = c;
	gm[0] = ak[0];
	for (int i = 1; i <= p; i++)
		gm[i] = min(ak[i], gm[i - 1]);
	for (int i = p - 1; i >= 0; i--)
		gm2[i] = min(gm2[i + 1], ak[i]);
}

int main() {
	iostream::sync_with_stdio(0);
	cin >> n >> k >> p;
	//n = get_int(); k = get_int(); p = get_int();
	//n = 500000, k = 100, p = 100;
	//cout << n << " " << k << " " << p << "\n";
	//return 0;
	a.resize(n);
	forn (i, n) {
	//	a[i] = 10;
	//	a[i] = get_int();
		cin >> a[i];
		dp[0][i + 1] = (dp[0][i] + a[i]) % p;
	}
	for (int i = 1; i < k; i++) {				
		forn (i, ma) {
			ak[i] = gm[i] = gm2[i] = int(1e9);
		}
		int sum = 0;
		for (int j = 0; j < i; j++) {
			sum = (sum + a[j]) % p;
		}
		upd(sum, dp[0][i] - sum);
		for (int j = i; j < n; j++) {
			sum = (sum + a[j]) % p;
			dp[1][j + 1] = min(gm[sum] + sum, gm2[sum + 1] + sum + p);
			if (ak[sum] > dp[0][j + 1] - sum) {
				upd(sum, dp[0][j + 1] - sum);
			}
			dp[0][j + 1] = dp[1][j + 1];
			//cout << dp[0][j + 1] << " ";
		}
		//cout << "\n";
	}
	cout << dp[0][n];
}