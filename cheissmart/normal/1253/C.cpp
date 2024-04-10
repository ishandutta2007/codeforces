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

int a[N], b[N], dp[N];

signed main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> a[i];
	sort(a, a+n);
	b[0] = a[0];
	for(int i=1;i<n;i++) b[i] = a[i] + b[i-1];
	for(int i=0;i<m;i++)
		dp[i] = b[i];
	for(int i=m;i<n;i++)
		dp[i] = b[i] + dp[i-m];
	for(int i=0;i<n;i++) cout << dp[i] << " ";
}