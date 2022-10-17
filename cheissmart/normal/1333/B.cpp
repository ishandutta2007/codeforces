#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 1e5 + 7;

int a[N], b[N];

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i=0;i<n;i++) cin >> a[i];
		for(int i=0;i<n;i++) cin >> b[i];
		int x = 0, y = 0, z = 0;
		for(int i=0;i<n;i++) {
			if(a[i] == 0) x++;
			else if(a[i] == 1) y++;
			else z++;
		}
		bool ok = 1;
		for(int i=n-1;i>=0;i--) {
			if(a[i] == 0) x--;
			else if(a[i] == 1) y--;
			else z--;
			int d = b[i] - a[i];
			if(d == 0) ok &= 1;
			else if(d > 0) ok &= y > 0;
			else ok &= z > 0;
		}

		cout << (ok ? "YES" : "NO") << endl;
	}

}