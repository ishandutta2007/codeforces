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

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		V<pair<ll, ll>> v;
		for(ll i = 2; i * i <= n; i++) {
			if(n % i == 0) {
				int cnt = 0;
				while(n % i == 0) n /= i, cnt++;
				v.EB(cnt, i);
			}
		}
		if(n != 1) v.EB(1, n);
		sort(ALL(v));
		int k = v.back().F;
		V<ll> a(k, 1);
		for(auto p:v) {
			for(int i = 0; i < p.F; i++)
				a[k - i - 1] *= p.S;
		}
		cout << k << endl;
		for(int i = 0; i < k; i++) cout << a[i] << " ";
		cout << endl;
	}
	
}