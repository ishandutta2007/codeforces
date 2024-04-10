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

const int INF = 1e9 + 7;

int a[55];

signed main()
{
	IO_OP;
	
	int n, h, m;
	cin >> n >> h >> m;
	for(int i=1;i<=n;i++)a[i] = h;
	for(int i=0;i<m;i++) {
		int l, r, x;
		cin >> l >> r >> x;
		for(int j=l;j<=r;j++) a[j] = min(a[j], x);
	}
	int ans = 0;
	for(int i=1;i<=n;i++) ans += a[i] * a[i];
	cout << ans << endl;
	
}