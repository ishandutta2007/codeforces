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

int a[N], b[N], mx[N], mn[N];

void solve() {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=n;i++)
		cin >> b[i];
	reverse(a+1, a+n+1);
	int x = 0, y = 0;
	for(int i=1;i<=n;i++)
		if(a[i] == 1) x++;
		else y++, a[i] = -1;
	for(int i=1;i<=n;i++)
		if(b[i] == 1) x++;
		else y++, b[i] = -1;
	for(int i=1;i<=n;i++) {
		b[i] += b[i-1];
		mx[i] = max(mx[i-1], b[i]);
		mn[i] = min(mn[i-1], b[i]);
 	}
	int sm = 0, ans = INF;
	for(int i=0;i<=n;i++) {
		sm += a[i];
		int req = x-y-sm;
		int l = 0, r = n;
		while(l <= r) {
			int m = (l + r) / 2;
			if(mn[m] <= req && req <= mx[m])
				r = m - 1;
			else
				l = m + 1;
		}
		if(l <= n && mn[l] <= req && req <= mx[l])
			ans = min(ans, i + l);
	}
	cout<< ans << '\n';	

}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		solve();
	}	
	
}