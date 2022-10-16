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

const int INF = 1e18 + 7, N = 5e5 + 6;

int a[N], s[N];

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	int m = (n + 1) / 2, x;
	for(int i = 0; i < m; i++) cin >> a[i];
	cin >> x;
	for(int i = m; i < n; i++) a[i] = x;
	for(int i = n - 1; i >= 0; i--) s[i] = a[i] + s[i + 1];
	int mn = INF;
	for(int i = 0; i < m; i++) {
		mn -= x;
		mn = min(mn, s[i]);
		if(mn > 0) {
			cout << n - i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	
}