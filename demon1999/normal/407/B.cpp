#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < n; i++)
#define sz(a) int(a.size())
#define mp(a, b) make_pair(a, b)
#define re return
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll mod = 1000000007;
const int ma = 131072;
ll n, m, dp[2 * ma], pr[2 * ma];  

int main() {
    cin >> n;
    forn (i, n) {
        cin >> pr[i];
	pr[i]--;
    }
    ll ans = 1;
    dp[0] = 1;
    for (ll i = 1; i < n; i++) {
    	dp[i] = 1;
	for (int j = pr[i]; j < i; j++)
	   dp[i] += dp[j] + 1LL;
	dp[i] %= mod;
	ans += dp[i];
//	cout << dp[i] << " ";
    }
    cout << (ans + n) % mod;
    return 0;	
}