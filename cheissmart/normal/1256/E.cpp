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

int dp[200005], lst[200005], ans[200005];
pi a[200005];

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> a[i].F;
		a[i].S = i;
	}
	sort(a+1, a+n+1);
	memset(dp, 0x3f, sizeof dp);
	dp[0] = -a[1].F;
	int mn = dp[0], l = 0;
	for(int i=3;i<=n;i++) {
		dp[i] = a[i].F + mn;
		lst[i] = l;
		if(i-2 >= 3) {
			if(dp[i-2] - a[i-1].F < mn) {
				mn = dp[i-2] - a[i-1].F;
				l = i-2;
			}
		}
	}
	int k = 0;
	l = n;
	while(l) {
		++k;
		for(int i=lst[l]+1;i<=l;i++) ans[a[i].S] = k;
		l = lst[l];
	}
	cout << dp[n] << " " << k << endl;
	for(int i=1;i<=n;i++) cout << ans[i] << " ";
}