#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int N = 1e6 + 87;
const int M = 1000000007;

int f[N];

bool ok(string s, int a, int b) {
	for(int i=0;i<s.size();i++)
		if(s[i] != '0'+a && s[i] != '0'+b)
			return false;
	return true;
}

int pw(int n, int k) {
	if(k == 0) return 1;
	int t = pw(n, k/2);
	if(k & 1) 
		return 1LL * t * t % M * n % M;
	return 1LL * t * t % M;
}

int C(int n, int m) {
	int a = f[n], b = 1LL * f[m] * f[n-m] % M;
	return 1LL * a * pw(b, M-2) % M;
}

int main()
{
	IO_OP;
	f[0] = 1;
	for(int i=1;i<N;i++)
		f[i] = 1LL * f[i-1] * i % M;
	int a, b, n;
	ll ans = 0;
	cin >> a >> b >> n;
	for(int i=0;i<=n;i++) {
		int j = n - i, s = a * i + b * j;
		if(ok(to_string(s), a, b))
			ans = (ans + C(n, i)) % M;
	}
	cout << ans << endl;
}