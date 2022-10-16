#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 2003;

pi a[N];
int b[N], c[N], p[N], s[N];

signed main()
{
	IO_OP;
	
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++)
		cin >> a[i].F >> a[i].S, a[i].F--, a[i].S--;
	sort(a, a + m, [&](pi x, pi y) {
		return x.F + x.S < y.F + y.S;		
	});
	auto go = [&](int i, int j) {
		return max(min(j + k - 1, a[i].S) - max(j, a[i].F) + 1, 0);		
	};
	for(int i = 0; i < m; i++) {
		int mx = 0;
		for(int j = 0; j < n - k + 1; j++) {
			b[j] += go(i, j);
			mx = max(mx, b[j]);
		}
		p[i] = mx;
	}
	for(int i = m - 1; i >= 0; i--) {
		int mx = 0;
		for(int j = 0; j < n - k + 1; j++) {
			c[j] += go(i, j);
			mx = max(mx, c[j]);
		}
		s[i] = mx;
	}
	int ans = 0;
	for(int i = 0; i < m; i++) ans = max(ans, p[i] + s[i + 1]);
	cout << ans << endl;
	
}