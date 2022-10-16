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
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int a[100005], b[100005];

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n, s;
		cin >> n >> s;
		for(int i=1;i<=n;i++) {
			cin >> a[i];
			b[i] = a[i];
			b[i] += b[i-1];
		}
		int mx, ans = 0;
		mx = upper_bound(b+1, b+n+1, s) - b - 1;
		for(int i=1;i<=n;i++) {
			int ss = s + a[i];
			int c = upper_bound(b+i+1, b+n+1, ss) - b;
			if(c == i+1) continue;
			c-=2;
			if(c > mx) {
				mx = c;
				ans = i;
			}
		}
		cout << ans << endl;
	}
	
}