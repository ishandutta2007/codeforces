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

int a[N * 2], pd[N * 2], ph[N * 2];

signed main()
{
	IO_OP;
	
	int n, x;
	cin >> n >> x;
	for(int i = 1; i <= n; i++) cin >> a[i], a[n+i] = a[i];
	for(int i = 1; i <= 2 * n; i++) {
		pd[i] = pd[i-1] + a[i];
		ph[i] = ph[i-1] + a[i] * (a[i] + 1) / 2;
	}
	int ans = 0;
	for(int i = n + 1, j = 1; i <= n * 2; i++) {
		while(pd[i] - pd[j - 1] >= x) j++;
		int left = x - (pd[i] - pd[j - 1]);
		int cur = ph[i] - ph[j - 1];
		int r = a[j - 1], l = r - left + 1;
		cur += (l + r) * left / 2;
		ans = max(ans, cur);
 	}
	cout << ans << endl;

}