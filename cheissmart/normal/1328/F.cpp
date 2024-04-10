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

const int INF = 1e18 + 7, N = 2e5 + 7;

int a[N], psum[N];

signed main()
{
	IO_OP;
	
	int n, k;
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a + 1, a+n+1);
	for(int i=1;i<=n;i++) psum[i] = psum[i-1] + a[i];
	int ans = INF;
	for(int i=1;i<=n;)  {
		int j = i;
		while(i <= n && a[i] == a[j]) i++;
		int c = i - j, cl = (a[j]-1) * (j - 1) - psum[j-1], cr = psum[n] - psum[i - 1] - (a[j] + 1) * (n - i + 1);
		if(c >= k) ans = min(ans, 0LL);
		else {
			if(c+j-1 >= k) ans = min(ans, cl + k - c);
			if(c+(n-i+1) >= k) ans = min(ans, cr + k - c);
			ans = min(ans, cl + cr + k - c);
		}
	}
	cout << ans << endl;

}