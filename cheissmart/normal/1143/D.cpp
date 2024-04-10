#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int main()
{
	IO_OP;
	int n, k, a, b;
	cin >> n >> k >> a >> b;
	vector<int> v({0});
	for(int i = 1; i <= k; i++) 
		if(k % i == 0)
			v.PB(i);
	ll mn = 1ll * n * k, mx = 0;
	for(int e : v) {
		for(int i = 0; i < n; i++) {
			for(int d0: {-1, 1}) {
				for(int d1: {-1, 1}) {
					ll l = d0 * a + d1 * b + 1ll * i * k + e;
					if(l < 0)
						l *= -1;
					if((l - d0 * a - d1 * b) % k)
						continue;
					ll g = __gcd(1ll * n * k, l);
					ll t = 1ll * n * k / g;
					mn = min(mn, t);
					mx = max(mx, t);
				}
			}
		}
	}
	cout << mn << " " << mx << endl;
	
}