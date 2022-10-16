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

int a[200005], o[200005], dp[2019];

int main()
{
	IO_OP;
	
	int n, m, k;
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1, a+n+1);
	for(int i=0;i<m;i++) {
		int x, y;
		cin >> x >> y;
		o[x] = max(o[x], y);
	}
	for(int i=1;i<=k;i++)
		a[i] += a[i-1];
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	for(int i=1;i<=k;i++) {
		for(int j=1;j<=i;j++) {
			dp[i] = min(dp[i], dp[i-j] + a[i] - a[i-j+o[j]]);
		}
	}
	cout << dp[k] << endl;
}