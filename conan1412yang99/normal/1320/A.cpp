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

int b[N], dp[N];
map<int, int> mx;

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> b[i];	
	int ans = 0;
	for(int i=0;i<n;i++) {
		dp[i] = b[i] + mx[b[i]-i];
		mx[b[i]-i] = max(mx[b[i]-i], dp[i]);
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;

}