#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 1e5 + 7, M = 998244353;

int freq[N], dp[N];

int qpow(int a, ll b) {
	if(b == 0) return 1;
	ll t = qpow(a, b / 2);
	t = t * t % M;
	if(b & 1) return t * a % M;
	else return t;
}

signed main()
{
	IO_OP;
	
	int m;
	cin >> m;
	for(int i = 0; i < m; i++) {
		int a, f;
		cin >> a >> f;
		freq[a] = f;
	}
	for(int i = 1e5; i >= 1; i--) {
		int sum = 0, sum_sq = 0;
		ll k = 0;
		for(int j = i; j <= 1e5; j += i) if(freq[j]) {
			k += freq[j];
			sum_sq = (sum_sq + (ll) j * j % M * freq[j] % M) % M;
			sum = (sum + (ll) j * freq[j] % M) % M;
		}
		int cross = ((ll) sum * sum % M - sum_sq + M) % M;
		if(k >= 2) dp[i] = (dp[i] + (ll) sum_sq * qpow(2, k - 2) % M * ((k - 1) % M) % M) % M;
		if(k >= 3) dp[i] = (dp[i] + (ll) cross * qpow(2, k - 3) % M * ((k - 2) % M) % M) % M;
		if(k >= 2) dp[i] = (dp[i] + (ll) cross * qpow(2, k - 2) % M) % M;
		for(int j = i * 2; j <= 1e5; j += i) dp[i] = (dp[i] - dp[j] + M) % M;
	}
	cout << dp[1] << endl;

}