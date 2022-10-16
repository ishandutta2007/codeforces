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

const int INF = 1e9 + 7, N = 2e5 + 7;

int dp1[N], dp2[N], a[N];

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	int mx = 1;
	dp1[1] = 1;
	for(int i=2;i<=n;i++) {
		if(a[i] > a[i-1]) dp1[i] = dp1[i-1] + 1;
		else dp1[i] = 1;
		mx = max(mx, dp1[i]);
	}
	dp2[n] = 1;
	for(int i=n-1;i>=1;i--) {
		if(a[i] < a[i+1]) dp2[i] = dp2[i+1] + 1;
		else dp2[i] = 1;
	}
	for(int i=2;i<n;i++) {
		if(a[i-1] < a[i+1]) {
			mx = max(mx, dp1[i-1] + dp2[i+1]);
		}
	}
	cout << mx << endl;
}