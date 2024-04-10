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
typedef double ld;
 
const ll mod = int(1e9) + 7, pq = 2, szz = 65536, ma = szz, szz1 = 8;
 
int get_int() {
	int k;
	scanf("%d", &k);
	re k;
}
 
ll dp[200002], sm[200002], a, b, k, t;

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> a >> b >> k >> t;
	dp[100001] = 1;
	for (int i = 1; i < 200002; i++) {
		sm[i] = sm[i - 1] + dp[i];
	}
	//cout << sm[200001] << endl;
	forn (i, t) {
		for (int j = 0; j < 200002; j++) {
			dp[j] = ((sm[min(j + k, 200001LL)] - sm[max(j - k - 1, 0LL)])%mod + mod)%mod;
		}
		for (int j = 1; j < 200002; j++) {
			sm[j] = (sm[j - 1] + dp[j]) % mod;
		}
	}
	ll ans = 0;
	for (int j = 0; j < 200002; j++) {
		ans = ((ans + dp[j] * (sm[max(min(a + j - b - 1, 200001LL), 0LL)])) % mod + mod) % mod;
	}
	cout << ans;
	re 0;
}