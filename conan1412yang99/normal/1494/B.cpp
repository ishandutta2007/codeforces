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
		int n;
		int a[4];
		cin >> n >> a[0] >> a[1] >> a[2] >> a[3];
		bool ok = true;
		for(int i = 0; i < 4; i++) {
			int l = a[(i + 3) % 4], r = a[(i + 1) % 4], f = a[(i + 2) % 4];
			if(a[i] == 0) {
				if(l == n || r == n) ok = false;
				if(l == n - 1) f--;
				if(r == n - 1) f--;
				if(f < 0) ok = false;
			} else if(a[i] == 1) {
				if(l == n && r == n) {
					ok = false;
					break;
				}
				int can = 1;
				if(l == n) f--, can--;
				if(r == n) f--, can--;
				if(l == n - 1) f--;
				if(r == n - 1) f--;
				assert(can >= 0);
				f += can;				
				if(f < 0) ok = false;
			}
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
	
}