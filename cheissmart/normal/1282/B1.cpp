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

const int INF = 1e9 + 7, N = 2e5 + 7;

int a[N];

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n, p, k;
		cin >> n >> p >> k;
		for(int i=0;i<n;i++)
			cin >> a[i];
		sort(a, a+n);
		int cur = 0, ans = 0;
		for(int i=1;i<n;i+=2) {
			cur += a[i];
			if(cur <= p)
				ans = max(ans, i+1);
		}
		cur = a[0];
		if(cur <= p) ans = max(ans, 1ll);
		for(int i=2;i<n;i+=2) {
			cur += a[i];
			if(cur <= p)
				ans = max(ans, i+1);
		}
		cout << ans << '\n';
	}	
	
}