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

map<int, int> last;

int a[N], dp[N], from[N];

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) {
		dp[i] = 1 + dp[last[a[i]-1]];
		from[i] = last[a[i]-1];
		last[a[i]] = i;
	}
	int pos = max_element(dp+1, dp+n+1)	- dp;
	cout << dp[pos] << endl;
	vi v;
	while(pos) {
		v.PB(pos);
		pos = from[pos];
	}
	reverse(ALL(v));
	for(int e:v) cout << e << " ";
	cout << endl;
	
}