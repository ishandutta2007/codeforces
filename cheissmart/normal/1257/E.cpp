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

const int INF = 1e9 + 7, N=2e5 + 87;

int a[N], b[N], c[N], mn[N];

signed main()
{
	IO_OP;
	
	int n1, n2, n3, n;
	cin >> n1 >> n2 >> n3;
	n = n1 + n2 + n3;
	for(int i=1,t;i<=n1;i++) cin >> t, a[t]++;
	for(int i=1,t;i<=n2;i++) cin >> t, b[t]++;
	for(int i=1,t;i<=n3;i++) cin >> t, c[t]++;
	for(int i=1;i<=n;i++) a[i] += a[i-1], b[i] += b[i-1], c[i] += c[i-1];
	for(int i=0;i<=n;i++) mn[i] = b[i] + a[n] - a[i];
	for(int i=1;i<=n;i++) mn[i] = min(mn[i], mn[i-1]);
	int ans = INF;
	for(int i=n;i>=0;i--) {
		int cans = b[n] - b[i] + a[n] - a[i];
		cans += mn[i] - (a[n] - a[i]) + c[i];
		ans = min(ans, cans);
	}
	cout << ans << endl;
}