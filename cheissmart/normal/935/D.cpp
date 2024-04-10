#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int M = 1e9 + 7;

int a[100005], b[100005], inv[100005];

int32_t main()
{
	IO_OP;
	
	inv[1] = 1;
	for(int i=2;i<100005;i++)
		inv[i] = (M - M / i) * inv[M % i] % M;
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<n;i++)
		cin >> b[i];
	ll ans = 0, c = 1;
	for(int i=0;i<n;i++) {
		if(a[i] && b[i]) {
			if(a[i] != b[i]) {
				if(a[i] > b[i]) ans += c;
				break;
			}
		} else if(a[i] == 0 && b[i]) {
			ans += c * (m - b[i]) % M * inv[m] % M;
			c *= inv[m];
			c %= M;
		} else if(a[i] && b[i] == 0) {
			ans += c * (a[i] - 1) % M * inv[m] % M;
			c *= inv[m];
			c %= M;
		} else {
			ans += c * (m - 1) % M * inv[2] % M * inv[m] % M;
			c *= inv[m];
			c %= M;
		}
	}
	cout << ans % M << endl;
}