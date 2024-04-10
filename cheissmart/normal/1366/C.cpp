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

const int INF = 1e9 + 7;

int a[33][33];

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		int len = n + m - 2;
		vi d(n+m);
		vi dd(n+m);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				int tt;
				cin >> tt;
				if(i + j < (len + 1) / 2) {
					if(tt) d[i+j]++;
					else dd[i+j]++;
				}
				int x = (n-1-i) + (m-1-j);
				if(x < (len + 1) / 2) {
					if(tt) d[x]++;
					else dd[x]++;
				}
			}
		}
		int ans = 0;
		for(int i=0;i<n+m;i++) ans += min(d[i], dd[i]);
		cout << ans << endl;
	}	
	
}